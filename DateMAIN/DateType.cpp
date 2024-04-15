#include "DateType.h"
#include <iostream>

// Static array to hold the names of the days of the week
const std::string DATEtype::DAYofWEEK[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

// Establish the Default Constuctor w/ parameters    
DATEtype::DATEtype(int month, int day, int year) {
    SETdate(month, day, year);
}

// Establish a Function to set the date with provided values
void DATEtype::SETdate(int month, int day, int year) {
    // Validate the Year and Month
    if (year >= 1900 && month >= 1 && month <= 12) {
        // Get the maximum days in the month
        int MAXdays = DAYSinMONTH(month, year);
        // Validate the Day
        if (day >= 1 && day <= MAXdays) {
            this->month = month;
            this->day = day;
            this->year = year;
            // Set MONTH, DAY, YEAR ^^ 
        }
    }
}

// Establish a Function to set the Month
void DATEtype::setMONTH(int month) {
    // Validate the Month
    if (month >= 1 && month <= 12) {
        // Set the MONTH
        this->month = month;
    }
}

// Establish a Function to set the Day
void DATEtype::setDAY(int day) {
    // Get the MAXIMUM days in the month
    int MAXdays = DAYSinMONTH(this->month, this->year);
    // Validate the Day
    if (day >= 1 && day <= MAXdays) {
        this->day = day;
        // Set the DAY
    }
}

// Establish a Function to set the Year
void DATEtype::setYEAR(int year) {
    // Validate the Year
    if (year >= 1900) {
        this->year = year;
        // Set the YEAR
    }
}

// Establish a Function to get the Month
int DATEtype::GETMonth() const {
    return month;
    // Return the MONTH
}

// Establish a Function to get the Day
int DATEtype::GETDay() const {
    return day;
    // Return the DAY
}

// Establish a Function to get the Year
int DATEtype::GETYear() const {
    return year;
    // Return the YEAR
}

// Establish a Function to determine whether or not the specific year is a LEAP YEAR
bool DATEtype::isLEAPyear(int year) {
    // Establish a Formula for the Leap Year
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Establish a Function to determine the amount of days there is in a month 
int DATEtype::DAYSinMONTH(int month, int year) {
    // If the selected month is Februaury
    if (month == 2) {
        // Check for the LEAP YEAR
        return (isLEAPyear(year) ? 29 : 28);
        // April, June, September, and November have 30 days
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        // January, March, May, July, August, October, and December have 31 days
        return 31;
    }
}

// Establish a Function the print the Date
void DATEtype::PRINTdate() const {
    std::cout << month << "-" << day << "-" << year << std::endl;
    // Expected Format: mm-dd-yyyy
}

// Establish a Function to determine the amount of days passed since the BEGINNING of the year
int DATEtype::daysPASSED() const {
    int TOTALdays = 0;
    // Loop through months prior to the current month
    for (int m = 1; m < month; ++m) {
        // Add days in each month to total
        TOTALdays += DAYSinMONTH(m, year);
    }
    // Add current day
    TOTALdays += day;
    return TOTALdays;
    //Return total days PASSED
}

// Establish a Function to determine the amount of days are remaining in a Year
int DATEtype::daysREMAIN() const {
    // Get total days passed
    int TOTALdays = daysPASSED();
    // Get total days in year
    int daysINyear = (isLEAPyear(year) ? 366 : 365);
    return daysINyear - TOTALdays;
    // Return remaining days
}

//Establish a Function to set the date to a future date by adding a specified number of days
void DATEtype::SETdateFUTURE(int days) {
    // Get total days passed
    int TOTALdays = daysPASSED();
    // Add specified number of days
    TOTALdays += days;
    // Initialize year
    int year = this->year;
    // Loop until all days are accounted for
    while (TOTALdays > 0) {
        // Get total days in year
        int daysINyear = (isLEAPyear(year) ? 366 : 365);
        // If more days than the year
        if (TOTALdays > daysINyear) {
            // Subtract days in year
            TOTALdays -= daysINyear;
            // Move to next year
            year++;
        }
        else {
            int month = 1;
            // Loop until days are within the month
            while (TOTALdays > DAYSinMONTH(month, year)) {
                // Subtract days in month
                TOTALdays -= DAYSinMONTH(month, year);
                // Move to next month
                month++;
            }
            this->year = year;
            this->month = month;
            this->day = day;
            break;
            // Set the YEAR, MONTH, and DAY
        }
    }
}