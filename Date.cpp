/* CalendarParser
 The goal is to take Google Calendar CSV files and parse the text contained in them
 to a spreadsheet format for data analysis.
 
 This program separates each event into its own token and then the print class determines
 how to output to spreadsheet format (may just give each category its own line in a text file).
 
 
 Created 5/15/14 by Matthew Weser
 */


    //starting format of date string: 2013 11 17 T 00 45 00 Z
    // 				      yyyy mm dd   hh mm ss

    // timezone for AZ is always: hour - 7
    // from the timeoffset data field

#include "Date.h"

Date::Date(string dateString) {			// parses out the formatted string
    
}

Date::~Date() {
    
}

string Date::getYear() {
	// get first four digits
    
}

string Date::getMonth() {
	// get next two digits
    
}

string Date::getDayOfWeek() {
    
}

string Date::getDay() {
	// get next two digits
    
}

string Date::getHour() {
	// skip 'T' char and get two digits
    
}

string Date::getMinute() {
	// get next two digits
    
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

void Date::toString() {
	// not sure, but probably use this to convert to proper ICS format

        // format of date string: 2013 11 17 T 00 45 00 Z
	// 			  yyyy mm dd   hh mm ss
    
    
    
}


