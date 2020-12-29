// Author: Rachael Judy
// Date: 2/16/2020
// Purpose: Following a two-pass assembly process, the program takes an assembly
//			file and converts to machine code to be entered in the RAM for the
//			mano machine. The files generated are a symbol table and a bin file.
//			The assembly file must be in the same folder as the executable
//
// 

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <math.h> // pow
#include <cstdlib>
#include <vector> // for command parallel command vectors
#include <cstdio>

using namespace std;

// converts a hexadecimal number in a string to its decimal equivalent
int convertHexToDec(string hexVal) {
	int decVal = 0;
	int digit;

	// loops through each character in string
	for (int i = 0; i < hexVal.length(); i++) {
		char curr = hexVal.at(i);
		switch (curr) {
		case 'A':
			digit = 10;
			break;
		case 'B':
			digit = 11;
			break;
		case 'C':
			digit = 12;
			break;
		case 'D':
			digit = 13;
			break;
		case 'E':
			digit = 14;
			break;
		case 'F':
			digit = 15;
			break;
		default:
			digit = atoi(&curr);
			break;
		}

		decVal += (digit * pow(16, hexVal.length() - 1 - i));
	}
	return decVal;
}

int main() {
	// get user input of filename for reading
	cout << "Rachael Judy - Mano Machine Assembler" << endl;
	cout << "-------------------------------------" << endl;
	cout << "When a valid filename with extension .asm is entered, the symbol table "
		<< "and bin files will be generated." << endl;
	string filename;
	cout << "Enter the .asm: filename: ";
	cin >> filename;

	ifstream inFile;
	inFile.open(filename);

	// checks that file exists and opens
	if (inFile.good()) {
		// create symbol output file
		ofstream symFile;
		symFile.open(filename.substr(0, filename.length() - 4) + ".sym");

		// pass 1 - create symbol table
		map<string, int> symbol;
		int counter = 0;
		string inputLine;

		// read each line of the file and parse command
		while (!inFile.eof()) {			
			getline(inFile, inputLine);
			inputLine.resize(75,' '); // prevents errors with substr

			// checks for location to start if not 0
			if (inputLine.substr(5, 3) == "ORG") {
				counter = convertHexToDec(inputLine.substr(9, 3)); 
			}
			// collects labels
			else {
				// adds label and address to symbol map and symbol table
				if (inputLine.at(3) == ',') {
					symbol.emplace(inputLine.substr(0, 3), counter);
					symFile << inputLine.substr(0, 3) << ": \t" << hex << counter 
						<< "\t" << inputLine.substr(16) << endl; // includes comment about usage
				}
				counter++;
			}
		}
		symFile.close();

		// create bin file
		ofstream binFile;
		binFile.open(filename.substr(0, filename.length() - 4) + ".bin");

		// start pass 2
		// parallel arrays for converting commands
		vector<string> commands = {
			"AND", "ADD", "LDA", "STA", "BUN", "BSA", "ISZ",
			"CLA", "CLE", "CMA", "CME", "CIR", "CIL", "INC",
			"SPA", "SNA", "SZA", "SZE", "HLT",
			"INP", "OUT", "SKI", "SKO", "ION", "IOF",
		};
		vector<string> hexCode = {
			"0000", "1000", "2000", "3000", "4000", "5000", "6000",
			"7800", "7400", "7200", "7100", "7080", "7040", "7020",
			"7010", "7008", "7004", "7002", "7001",
			"F800", "F400", "F200", "F100", "F080", "F040"
		};
		
		// reset counter
		counter = 0;

		// go back to beginning of input file
		inFile.clear();
		inFile.seekg(0, inFile.beg);

		// loop through input file lines
		while (!inFile.eof()) {
			// get line, collects three letter command from line
			getline(inFile, inputLine);
			inputLine.resize(75, ' ');
			string command = inputLine.substr(5, 3);
			int commandIndex = -1;

			// checks that spaces occur in required spots; otherwise skips command
			if (inputLine.at(4) != ' ' || inputLine.at(8) != ' ' || inputLine.at(12) != ' ') {
				cout << "Command to be written at address " << hex << counter 
					<< " is invalid and will be skipped." << endl;
				counter++;
				continue;
			}

			// loop through commands available, searching for match to extracted command
			for (int i = 0; i < commands.size(); i++) {
				if (command == commands[i])
					commandIndex = i;
			}

			string value = inputLine.substr(9, 3); // address or operand
			string comment = inputLine.substr(16);
			// sets counter to location if needed
			if (command == "ORG") {
				if (counter == 0 && value != "000") 
					// inputs a branching command if nonzero program origin to jump to program
					binFile << counter << ": " << "\t4" << value << "\t" << comment << endl;
				counter = convertHexToDec(value);
			}
			else {
				// check for values connected to labels, convert and write
				if (command == "DEC") {
					int address = stoi(value);
					if (symbol.count(inputLine.substr(0, 3)))
						binFile << hex << symbol.at(inputLine.substr(0, 3)) << ": \t" 
						<< hex << (address & convertHexToDec("FFFF")) << "\t" << comment << endl;
					else
						binFile << hex << counter << ": \t" << hex << (address & convertHexToDec("FFFF")) 
						<< "\t" << comment << endl;

					counter++;
				}
				else if (command == "HEX") {
					// checks if value is first value to be input
					if (symbol.count(inputLine.substr(0, 3))) {
						binFile << hex << symbol.at(inputLine.substr(0, 3)) << ": \t";
					}
					else
						binFile << counter << ": \t";

					binFile << value << "\t" << comment << endl;
					counter++;
				}

				// if the command was handled above or invalid, jump to next line
				if (commandIndex == -1) {
					continue;
				}
				else if (commandIndex <= 6) { // memory command
					int indirect = 0;
					if (inputLine.at(13) == 'I')
						indirect = pow(16, 3) * 8;

					// get address
					int addr;
					if (symbol.count(value))
						addr = symbol.at(value);
					else
						addr = convertHexToDec(value);
					// get command in decimal
					int decCommand = convertHexToDec(hexCode.at(commandIndex)) | indirect | addr;

					binFile << hex << counter << ": \t" << hex << decCommand 
						<< "\t" << comment << endl;
				}
				else { // not a memory instruction
					binFile << hex << counter << ": \t" << hexCode.at(commandIndex) 
						<< "\t" << comment << endl;
				}
				counter++;
			}
		}
		binFile.close();

		cout << "Symbol table and bin file generated. View " << filename.substr(0, filename.length() - 4) 
			<< ".sym and .bin in same location as source assembly file." << endl;
	}
	else
	{
		cout << "Enter a valid filename and extension found in the same folder as the executable." << endl;
		inFile.clear();
	}

	inFile.close();

	system("pause");
	return 0;
}