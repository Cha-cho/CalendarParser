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
using std::string;
using std::stoi;


class Date {
private:
	// store each date field as string
	// only convert to int for time calculations
    string year;
    string month;
    string dayOfWeek;
    string day;
    string hour;
    string minute;
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
    
    void setYear(int year);
    void setMonth(int month);
    void setDayOfWeek(int dayOfWeek);
    void setDay(int day);
    void setHour(int hour);
    void setMinute(int minute);
    void setDayString(string dayString);
    
    void toString();
    
};


#endif /* defined(__CalendarParser__Date__) */
