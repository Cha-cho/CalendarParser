/* CalendarParser
 The goal is to take Google Calendar CSV files and parse the text contained in them
 to a spreadsheet format for data analysis.
 
 This program separates each event into its own token and then the print class determines
 how to output to spreadsheet format (may just give each category its own line in a text file).
 
 
 Created 5/15/14 by Matthew Weser
 */

#include "Event.h"

/* use to parse from string to int
 std::string s = "10";
 int i = std::stoi(s);
 */

Event::Event(fstream fout,
	     string name,
	     string descript,
	     string locat,
	     string calName,
	     bool isAllDay,
	     int nGuests,
	     string UIDs,
	     string dateStartString,
	     string dateEndString,
	     string dateStampString,
	     string dateCreatedString,
	     string dateModifiedString) :
eventName(name),
description(descript),
location(locat),
calendarName(calName),
allDay(isAllDay),
numGuests(nGuests),
UID(UIDs),
dateStartStr(dateStartString),
dateEndStr(dateEndString),
dateStampStr(dateStampString),
dateCreatedStr(dateCreatedString),
dateModifiedStr(dateModifiedString)
{
    
}

Event::~Event() {
    
}

string Event::getYear(Date *date) {
    
}

string Event::getMonth(Date *date) {
    
}

string Event::getDay(Date *date) {
    
}

string Event::getDayOfWeek(Date *date) {
    
}

string Event::getDayString(Date *date) {
    
}

string Event::getLocation() {
    
}

string Event::getEventName() {
    
}

string Event::getCalendarName() {
    
}

bool Event::isAllDay() {
    
}

string Event::getUID() {
    
}

string Event::getDescription() {
    
}

double Event::calculateDuration() {
    
}

void Event::print() {
    fout <<
    calendarName << ',' <<
    eventName << ',' <<
    location << ',' <<
    description << ',' <<
    dateStartStr << ',' <<
    dateEndStr << ',' <<
    dateCreatedStr << ',' <<
    dateModifiedStr << ',' <<
    dateStampStr << ',' <<
    eventDuration <<
    endl;
    
    
}



