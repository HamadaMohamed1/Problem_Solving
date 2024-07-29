/*
* Problem #4
* Write a program to print number of Dayes,Hours,Minutes,and Seconds in certian year
*/
#include <iostream>
#include <string>
using namespace std;

int ReadNumber(string message)
{
    int num;
    cout << message << endl;
    cin >> num;
    return num;
}

string NumberToText(int number)
{
    if (number == 0)
    {
        return "";
    }

    if (number >=1 && number <= 19)
    {
        string arr[] = {"","One ","Two ","Three ","Four ","Five ","Six ","Seven ",
        "Eight ","Nine ","Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ",
        "Fifteen ","Sixteen ","Seventeen ","Eighteen ","Ninteen "};
        return arr[number];
    }

    if (number >= 20 && number <= 99)
    {
        string arr[] = {"","","Twenty ","Thirty ","Forty ","Fifty ","Sixty ",
        "Seventy ","Eighty ","Nintey "};
        return arr[number / 10] + NumberToText(number % 10);
    }

    if (number >= 100 && number <= 199)
    {
        return "One Handred " + NumberToText(number % 100);
    }

    if (number >= 200 && number <= 999)
    {
        return NumberToText(number / 100) + "Handreds " + NumberToText(number % 100);
    }

    if (number >= 1000 && number <= 1999)
    {
        return "One Thounsand " + NumberToText(number % 1000);
    }

    if (number >= 2000 && number <= 999999)
    {
        return NumberToText(number / 1000) + "Thounsands " + NumberToText(number % 1000);
    }

    if (number >= 1000000 && number <= 1999999)
    {
        return "One Million " + NumberToText(number % 1000000);
    }

    if (number >= 2000000 && number <= 999999999)
    {
        return NumberToText(number / 1000000) + "Millions " + NumberToText(number % 1000000);
    }

    if (number >= 1000000000 && number <= 1999999999)
    {
        return"One Billion " + NumberToText(number % 1000000000);
    } 
    else    
    { 
        return   NumberToText(number / 1000000000) + "Billions " + NumberToText(number % 1000000000);
    }
}

bool IsLeapYear(short year)
{
    //if (year % 400 == 0)/*leap year if divisable by 400*/
    //{
    //    return true;
    //}
    //else if (year % 4 == 0 && year % 100 != 0)/*leap year if divisable by 4 and not ending with 00 i.e 1900*/
    //{
    //    return true;
    //}
    //else
    //{
    //    return false;
    //}
    
   // return (year % 400 == 0) ? true : (year % 4 == 0 && year % 100 != 0) ? true : false;
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

short NumberOfDayesInYear(short year)
{
    return IsLeapYear(year) ? 366 : 365;
}

int NumberOfHoursInYear(short year)
{
    return NumberOfDayesInYear(year) * 24;
}

int NumberOfMinutesInYear(short year)
{
    return NumberOfHoursInYear(year) * 60;
}
int NumberOfSecondsInYear(short year)
{
    return NumberOfMinutesInYear(year) * 60;
}


int main()
{
    
    short year = ReadNumber("Enter the year");
    cout << "Numebr of Dayes   : " << NumberOfDayesInYear(year) << endl;
    cout << "Numebr of Hours   : " << NumberOfHoursInYear(year) << endl;
    cout << "Numebr of Minutes : " << NumberOfMinutesInYear(year) << endl;
    cout << "Numebr of Seconds : " << NumberOfSecondsInYear(year) << endl;




    return 0;
}

