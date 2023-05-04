#include <iostream>
#include <string>
#include <sstream> 
#include <windows.h>
#include <cmath>
using namespace std;

class Date
{
	int day, month, year;
	static const int days_in_a_month[12];

public:
	Date(int day_t, int month_t, int year_t);
	Date();
	Date(Date& original);
	int getDay();
	int getMonth();
	int getYear();
	void getSeason(int& season);

	string stringDate();
	bool leapYear();
	int getTotalDays();
	string getSeason();
	void fill();
	bool check();

	Date operator+=(int plus_days);
	int operator-(Date date);
};

