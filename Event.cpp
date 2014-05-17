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

Event::Event() {
    
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

string Event::dateToString(Date *date) {
    
}

void Event::print() {
    fout << calendarName << ',' << eventName << ',' << location << ',' << description << ',' << dateStartStr << ',' << dateEndStr << ',' << dateCreatedStr << ',' << dateModifiedStr << ',' << dateStampStr << ',' << eventDuration << endl;
    
    
}



