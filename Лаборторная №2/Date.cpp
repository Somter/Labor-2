#include "Date.h"
#include <iostream>	
using namespace std;	
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;	
}
	
Date::Date(int day, int month, int year)
{
	this->day = day;	
	this->month = month;	
	this->year = year;	
}

Date& Date::operator++()
{	
	if ((month % 2) == 0 && month != 2)		 
	{
		if (day > 0 && day <= 29) 
		{
			day += 1;	
		}
	}
	else if((month % 2) != 0 && month != 2)	
	{
		if (day > 0 && day <= 30)	
		{
			day += 1;			
		}	
	}
	if (month == 2) 
	{
		if (day > 0 && day <= 28)
		{
			day += 1;
		}
	}
	return *this;	
}

Date& Date::operator--()
{

	if ((month % 2) == 0 && month != 2)
	{
		if (day > 1 && day <= 30)	
		{
			day -= 1;
		}
	}
	else if ((month % 2) != 0 && month != 2)
	{
		if (day > 1 && day <= 31)
		{
			day -= 1;
		}
	}
	if (month == 2)
	{
		if (day > 1 && day <= 29)
		{
			day -= 1;
		}
	}
	return *this;	
}

Date Date::operator-(int MinusDay)	
{
	if (MinusDay < 0)
	{
		MinusDay = 0;
	}
	Date result = *this;
	while (MinusDay > 0)
	{
		if (result.day > MinusDay)
		{
			result.day = result.day - MinusDay;
			MinusDay = 0;
		}
		else
		{
			if (result.month == 1)
			{
				result.year--;
				result.month = 12;
			}
			else
			{
				result.month--;
			}
			int daysInMonth = 31;
			if (result.month == 4 || result.month == 6 || result.month == 9 || result.month == 11)
			{
				daysInMonth = 30;
			}
			else if (result.month == 2)
			{
				daysInMonth = 28; 
			}

			if (MinusDay >= daysInMonth)
			{
				MinusDay = MinusDay - daysInMonth;	
			}
			else
			{
				result.day = MinusDay;	
				MinusDay = 0;	
			}
		}
	}
	return result;
}

Date Date::operator+(int PlusDay)
{
	if (PlusDay < 0)
	{
		PlusDay = 0;
	}
	Date result = *this;
	while (PlusDay > 0)
	{
		int daysInMonth = 31; 

		if (result.month == 4 || result.month == 6 || result.month == 9 || result.month == 11)
		{
			daysInMonth = 30; 
		}
		else if (result.month == 2)
		{
			daysInMonth = 28;
		}

		if (result.day + PlusDay <= daysInMonth)
		{
			result.day = result.day + PlusDay;
			PlusDay = 0;	
		}
		else
		{
			PlusDay = PlusDay - (daysInMonth - result.day + 1);	
			result.day = 1;

			if (result.month == 12)
			{
				result.month = 1;
				result.year++;
			}
			else
			{
				result.month++;
			}
		}
	}
	return result;
}

Date& Date::operator-(Date SecDate)	
{
	while (SecDate.year < year || (SecDate.year == year && SecDate.month < month) || 
		(SecDate.year == year && SecDate.month == month && SecDate.day < day))
	{
		int daysInMonth = 31;

		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			daysInMonth = 30;
		}
		else if (month == 2)
		{
			daysInMonth = 28;
		}

		if (day > 1)
		{
			day--;
		}
		else
		{
			if (month == 1)
			{
				year--;
				month = 12;
			}
			else
			{
				month--;
			}
			day = daysInMonth;
		}

		SecDate.day--;
	}
	return *this;	
}

Date& Date::operator+=(int PlusDay)
{
	if (PlusDay <= 0)
	{
		return *this; // Не делаем ничего, если PlusDay <= 0
	}

	while (PlusDay > 0)
	{
		int daysInMonth = 31;

		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			daysInMonth = 30;
		}
		else if (month == 2)
		{
			daysInMonth = 28;
		}

		if (day + PlusDay <= daysInMonth)
		{
			day += PlusDay;
			PlusDay = 0;
		}
		else
		{
			PlusDay -= (daysInMonth - day + 1);
			day = 1;

			if (month == 12)
			{
				month = 1;
				year++;
			}
			else
			{
				month++;	
			}
		}
	}
	return *this;
}

Date& Date::operator-=(int MinusDay)
{
	if (MinusDay < 0)
	{
		MinusDay = 0;
	}
	Date result = *this;
	while (MinusDay > 0)
	{
		if (result.day > MinusDay)
		{
			result.day -= MinusDay;
			MinusDay = 0;
		}
		else
		{
			if (result.month == 1)
			{
				result.year--;
				result.month = 12;
			}
			else
			{
				result.month--;
			}
			int daysInMonth = 31;
			if (result.month == 4 || result.month == 6 || result.month == 9 || result.month == 11)
			{
				daysInMonth = 30;
			}
			else if (result.month == 2)
			{
				daysInMonth = 28;
			}

			if (MinusDay >= daysInMonth)
			{
				MinusDay -= daysInMonth;
			}
			else
			{
				result.day = MinusDay;
				MinusDay = 0;
			}
		}
	}
	return result;
}

bool Date::operator>(Date& secd)
{
	if (year > secd.year) {
		return true;
	}
	else if (year < secd.year) {
		return false;
	}
	if (month > secd.month) {
		return true;
	}
	else if (month < secd.month) {
		return false;
	}
	return day > secd.day;	
}

bool Date::operator<(Date& secd)
{
	if (year < secd.year) {
		return true;
	}
	else if (year > secd.year) {
		return false;
	}
	if (month < secd.month) {
		return true;
	}
	else if (month > secd.month) {
		return false;
	}
	return day < secd.day;
}

bool Date::operator>=(Date& secd)
{
	if (year >= secd.year) {
		return true;
	}
	else if (year < secd.year) {
		return false;
	}
	if (month >= secd.month) {
		return true;
	}
	else if (month < secd.month) {
		return false;
	}
	return day >= secd.day;
}

bool Date::operator<=(Date& secd)
{
	if (year <= secd.year) {
		return true;
	}
	else if (year > secd.year) {
		return false;
	}
	if (month <= secd.month) {
		return true;
	}
	else if (month > secd.month) {
		return false;
	}
	return day <= secd.day;
}

bool Date::operator==(Date& secd)
{
	if (year == secd.year && month == secd.month && day == secd.day) {
		return true;
	}
	return false;	
}

bool Date::operator!=(Date& secd)
{
	return year != secd.year || month != secd.month || day != secd.day;
}

void Date::SetDay()
{

}

void Date::SetMonth()
{

}

void Date::SetYear()
{
}

int Date::GetDay()
{
	return 0;
}

int Date::GetMonth()
{
	return 0;
}

int Date::GetYear()
{
	return 0;
}

void Date::Print() const	
{	
	cout << "Day: " << day << endl;	
	cout << "Month: " << month << endl;	
	cout << "Year: " << year << endl;	
	cout << "\n";	

}
