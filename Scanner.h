/* CalendarParser
 The goal is to take Google Calendar CSV files and parse the text contained in them
 to a spreadsheet format for data analysis.
 
 This program separates each event into its own token and then the print class determines
 how to output to spreadsheet format (may just give each category its own line in a text file).
 
 
 Created 5/15/14 by Matthew Weser
 */

#ifndef Lab4_Scanner_h
#define Lab4_Scanner_h

#include "my_ctype.h"
#include "common.h"
#include <fstream>
#include "Event.h"


class Scanner
{
private:
    /*********************
     Private Variables for Scanner
     Must be initialized in the constructor.
     *********************/

    string categoryName;
    string fieldName;
    char *linePtr;
    string lineString;
    Event *newEvent;
    
    void skipToColon(string lineString);		// not sure how to do this versus pointer manipulation
    string getCategoryName(char *linePtr);
    string getFieldName(char *linePtr);			// not sure what the right parameters here should be or the return: see what works
    string getNextLine(char *linePtr);			// moves to next line for extraction, if done with current line
    
    ifstream& fin;
    
public:
    Scanner(ifstream& infile);
    ~Scanner();
    Event* getEvent();

};

#endif
