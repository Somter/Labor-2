// Лаборторная №2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Date.h"	
using namespace std;	

int main()
{
	Date FirstDate(23, 7, 2022);		
	cout << "Firsy Date: \n";
	FirstDate.Print();	
	Date SecondDay(20, 5, 2022);
	cout << "Second Date: \b";	
	SecondDay.Print();	

	Date temp1(FirstDate);
	Date temp2(SecondDay);	

	cout << "First date: " << endl;
	cout << "-----------------------------\n\n";
	Date RezultFirstDay = ++FirstDate;
	cout << "#1 day + 1: \n"; 
	RezultFirstDay.Print();
	cout << "#2 day - 1: \n";	
	RezultFirstDay = --FirstDate;
	RezultFirstDay.Print();
	cout << "-----------------------------\n";

	cout << "Second date: " << endl;	
	cout << "-----------------------------\n\n";
	Date RezultSecondDay = ++SecondDay;
	cout << "#1 day + 1: \n";
	RezultSecondDay.Print();
	cout << "#2 day - 1: \n";
	RezultSecondDay = --SecondDay;	
	RezultSecondDay.Print();
	cout << "-----------------------------\n";

	int day = 5;		
	cout << "First date: " << endl;
	cout << "-----------------------------\n\n";	
	Date RezultOperationsFirstDate = FirstDate - day;		
	cout << "Date - colvo days: \n";
	RezultOperationsFirstDate.Print();	
	
	cout << "Second date: " << endl;
	cout << "-----------------------------\n\n";	
	Date RezultOperationsSecondDate = SecondDay - day;	
	cout << "Date - colvo days: \n";
	RezultOperationsFirstDate.Print();

	int plusDay = 21;	
	cout << "First date: " << endl;
	cout << "-----------------------------\n\n";	
	Date PlusDayFirstDate = FirstDate + plusDay;	
	cout << "Date + covo days: " << endl;	
	PlusDayFirstDate.Print();	

	cout << "Second date: " << endl;
	cout << "-----------------------------\n\n";
	Date PlusDaySecondDate = SecondDay + plusDay;	
	cout << "Date + colvo days: \n";
	PlusDaySecondDate.Print();	

	cout << "Date - Date: " << endl;	
	cout << "-----------------------------\n\n";	
	Date DateMInusDAte = FirstDate - SecondDay;		
	DateMInusDAte.Print();	

	cout << "First date: " << endl;
	cout << "-----------------------------\n\n";
	Date PlusRavnoDayFirstDate = FirstDate += plusDay;
	cout << "Date += covo days: " << endl;
	PlusRavnoDayFirstDate.Print();	

	cout << "Second date: " << endl;	
	cout << "-----------------------------\n\n";
	Date PlusRavnoDaySecondDate = SecondDay += plusDay;
	cout << "Date += covo days: " << endl;
	PlusRavnoDaySecondDate.Print();

	cout << "First date: " << endl;
	cout << "-----------------------------\n\n";
	Date MinusRavnoDayFirstDate = FirstDate -= day;	
	cout << "Date -= covo days: " << endl;
	MinusRavnoDayFirstDate.Print();	

	cout << "Second date: " << endl;
	cout << "-----------------------------\n\n";
	Date MinusRavnoDaySecondDate = SecondDay -= day;	
	cout << "Date -= covo days: " << endl;
	MinusRavnoDaySecondDate.Print();

	if (temp1 > temp2)
	{
		cout << "First date > Second Date" << endl;	
	}
	if (temp1 < temp2) 
	{
		cout << "First date < Second Date" << endl;
	}
	if (temp1 >= temp2) 
	{
		cout << "First date >= Second Date" << endl;
	}
	if (temp1 <= temp2)
	{
		cout << "First date <= Second Date" << endl;
	}
	if (temp1 == temp2)
	{
		cout << "First date == Second Date" << endl;
	}
	if (temp1 != temp2) 
	{
		cout << "First date != Second Date" << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
