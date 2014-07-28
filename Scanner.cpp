/* CalendarParser
 The goal is to take Google Calendar CSV files and parse the text contained in them
 to a spreadsheet format for data analysis.
 
 This program separates each event into its own token and then the print class determines
 how to output to spreadsheet format (may just give each category its own line in a text file).
 
 
 Created 5/15/14 by Matthew Weser
 */

#include "Scanner.h"


Scanner::Scanner(ifstream & infile, ofstream & outfile) : fin(infile), fout(outfile) {
	// meat of program occurs here
	// calendars, events, and all the details are scanned here
    
    
	//int line = 0;
	//bool calEnd = false;
    
    
    
    char inChar[1000];
    FILE* file = fopen("input.txt", "r");	// opens input file for fgets
    
    while (1) {
	
	    // BEGIN GRAB LINE ====================================================================================================
	fgets (inChar, 1000, file);			// get entire line until '\n' char (includes whitespaces, which is the important part)
	string inString(inChar);
	stringParse(inString);
	    //line++;
	    // END GRAB LINE ====================================================================================================
	
	
	    // BEGIN DATA CAPTURE ====================================================================================================
	if (tagString == "BEGIN") {
		// could be the begining of Event, Calendar, or other (like timezone or alarm)
		// probably will need own switch cases here
	    if (fieldString == "VEVENT") {
		
		    // basically creates new event with each BEGIN:VEVENT
		newEvent = new Event(fout, currentCalendar, timeOffset);
 
	    }
	    
	} else if (tagString == "END") {
		// if statements for the word that follows
		// grab same if statements as from BEGIN
	    
	    cout << fieldString << endl;
	    
	    if (fieldString == "VEVENT") {
		newEvent->print();		// event data printed to CSV		
		cout << "<<<<<<<<<<END OF EVENT>>>>>>>>>>>>>>>" << endl;
		
	    } else if (fieldString == "VCALENDAR") {
		cout << "END_CALENDAR" << endl;
		/*	Could just append special character at the end of the file in shell script with cat
		 if (EOF) {
		 cout << "EOF" << endl;
		 break;
		 }
		 */
	    }
	} else if (tagString == "X-WR-CALNAME") {
	    currentCalendar = fieldString;
	} else if (tagString == "DTSTART;VALUE=DATE") {
		// not sure what the difference between just regular DTSTART is
		// maybe some sort of version thing
	    newEvent->setDateStart(fieldString);
	} else if (tagString == "DTEND;VALUE=DATE") {
		// not sure what the difference between just regular DTSTART is
		// maybe some sort of version thing
	    newEvent->setDateEnd(fieldString);
	} else if (tagString == "DTSTAMP") {
	    newEvent->setDateStamp(fieldString);
	} else if (tagString == "CREATED") {
	    newEvent->setDateCreated(fieldString);
	} else if (tagString == "DESCRIPTION") {
	    newEvent->setDescription(fieldString);
	} else if (tagString == "LAST-MODIFIED") {
	    newEvent->setDateModified(fieldString);
	} else if (tagString == "LOCATION") {
	    newEvent->setLocation(fieldString);
	} else if (tagString == "SUMMARY") {
	    newEvent->setEventName(fieldString);
	} else if (tagString == "DTSTART") {
	    newEvent->setDateStart(fieldString);
	} else if (tagString == "DTEND") {
	    newEvent->setDateEnd(fieldString);
	} else if (tagString == "TZOFFSETFROM") {
		// will need to add to date class to find actual time of event at TZ
		// will need to also parse out as a field in date
	    timeOffset = fieldString;
	} else if (tagString == "EOF") {
	    cout << "The end of all things" << endl;
	    break;
	}
	
	
	/*********************************************************************
	 // fields may not be necessary, but add code for easy future functionality
	
	 else if (tagString == "TZNAME") {
	 // some future timezone info here
	 newEvent->setTimezoneName(fieldString);
	 } else if (tagString == "UID") {
	 newEvent->setUID(fieldString);
	 } else if (tagString == "CLASS") {
	 newEvent->setClass(fieldString);
	 } else if (tagString == "SEQUENCE") {
	 newEvent->setSequence(fieldString);
	 } else if (tagString == "TRANSP") {
	 newEvent->setTransparency(fieldString);
	 } else if (tagString == "STATUS") {
	 newEvent->setStatus(fieldString);
	 } else if (tagString == "X-WR-TIMEZONE") {
	 // some future timezone info here
	 *********************************************************************/
	
	
	    // END DATA CAPTURE ====================================================================================================
	
	
	
    }	// END EVENT DATA LOOP
    
}

Scanner::~Scanner() {
	// delete newEvent;
}

void Scanner::stringParse(string inString) {
    size_t colon = inString.find(":");					// finds index of colon in string
    size_t length = inString.find('\r');				// finds length of whole string
    tagString = inString.substr(0, colon);				// substring of 0->colon
    fieldString = inString.substr(colon + 1, length - colon - 1);	// substring from colon->end
}





