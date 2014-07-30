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

Event::Event(ofstream& outfile,
	     string calName,
	     string tzOffset)
: fout(outfile),
calendarName(calName),
timeOffsetString(tzOffset)
{
    setTimeOffsetInt(timeOffsetString);		// int used for calculations, string used for printing
    
    
    
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
    
    
    cout <<
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
    dateStart = new Date(dateString, timeOffsetInt);
    dateStartStr = dateStart->toString();
}

void Event::setDateEnd(string dateString) {
    dateEnd = new Date(dateString, timeOffsetInt);
    dateEndStr = dateEnd->toString();
}

void Event::setDateStamp(string dateString) {
    dateStamp = new Date(dateString, timeOffsetInt);
    dateStampStr = dateStamp->toString();
}

void Event::setDateCreated(string dateString) {
    dateCreated = new Date(dateString, timeOffsetInt);
    dateCreatedStr = dateCreated->toString();
}

void Event::setDateModified(string dateString) {
    dateModified = new Date(dateString, timeOffsetInt);
    dateModifiedStr = dateModified->toString();
}


/*
 string Event::getDayOfWeek(Date *date) {
 return date->getDayOfWeek();
 
 }
 
 string Event::getDayString(Date *date) {
 return date->getDayString();
 
 }
 */

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

string Event::getTimeOffsetString() {
    return timeOffsetString;
}

int Event::getTimeOffsetInt() {
    return timeOffsetInt;
}

/*
 string Event::getTimezoneName() {
 return timezoneName;
 }*/

double Event::calculateDuration() {
	// dateEnd - dateStart
	// (yearEnd - yearStart)*365.25*24 + (dayEnd - dayStart)*24 + (hourEnd - hourStart) + (minEnd - minStart)/60
    	// 				     ^ideally would have 'day of year' and have leap years taken care of
	// perhaps take date entries piece-by-piece, or just find Gregorian calendar lib
	// return number of hours in decimal format: can convert later
    double hours = 0;
    
    int numYear = stoi(dateEnd->getYear()) - stoi(dateStart->getYear());
    int numDay = stoi(dateEnd->getDay()) - stoi(dateStart->getDay());
    int numHour = stoi(dateEnd->getHour()) - stoi(dateStart->getHour());
    int numMinute = stoi(dateEnd->getMinute()) - stoi(dateStart->getMinute());
    
	// enter cases where day may be negative (1st of month - 31st of month)
    if (numDay < 0) {
	numDay = 1;
    } else if (numHour < 0) {
	numHour += 24;
    } else if (numMinute < 0) {
	numHour += 60;
    }
    
    hours = numYear*365.25*24 + numDay*24 + numHour + numMinute/60;
    return hours;
}

void Event::setLocation(string locat) {
    location = locat;
}

void Event::setEventName(string name) {
    eventName = name;
}

void Event::setCalendarName(string calName) {
    
}

void Event::setAllDay(bool isAllDay) {
    allDay = isAllDay;
}

void Event::setUID(string UIDs) {
    UID = UIDs;
}

void Event::setDescription(string descript) {
    description = descript;
}

void Event::setTimeOffsetInt(const string fieldString) {
	// format: TZOFFSETTO:-0700
	// fieldstring: "-0700"
    	// 		 ±hhmm
    
    timeOffsetInt = stoi(fieldString) / 100;		// make sure this is working properly
    
	// not exactly the way I want this to work, but it will suffice for the time being
}

/*
 void Event::setTimezoneName(string fieldString) {
 timezoneName = fieldString;		// e.g. "MST"
 }*/





