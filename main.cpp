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

FILE *init_lister(const char *name, char source_file_name[], char dte[]);
void quit_scanner(FILE *src_file, Event *list);

int main(int argc, const char * argv[])
{
    Event *event = NULL;
    ifstream fin;
    ofstream fout;
    
    fin.open("input.txt");		// use shell script 'cat' to combine all the ICS files into one text file
    fout.open("output.csv");		// allows reading by MATLAB
    
    Scanner scanner(fin);
    
    do
	{
	event = scanner.getEvent();
        event->print();
	} while (scanner->getEvent() != END_OF_FILE);		// actually have "END:VCALENDAR"
    
	//delete token;
    fin.close();
    fout.close();
    
    return 0;
}


