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
    
	// date objects
    Date *dateStart;
    Date *dateEnd;
    Date *dateStamp;
    Date *dateCreated;
    Date *dateModified;
    
	// date strings
    string dateStartStr;
    string dateEndStr;
    string dateStampStr;
    string dateCreatedStr;
    string dateModifiedStr;
    
	// other event properties
    string eventName;
    string description;
    string location;
    string calendarName;
    bool allDay;
    int numGuests;
    string UID;
    ofstream& fout;
    string timeOffsetString;		// only hours for now. Perhaps add minutes later for int'l
    int timeOffsetInt;			// int used for calculations, string used for printing
    string timezoneName;
    
	// calculated properties
    double eventDuration;
    
public:
    Event(ofstream& outfile,
	  string calName,
	  string timeOffset);
    ~Event();
    
    
	// UTILITIES ==================================================
    
    double calculateDuration();
    void print();

    
    
	// GET =========================================================
    
	// get Event properties
    string getLocation();
    string getEventName();
    string getCalendarName();
    bool isAllDay();
    string getUID();
    string getDescription();
    int getTimeOffsetInt();
    string getTimeOffsetString();
    string getTimezoneName();
    
    /* string getDayOfWeek(Date *date);
     string getDayString(Date *date);*/
    
    
	// get Date objects
    Date getDateStart();
    Date getDateEnd();
    Date getDateStamp();
    Date getDateCreated();
    Date getDateModified();
    


	// SET =========================================================
	
	// set Date objects and strings simultaneously
    void setDateStart(string dateString);
    void setDateEnd(string dateString);
    void setDateStamp(string dateString);
    void setDateCreated(string dateString);
    void setDateModified(string dateString);
   
	// set Event properties
    void setLocation(string locat);
    void setEventName(string name);
    void setCalendarName(string calName);
    void setAllDay(bool isAllDay);
    void setUID(string UIDs);
    void setDescription(string descript);
    void setTimeOffsetInt(string fieldString);
    void setTimezoneName(string fieldString);
    
    
};

#endif /* defined(__CalendarParser__Event__) */













