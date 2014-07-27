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
#include <fstream>
#include "Date.h"
#include "String.h"
#include "common.h"


    // include some sort of calendar lib for calculating relative dates?

using namespace std;
using std::ofstream;
using std::stoi;


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
    ofstream& fout;
    int timeOffset;		// only hours for now. Perhaps add minutes later for int'l
    string timezoneName;
    
    double eventDuration;
    
public:
    Event(ofstream& fout,
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
	  string dateModifiedString);
    ~Event();
    string getYear(Date *date);
    string getMonth(Date *date);
    string getDay(Date *date);
    
    /*
    string getDayOfWeek(Date *date);
    string getDayString(Date *date);
    */
    
    string getLocation();
    string getEventName();
    string getCalendarName();
    bool isAllDay();
    string getUID();
    string getDescription();
    int getTimeOffset();
    string getTimezoneName();
    
    
    Date getDateStart();
    Date getDateEnd();
    Date getDateStamp();
    Date getDateCreated();
    Date getDateModified();
    
    
    void setDateStart(string dateString);
    void setDateEnd(string dateString);
    void setDateStamp(string dateString);
    void setDateCreated(string dateString);
    void setDateModified(string dateString);
    
    
    
    void setYear(Date *date);
    void setMonth(Date *date);
    void setDay(Date *date);
    void setDayOfWeek(Date *date);
    void setDayString(Date *date);
    void setLocation(string locat);
    void setEventName(string name);
    void setCalendarName(string calName);
    void setAllDay(bool isAllDay);
    void setUID(string UIDs);
    void setDescription(string descript);
    void setTimeOffset(string fieldString);
    void setTimezoneName(string fieldString);

    double calculateDuration();
    void print();
};

#endif /* defined(__CalendarParser__Event__) */













