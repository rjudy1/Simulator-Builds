// Author:	Rachael Judy
// Date:	3/31/2020
// Purpose: Implement the GUI and functionality for cache simulator
// Modifications:
//					3/30/2020 - Generated from WXFormBuilder


#ifndef __subCacheGUI__
#define __subCacheGUI__

#include <vector>
#include <string>
#include <cstdlib>
#include <bitset>

#include "CacheGUI.h"

using namespace std;

// Cache Item struct stored in cache vector with int and binary tag stored
struct CacheItem {
	string strTag;
	string data;
	int intTag;
};

/** Implementing CacheGUI */
class subCacheGUI : public CacheGUI
{
	protected:
		// Handlers for CacheGUI events.
		void searchCache( wxCommandEvent& event );
		void resetCache( wxCommandEvent& event );
		void reset();
		void updateDisplay();
	public:
		/** Constructor */
		subCacheGUI( wxWindow* parent );
		
	//// end generated class members

	private: // vector that holds the "memory"
		const vector<string> memory = {
			"92", "70", "8C", "FD", "B9", "E2", "40", "C2",
			"0D", "9A", "D1", "F8", "43", "7E", "B7", "75",
			"FB", "44", "DD", "F6", "A6", "43", "11", "17",
			"98", "88", "08", "6A", "6D", "B8", "BC", "12",
			"0A", "F1", "4C", "45", "63", "2C", "40", "98",
			"91", "65", "0E", "76", "EE", "5D", "18", "29",
			"85", "13", "60", "C5", "56", "F2", "89", "9E",
			"06", "E2", "0B", "A2", "B2", "41", "B1", "7B"
		};

		vector <vector<CacheItem>> sets; // vector to hold cache; each set has two blocks
		vector <int> spotsOpen; // tracks which slot should be replaced if cache line is needed
};

#endif // __subCacheGUI__
