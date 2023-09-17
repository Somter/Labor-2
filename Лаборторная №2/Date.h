#pragma once
class Date
{
private:
	int day;
	int month;
	int year;	
public:
	Date();	
	Date(int day, int month, int year);	
	Date& operator ++();					
	Date& operator --();	
	Date operator - (int MinusDay);
	Date operator + (int PlusDay);	
	Date& operator - (Date SecDate);	
	Date& operator += (int PlusDay);
	Date& operator-=(int MinusDay);
	bool operator > (Date& secd);	
	bool operator < (Date& secd);	
	bool operator >= (Date& secd);
	bool operator <= (Date& secd);
	bool operator == (Date& secd);
	bool operator != (Date& secd);

	void SetDay();
	int GetMonth();
	int GetYear();	
	void Print() const;	
	void SetMonth();
	void SetYear();
	int GetDay();
	
};
