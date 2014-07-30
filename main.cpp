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
    fout.open("output.csv");		// allows reading by MATLAB
   
    fout <<
    "Calendar" << ',' <<
    "Event" << ',' <<
    "Location" << ',' <<
    "Description" << ',' <<
    "Start" << ',' <<
    "End" << ',' <<
    "Created" << ',' <<
    "Modified" << ',' <<
    "Date Stamp" << ',' <<
    "Duration" <<
    endl;
    
    
    while (!isEOF) {
	Scanner scanner(fin, fout);	// runs through all events in the file
	
	if (EOF) {			// not sure if this thing does what you think it does
	    isEOF = true;
	    fin.close();
	    fout.close();
	}
    }

    
    return 0;
}



