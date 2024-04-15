#pragma once
#ifndef DateType_H
#define DateType_H
#include <string>

class DATEtype {
private:
    // Stores the MONTH (1 - 12//January - December)
    int month;
    // Stores the DAY (1 - LAST day of the month (28,30,31))
    int day;
    // Stores the YEAR (x >= 1900)
    int year;
    // Static Array to hold the valid names for the day variable
    static const std::string DAYofWEEK[];

public:
    //Preconditon: MONTH (1 - 12//January - December); DAY (1 - LAST day of the month (28,30,31)); YEAR (x >= 1900)
    DATEtype(int month = 1, int day = 1, int year = 1900);
    //Postcondition: Establishes a DATEtype object with a specific month, day, and year

    //Precondition: MONTH (1 - 12//January - December); DAY (1 - LAST day of the month (28,30,31)); YEAR (x >= 1900)
    void SETdate(int month, int day, int year);
    //Postcondition: Sets the month, day, and year of the DATEtype object

    //Precondition: MONTH (1 - 12//January - December)
    void setMONTH(int month);
    //Postcondition: Sets the month of the DATEtype object

    //Precondition: DAY (1 - LAST day of the month (28,30,31))
    void setDAY(int day);
    //Postcondition: Sets the day of the DATEtype object

    //Precondition: YEAR (x >= 1900)
    void setYEAR(int year);
    //Postcondition: Sets the year of the DATEtype object

    int GETMonth() const;
    //Postcondition: Returns the month of the DATEtype object

    int GETDay() const;
    //Postcondition: Returns the day of the DATEtype object

    int GETYear() const;
    //Postcondition: Returns the year of the DATEtype object

    //Precondition: Determines if the year is valid
    static bool isLEAPyear(int year);
    //Postcondition: True = Leap Year, False = Not Leap Year

    //Precondition: Determines if the month (1 - 12) and year (x >= 1900) is valid
    static int DAYSinMONTH(int month, int year);
    //Postcondition: Returns the number of days in the given month and year 

    void PRINTdate() const;
    //Postcondition: Prints the month, day, year; mm-dd-yyyy

    int daysPASSED() const;
    //Postcondition: Returns the number of days passed since the beginning of the year from the current date of that year

    int daysREMAIN() const;
    //Postcondition: Returns the number of days remaining since the beginning of the year from the current date of that year 

    //Precondition: Determines if the day is valid
    void SETdateFUTURE(int days);
    //Postcondition: Sets the specified date to the future date by adding the fixed number of days
};

#endif // DateType_H