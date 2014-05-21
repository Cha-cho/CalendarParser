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

Event::Event(ofstream & outfile,
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
	     string dateModifiedString)
: fout(outfile),
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

string Event::getYear(Date *date) {
    return date->getYear();
}

string Event::getMonth(Date *date) {
    return date->getMonth();

}

string Event::getDay(Date *date) {
    return date->getDay();

}

string Event::getDayOfWeek(Date *date) {
    return date->getDayOfWeek();

}

string Event::getDayString(Date *date) {
    return date->getDayString();

}

string Event::getLocation() {
    return location;

}

string Event::getEventName() {
    return eventName;
}

string Event::getCalendarName() {
    return calendarName;
}

bool Event::isAllDay() {
    return allDay;
}

string Event::getUID() {
    return UID;
}

string Event::getDescription() {
    return description;
}

double Event::calculateDuration() {
	// dateEnd - dateStart
	// perhaps take date entries piece-by-piece, or just find Gregorian calendar lib
	// return number of hours: can convert later
    double hours = 0;
    
    
    return hours;
}

void setYear(Date *date) {
    
}

void setMonth(Date *date) {
    
}

void setDay(Date *date) {
    
}

void setDayOfWeek(Date *date) {
    
}

void setDayString(Date *date) {
    
}

void setLocation(string locat) {
    
}

void setEventName(string name) {
    
}

void setCalendarName(string calName) {
    
}

void setAllDay(bool isAllDay) {
    
}

void setUID(string UIDs) {
    
}

void setDescription(string descript) {
    
}






