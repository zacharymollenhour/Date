// date.h
//*************************************************************
//Name: date.h                                                *
//Author: Zachary Mollenhour                                  *
//Description: Header File for date.cpp assignment            *
//Date: May 28th, 2020                                        *
//							      *
//*************************************************************


#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date
{
	private:
   		int day, month, year;
   		char format;
   		bool isLeapYear() const;
   		int days_in_month() const;

	public:
   		Date(int month=1, int day=1, int year=2000)
		{
			Date::month=month;
			Date::day=day;
			Date::year=year;
		};
		void Input();
		void Show();
		bool Set(int m, int d, int y);
		int GetMonth() const;
		int GetDay() const;
		int GetYear() const;
		bool SetFormat(char f);
		void Increment(int numDays=1);
		int Compare(const Date& d);
		void printJulianDate();
};

#endif

//end of date.h file
