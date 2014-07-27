/* CalendarParser
 The goal is to take Google Calendar CSV files and parse the text contained in them
 to a spreadsheet format for data analysis.
 
 This program separates each event into its own token and then the print class determines
 how to output to spreadsheet format (may just give each category its own line in a text file).
 
 
 Created 5/15/14 by Matthew Weser
 */

#include <iostream>
#include <fstream>
#include <typeinfo>
#include "common.h"
#include "Scanner.h"
#include "Date.h"
#include "Event.h"

using namespace std;
void run(ifstream & infile, ofstream & fout);

int main(int argc, const char * argv[])
{
    ifstream fin;
    ofstream fout;
    bool isEOF = false;
    
    fin.open("input.txt");		// use shell script 'cat' to combine all the ICS files into one text file
    fout.open("output.txt");		// allows reading by MATLAB
   
    while (!isEOF) {
	run(fin, fout);
	
	if (EOF) {			// not sure if this thing does what you think it does
	    isEOF = true;
	    fin.close();
	    fout.close();
	}
    }

    
    return 0;
}

void run(ifstream & fin, ofstream & fout) {
	// certain calendar properties will be grabbed, and then won't change until the next calendar is accessed
	// properties: calName, timezone
    	// set up as some sort of global var that can be accessed with each new event, updated with the new calendar
    
    bool calDone = false;
	//Event *newEvent = NULL;

    Scanner scanner(fin);
    
    while (!calDone) {
	cout << "Next event" << endl;
	Event newEvent = scanner.getEvent();		// need to add to parameter listing for event
	newEvent.print();
	    // somehow delete event
    }
}



