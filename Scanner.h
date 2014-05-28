/* CalendarParser
 The goal is to take Google Calendar CSV files and parse the text contained in them
 to a spreadsheet format for data analysis.
 
 This program separates each event into its own token and then the print class determines
 how to output to spreadsheet format (may just give each category its own line in a text file).
 
 
 Created 5/15/14 by Matthew Weser
 */

#ifndef Lab4_Scanner_h
#define Lab4_Scanner_h

#include "common.h"
#include <fstream>
#include "Event.h"
#include <string.h>


class Scanner {
private:
    string inString;
    string tagString;
    string fieldString;
    Event *newEvent;
    
    string getBeforeColon(string inString);
    string getAfterColon(string inString);			// not sure what the right parameters here should be or the return: see what works
    
    ifstream& fin;
    
public:
    Scanner(ifstream& infile);
    ~Scanner();
    Event getEvent(Event* calEvent);

};

#endif
