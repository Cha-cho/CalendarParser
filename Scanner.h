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
#include "Event.h"
#include <fstream>
#include <string.h>
#include <stdio.h>

using std::string;

class Scanner {
private:
    string currentCalendar;
    string timeOffset;
    
    string inString;
    string tagString;
    string fieldString;
    Event *newEvent;
    
    void stringParse(string inString);
    ifstream& fin;
    ofstream& fout;
    
public:
    Scanner(ifstream & fin, ofstream & fout);
    ~Scanner();

};

#endif
