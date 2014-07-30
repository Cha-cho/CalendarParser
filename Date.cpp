/* CalendarParser
 The goal is to take Google Calendar CSV files and parse the text contained in them
 to a spreadsheet format for data analysis.
 
 This program separates each event into its own token and then the print class determines
 how to output to spreadsheet format (may just give each category its own line in a text file).
 
 
 Created 5/15/14 by Matthew Weser
 */


    //starting format of date string: 2013 11 17 T 00 45 00 Z
    // 				      yyyy mm dd   hh mm ss
    //				      0123 45 67 8 90 12 34 5

    // timezone for AZ is always: hour - 7
    // from the timeoffset data field

#include "Date.h"

Date::Date(string dateString, int timeOffset) {
	// parses out the formatted string into individual strings
	// simply stores strings
	// any sort of date calculations require 'stoi' to convert to int
    
    
    
    
	// use substring class (position, length) to parse parts of dateString
    year = dateString.substr(0,4);
    month = dateString.substr(4,2);
    day = dateString.substr(6,2);
    hour = dateString.substr(9,2);
    minute = dateString.substr(11,2);
    
    
    
    
	// CALCULATE PROPER TIMEZONE TIME HERE WITH TIMEOFFSET
    
    
    
}

Date::~Date() {
    
}

string Date::getYear() {
    return year;
}

string Date::getMonth() {
    return month;
}

string Date::getDay() {
    return day;
}

string Date::getHour() {
    return hour;
}

string Date::getMinute() {
    return minute;
}


/*
 string Date::getDayOfWeek() {
 
 }
 
 string Date::getDayString() {
 
 }
 
 
 void Date::setYear(int year) {
 this->year = year;
 }
 
 void Date::setMonth(int month) {
 this->month = month;
 }
 
 void Date::setDayOfWeek(int dayOfWeek) {
 this->dayOfWeek = dayOfWeek;
 }
 
 void Date::setDay(int day) {
 this->day = day;
 }
 
 void Date::setHour(int hour) {
 this->hour = hour;
 }
 
 void Date::setMinute(int minute) {
 this->minute = minute;
 }
 
 void Date::setDayString(string dayString) {
 this->dayString = dayString;
 }
 */

string Date::toString() {
	// may need this to convert to friendly spreadsheet format
        // format of date string: 2013 11 17 T 00 45 00 Z
	// 			  yyyy mm dd   hh mm ss
    
    string output = year + "/" + month + "/" + day + "  " + hour + ":" + minute;
    return output;

}

void Date::toDateString() {
	// converts to original ICS formatting
    
        // format of date string: 2013 11 17 T 00 45 00 Z
	// 			  yyyy mm dd   hh mm ss
    
    string output = year + month + day + 'T' + hour + minute + "00Z";
}


