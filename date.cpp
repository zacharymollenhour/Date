//
//*************************************************************
//*************************************************************
// * Name: Date.cpp					      *
// * Class: COP3330					      *
// * Description: Cpp file for date class that checks dates   *
// * To see if its a valid date or not                        *
// * Author: Zachary Mollenhour                               *
// * Date: May 27th, 2020				      *
//*************************************************************
#include "date.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;




// helper function to return whether 
// the year is leap or not	      



bool Date::isLeapYear() const
{
   return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
}

// helper function to return 
// the number of days in the month
int Date::days_in_month() const
{
   if(month == 2)
   {
       if(isLeapYear())
           return 29;
       else
           return 28;
   }else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month ==10 || month==12)
       return 31;
   else
       return 30;

}

// function to get the inputed 
// date from the user
void Date::Input()
{
   // variable declaration
   int m,d,y;
   char sep;
   
   // input of date
   cout<<"Enter date:";
   cin>>m>>sep>>d>>sep>>y;
   
   // loop that continues till the user enters a valid date
   while(!Set(m,d,y))
   {
       cout<<"Invalid date. Try again: " << endl;
       cin>>m>>sep>>d>>sep>>y;
   }
}

// function to display the 
// date in the format specified
void Date::Show()
{
   //Default
   if(format == 'D')
   {
       cout<<month<<"/"<<day<<"/"<<year <<endl;
   }
   //Two Digit
   else if(format == 'T')
   {
       cout<<setw(2)<<setfill('0')<<month<<"/"<<setw(2)<<setfill('0')<<day<<"/"<<setw(2)<<setfill('0')<<(year%100)<<endl;
   }
   //Long Format
   else if(format == 'L')
   {
       switch(month)
       {
       case 1:
           cout<<"January";
           break;
       case 2:
           cout<<"February";
           break;
       case 3:
           cout<<"March";
           break;
       case 4:
           cout<<"April";
           break;
       case 5:
           cout<<"May";
           break;
       case 6:
           cout<<"June";
           break;
       case 7:
           cout<<"July";
           break;
       case 8:
           cout<<"August";
           break;
       case 9:
           cout<<"September";
           break;
       case 10:
           cout<<"October";
           break;
       case 11:
           cout<<"November";
           break;
       case 12:
           cout<<"December";
           break;
       }

       cout<<" "<<day<<", "<<year << endl;
   }
}

// method to validate the passed arguments 
// and set the date if the arguments 
// represent a valid date
bool Date::Set(int m, int d, int y)
{
   if(y > 1582)
   {
       //Check month against various month values to see if valid
       if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
       {
           if(d < 1 || d > 31)
               return false;
           else
           {
               day = d;
               month = m;
               year = y;
               return true;
           }
       }
       else if(m == 4 || m == 6 || m == 9 || m == 11)
       {
           if(d < 1 || d > 30)
               return false;
           else
           {
               day = d;
               month = m;
               year = y;
               return true;
           }
       }
       else if(m == 2)
       {
           if((y%400 == 0 ) || ((y%4 == 0) && (y%100) != 0))
           {
               if(d < 1 || d > 29)
                   return false;
               else
               {
                   day = d;
                   month = m;
                   year = y;
                   return true;
               }
           }else
           {
               if(d < 1 || d > 28)
                   return false;
               else{
                   day = d;
                   month = m;
                   year = y;
                   return true;
               }
           }
       }else
           return false;
   }
   else if(y == 1582)
   {
       if(m >= 10)
       {
           if(m == 10 || m == 12)
           {
               if(d < 1 || d > 31)
                   return false;
               else
               {
                   day = d;
                   month = m;
                   year = y;
                   return true;
               }
           }
           else if( m == 11)
           {
               if(d < 1 || d > 30)
                   return false;
               else
               {
                   day = d;
                   month = m;
                   year = y;
                   return true;
               }
           }
           else
               return false;
       }
   }

   return false;
}

// function to return the month value
int Date::GetMonth() const
{
   return month;
}

// function to return the day value
int Date::GetDay() const
{
   return day;
}

// function to return the year value
int Date::GetYear() const
{
   return year;
}

// function to set the format of the date for output
bool Date::SetFormat(char f)
{
   if(f == 'D' || f == 'T' || f == 'L')
   {
       format = f;
       return true;
   }

   return false;

}

// function to increment the number of days passed to the date and update the date
void Date::Increment(int numDays)
{
   //Add number of days that have passed
   day += numDays;

   // loop that continues till the date is valid
   while(day > days_in_month())
   {
       day -= days_in_month();
       month++;

       if(month > 12) // if month > 12, i.e it represents the first month of next year
       {
           // increment year and set month to 1
           year++;
           month = 1;
       }
   }
}

// function to compare the passed date with this date and return
// -1, if the calling object comes first chronologically
// 0, if the calling object comes first chronologically
// 1, if the objects are the same date

int Date::Compare(const Date& d)
{
   if(year < d.year)
       return -1;
   else if(year > d.year)
       return 1;
   else
   {
       if(month < d.month)
           return -1;
       else if(month > d.month)
           return 1;
       else
       {
           if(day < d.day)
               return -1;
           else if(day > d.day)
               return 1;
           else
               return 0;
       }
   }
}

// function to print the julian date
void Date::printJulianDate()
{
   int days=0;

   // loop to get the day number
   for(int i=1;i<month;i++)
   {
       switch(i)
       {
       case 1:
           days += 31;
           break;
       case 2:
           if(isLeapYear())
               days += 29;
           else
               days += 28;
           break;
       case 3:
           days += 31;
           break;
       case 4:
           days += 30;
           break;
       case 5:
           days += 31;
           break;
       case 6:
           days += 30;
           break;
       case 7:
           days += 31;
           break;
       case 8:
           days += 31;
           break;
       case 9:
           days += 30;
           break;
       case 10:
           days += 31;
           break;
       case 11:
           days += 30;
           break;
       case 12:
           days += 31;
           break;
       }

   }
   days += day;
   cout<<days<<","<<setw(4)<<setfill('0')<<year<<endl;
}
