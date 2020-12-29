// Author:	Rachael Judy
// Date:	3/31/2020
// Purpose: Implement the GUI and functionality for cache simulator
// Modifications:
//

#include "subCacheGUI.h"

// general function that checks that string entered is an integer
bool isInt(string str) {
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}

// sets up cache and number tracking vectors to right size
subCacheGUI::subCacheGUI(wxWindow* parent) : CacheGUI(parent) {
	reset();
}

// checks cache for requested address, 
// if available displays, if not brings data to cache with FIFO
void subCacheGUI::searchCache(wxCommandEvent& event)
{
	string input = inputText->GetLabel(); // get input
	int address;
	string status = "Cache Miss\n"; // defaults to a miss
	string resultData; // will contain the data
	int setNum; // determines the set number the data should belong to
	int tag;

	// validate input as integer between 0 and 63, inclusive
	if (isInt(input) && stoi(input) <= 63 && stoi(input) >= 0) {
		address = stoi(input); // decimal address of main memory
		setNum = address % 4;
		tag = address / 4; // decimal tag

		// search for a cache hit by comparing both tags
		// at that index to the desired tag
		for (int i = 0; i < 2; i++)
			if (sets.at(setNum).at(i).intTag == tag) {
				status = "Cache Hit\n";
				resultData = sets.at(setNum).at(i).data;
			}

		// if not found, bring the data into the cache from memory
		if (status == "Cache Miss\n") {
			resultData = memory.at(address);

			// create cache item
			CacheItem c;
			c.intTag = tag;
			c.strTag = bitset<4>(c.intTag).to_string();
			c.data = memory.at(address);

			// add item to cache vector and switch next to be replaced
			sets.at(setNum).at(spotsOpen.at(setNum)) = c;
			spotsOpen.at(setNum) = 1 - spotsOpen.at(setNum);

			// update the cache display
			updateDisplay();

		}
		resultLabel->SetLabel(status + "Data: " + resultData);
	}
	else {
		resultLabel->SetLabel("The entry must be a decimal\n   in range 0 to 63.");
	}
}


void subCacheGUI::resetCache(wxCommandEvent& event) {
	reset();
}

// resets cache display and vector
void subCacheGUI::reset() {
	CacheItem c;
	c.data = "__";
	c.strTag = "____";
	c.intTag = 64; // out of range so shouldn't be used

	// resets size of cache vector to empty it
	sets.resize(4);
	for (int i = 0; i < sets.size(); i++) {
		sets.at(i).resize(2);
		for (int j = 0; j < sets.at(i).size(); j++) {
			sets.at(i).at(j) = c;
		}
	}
	updateDisplay();

	// resets the open spot in the cache to the first available
	spotsOpen.resize(4);
	for (int i = 0; i < spotsOpen.size(); i++)
		spotsOpen.at(i) = 0;
}

// reloads full display, saves code by doing whole thing
// but less efficient then targeted update
void subCacheGUI::updateDisplay() {
	tag000->SetLabel(sets.at(0).at(0).strTag);
	data000->SetLabel(sets.at(0).at(0).data);
	tag001->SetLabel(sets.at(0).at(1).strTag);
	data001->SetLabel(sets.at(0).at(1).data);

	tag010->SetLabel(sets.at(1).at(0).strTag);
	data010->SetLabel(sets.at(1).at(0).data);
	tag011->SetLabel(sets.at(1).at(1).strTag);
	data011->SetLabel(sets.at(1).at(1).data);

	tag100->SetLabel(sets.at(2).at(0).strTag);
	data100->SetLabel(sets.at(2).at(0).data);
	tag101->SetLabel(sets.at(2).at(1).strTag);
	data101->SetLabel(sets.at(2).at(1).data);

	tag110->SetLabel(sets.at(3).at(0).strTag);
	data110->SetLabel(sets.at(3).at(0).data);
	tag111->SetLabel(sets.at(3).at(1).strTag);
	data111->SetLabel(sets.at(3).at(1).data);
}