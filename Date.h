/* CalendarParser
 The goal is to take Google Calendar CSV files and parse the text contained in them
 to a spreadsheet format for data analysis.
 
 This program separates each event into its own token and then the print class determines
 how to output to spreadsheet format (may just give each category its own line in a text file).
 
 
 Created 5/15/14 by Matthew Weser
 */

#ifndef __CalendarParser__Date__
#define __CalendarParser__Date__

#include <iostream>
    // include some sort of calendar lib?

using namespace std;

class Date {
private:
    int year;
    int month;
    int dayOfWeek;
    int day;
    int hour;
    int minute;
    string dayString;
    
    string dateString;
    
    
public:
    Date(string dateString);		// parses out the formatted string
    ~Date();
    string getYear();
    string getMonth();
    string getDayOfWeek();
    string getDay();
    string getHour();
    string getMinute();
    string getDayString();
    
    void toString();
    
};


#endif /* defined(__CalendarParser__Date__) */
