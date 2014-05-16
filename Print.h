/* CalendarParser
 The goal is to take Google Calendar CSV files and parse the text contained in them
 to a spreadsheet format for data analysis.
 
 This program separates each event into its own token and then the print class determines
 how to output to spreadsheet format (may just give each category its own line in a text file).
 
 
 Created 5/15/14 by Matthew Weser
 */

#ifndef __Lab4__Print__
#define __Lab4__Print__

#include <iostream>
#include "common.h"
#include "Token.h"
#include "Identifier.h"
#include "Integer.h"
#include "Real.h"
#include "String.h"

using namespace std;

class LineNumberList;


class Print {
private:
    string sourceFileName;
    string currentDate;
    int pageNumber;
    int lineCount;
    void printPageHeader();
    
public:
    Print(char source_name[], char date[]);
    ~Print();
    void printLine(char line[]);
    void printToken(Token *token);
    int getLineCount();
    void printTree(Identifier *identifier);
    void printTreeRecursive(Identifier *identifier);
};

#endif /* defined(__Lab4__Print__) */
