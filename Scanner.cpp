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

Event Scanner::getEvent(Event* calEvent) {
    fin >> inString;
    tagString = getBeforeColon(inString);
    fieldString = getAfterColon(inString);
    
    if (tagString == "BEGIN") {
	    // could be the begining of Event, Calendar, or other (like timezone or alarm)
	    // probably will need own switch cases here
    } else if (tagString == "X-WR-CALNAME") {
	calEvent->setEventName(fieldString);
    } else if (tagString == "X-WR-TIMEZONE") {
	<#statements#>
    } else if (tagString == "TZOFFSETFROM") {
	<#statements#>
    } else if (tagString == "TZNAME") {
	<#statements#>
    } else if (tagString == "DTSTART;VALUE=DATE") {
	
    } else if (tagString == "DTEND;VALUE=DATE") {
	<#statements#>
    } else if (tagString == "DTSTAMP") {
	<#statements#>
    } else if (tagString == "CREATED") {
	<#statements#>
    } else if (tagString == "DESCRIPTION") {
	<#statements#>
    } else if (tagString == "LAST-MODIFIED") {
	<#statements#>
    } else if (tagString == "LOCATION") {
	<#statements#>
    } else if (tagString == "SUMMARY") {
	<#statements#>
    } else if (tagString == "END") {
	<#statements#>
    } else if (tagString == "UID") {
	<#statements#>
    } else if (tagString == "DTSTART") {
	<#statements#>
    } else if (tagString == "DTEND") {
	<#statements#>
    } else if (tagString == "CLASS") {
	<#statements#>
    } else if (tagString == "SEQUENCE") {
	<#statements#>
    } else if (tagString == "TRANSP") {
	<#statements#>
    } else if (tagString == "STATUS") {
	<#statements#>
    } else {
	
    }
}


}

Event Scanner::init_calendar() {
    
    
}
