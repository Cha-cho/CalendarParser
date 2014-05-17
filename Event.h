/* CalendarParser
 The goal is to take Google Calendar CSV files and parse the text contained in them
 to a spreadsheet format for data analysis.
 
 This program separates each event into its own token and then the print class determines
 how to output to spreadsheet format (may just give each category its own line in a text file).
 
 
 Created 5/15/14 by Matthew Weser
 */

#ifndef __CalendarParser__Event__
#define __CalendarParser__Event__

#include <iostream>
#include "Date.h"
#include "String.h"
#include "common.h"
  // include some sort of calendar lib for calculating relative dates?

using namespace std;

class Event {
private:
    Date *dateStart;
    Date *dateEnd;
    Date *dateStamp;
    Date *dateCreated;
    Date *dateModified;
    
    string dateStartStr;
    string dateEndStr;
    string dateStampStr;
    string dateCreatedStr;
    string dateModifiedStr;
    
    string eventName;
    string description;
    string location;
    string calendarName;
    bool allDay;
    int numGuests;
    string UID;
    
    double eventDuration;
    
public:
    Event();
    ~Event();
    string getYear(Date *date);
    string getMonth(Date *date);
    string getDay(Date *date);
    string getDayOfWeek(Date *date);
    string getDayString(Date *date);
    string getLocation();
    string getEventName();
    string getCalendarName();
    bool isAllDay();
    string getUID();
    string getDescription();
    
    double calculateDuration();
    void print();
};

#endif /* defined(__CalendarParser__Event__) */













