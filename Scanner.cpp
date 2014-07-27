/* CalendarParser
 The goal is to take Google Calendar CSV files and parse the text contained in them
 to a spreadsheet format for data analysis.
 
 This program separates each event into its own token and then the print class determines
 how to output to spreadsheet format (may just give each category its own line in a text file).
 
 
 Created 5/15/14 by Matthew Weser
 */

#include "Scanner.h"


Scanner::Scanner(ifstream & infile) : fin(infile) {
    
}

Scanner::~Scanner() {
	// delete newEvent;
}

Event Scanner::getEvent() {
    bool calEnd = false;
    char inChar[500];
    FILE* file = fopen("input.txt", "r");	// opens input file for fgets
    int line = 0;
    
    /*******************************
     Here is where you should copy calEvent fields into newEvent */
    while (line < 116599) {
	
	fgets (inChar, 500, file);			// get entire line until '\n' char (includes whitespaces, which is the important part)
	string inString(inChar);
	stringParse(inString);
	line++;
	
	if (tagString == "BEGIN") {
		// could be the begining of Event, Calendar, or other (like timezone or alarm)
		// probably will need own switch cases here
	    if (fieldString == "VEVENT") {
		newEvent->setCalendarName(currentCalendar);
		newEvent->setTimeOffset(timeOffset);
	    }
	    
	} else if (tagString == "END") {
		// if statements for the word that follows
		// grab same if statements as from BEGIN
	    
	    cout << fieldString << endl;
	    
	    if (fieldString == "VEVENT") {
		
		cout << "<<<<<<<<<<END OF EVENT>>>>>>>>>>>>>>>" << endl;
		    //calEnd = true;
	    } else if (fieldString == "VCALENDAR") {
		cout << "END_CALENDAR" << endl;
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
	} else if (tagString == "TZNAME") {
		// some future timezone info here
	    newEvent->setTimezoneName(fieldString);
	    
	}
	
	
	/*********************************************************************
	 // fields may not be necessary, but add code for easy future functionality
	 
	 else if (tagString == "UID") {
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
	
    }
    
    return *newEvent;		// make sure to differentiate between this and calEvent
}

void Scanner::stringParse(string inString) {
    size_t colon = inString.find(":");				// finds index of colon in string
    size_t length = inString.length();				// finds length of whole string
    tagString = inString.substr(0, colon);			// substring of 0->colon
    fieldString = inString.substr(colon + 1, length - 1);	// substring from colon->end
    
}





