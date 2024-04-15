#include <iostream>
#include "DateType.h"

int main() {
    // Establish the Default Constuctor w/ parameters    
    std::cout << "Default Constructor: ";
    DATEtype date1;
    date1.PRINTdate();
    // Expected Output: 01-01-1900

    // Establish the Default Constructor w/ NEW parameters
    std::cout << "Constructor: ";
    DATEtype date2(10, 10, 2010);
    date2.PRINTdate();
    // Expected Output: 10-10-2010

    std::cout << "Number of days passed: " << date2.daysPASSED() << std::endl;
    std::cout << "Number of days left: " << date2.daysREMAIN() << std::endl;
    // Expected Output: Determine the amount of days that passed/currently remaining for date2 (10-10-2010)

    std::cout << "Number of days in the month: " << DATEtype::DAYSinMONTH(date2.GETMonth(), date2.GETYear()) << std::endl;
    // Expected Output: Determine the amount of days in the selected month (October:31)

    // Set NUMdays = 50; add it to date2 (10-10-2010)
    int NUMdays = 50;
    std::cout << "After " << NUMdays << " days, date will be: ";
    date2.SETdateFUTURE(NUMdays);
    date2.PRINTdate();
    // Expected Output: 50 days after date2 (10-10-2010)

    // Resetting the year to the decade of the Constructor w/ NEW parameters
    int NEWyear = (date2.GETYear() / 10) * 10;
    std::cout << "Resetting year to " << NEWyear << ":";
    date2.setYEAR(NEWyear);
    date2.PRINTdate();
    // Expected Output: 2010

    // Resetting the UPDATED month to reset to the same month
    int LASTdayMONTH = DATEtype::DAYSinMONTH(date2.GETMonth(), date2.GETYear());
    std::cout << "Resetting Day to " << LASTdayMONTH << ": ";
    date2.setDAY(LASTdayMONTH);
    date2.PRINTdate();
    // Expected Output: Updated date with month reset to the same month

    // Resetting day to the last day of the month for the constructor w/ NEW parameters
    int NEWyear2 = date2.GETYear() + 1;
    std::cout << "Resetting year to " << NEWyear2 << ": ";
    date2.setYEAR(NEWyear2);
    date2.PRINTdate();
    // Expected output: Updated date with day reset to the last day of the month

    // Resetting month to January
    std::cout << "Resetting month to 1 (January): ";
    date2.setMONTH(1);
    date2.PRINTdate();
    // Expected output: Updated date with month reset to January

    return 0;
}