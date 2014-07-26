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

Date Event::getDateStart() {
    return *dateStart;
}

Date Event::getDateEnd() {
    return *dateEnd;
}

Date Event::getDateStamp() {
    return *dateStamp;
}

Date Event::getDateCreated() {
    return *dateCreated;
}

Date Event::getDateModified() {
    return *dateModified;
}

void Event::setDateStart(string dateString) {
    
}

void Event::setDateEnd(string dateString) {
    
}

void Event::setDateStamp(string dateString) {
    
}

void Event::setDateCreated(string dateString) {
    
}

void Event::setDateModified(string dateString) {
    
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

int Event::getTimeOffset() {
    return timeOffset;
}

string Event::getTimezoneName() {
    return timezoneName;
}

double Event::calculateDuration() {
	// dateEnd - dateStart
	// perhaps take date entries piece-by-piece, or just find Gregorian calendar lib
	// return number of hours: can convert later
    double hours = 0;
    
    
    return hours;
}

void Event::setYear(Date *date) {
    
}

void Event::setMonth(Date *date) {
    
}

void Event::setDay(Date *date) {
    
}

void Event::setDayOfWeek(Date *date) {
    
}

void Event::setDayString(Date *date) {
    
}

void Event::setLocation(string locat) {
    
}

void Event::setEventName(string name) {
    
}

void Event::setCalendarName(string calName) {
    
}

void Event::setAllDay(bool isAllDay) {
    
}

void Event::setUID(string UIDs) {
    
}

void Event::setDescription(string descript) {
    
}

void Event::setTimeOffset(const string fieldString) {
	// format: TZOFFSETTO:-0700
	// fieldstring: "-0700"
    	// 		 ±hhmm
    
    timeOffset = stoi(fieldString) / 100;		// make sure this is working properly
			
	// not exactly the way I want this to work, but it will suffice for the time being
}

void Event::setTimezoneName(string fieldString) {
    timezoneName = fieldString;		// e.g. "MST"
}





