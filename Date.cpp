#include "Date.h"

const int Date::days_in_a_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date() { day = 1; month = 1; year = 1900; }

Date::Date(int day_t, int month_t, int year_t) { day = day_t; month = month_t; year = year_t; }

Date::Date(Date& original) { this->day = original.day; this->month = original.month; this->year = original.year; }

int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }
void Date::getSeason(int& season) { season = (month / 3) % 4; }

int Date::getTotalDays()
{
	int leap_years = 0, total_days = day;
	bool year_is_leap = this->leapYear();

	if (year_is_leap && month > 2)
	{
		total_days++;
	}
	for (int i = 0; i < month - 1; i++)
	{
		total_days += days_in_a_month[i];
		if (this->leapYear() && i == 2) { total_days++; }
	}
	leap_years += year / 4 - year / 100 + year / 400; if (year_is_leap) leap_years--;
	total_days += leap_years * 366 + (year - leap_years) * 365;
	return total_days;

}

bool Date::leapYear()
{
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

string Date::getSeason()
{
	int season; getSeason(season);
	switch (season)
	{
	case 0:
		return "Зима";
	case 1:
		return "Весна";
	case 2:
		return "Літо";
	case 3:
		return "Осінь";
	}
}

void Date::fill()
{
	string s, s1;
	bool error;
	do
	{
		error = 0;

		cout << "Введіть дату у форматі День.Місяць.Рік: ";
		cin >> s; cin.ignore();

		int pos1 = s.find('.') + 1;
		int pos2 = s.find('.', pos1);

		s1 = s.substr(0, pos1 - 1); day = stoi(s1);

		s1 = s.substr(pos1, pos2 - pos1); month = stoi(s1);

		s1 = s.substr(pos2 + 1, s.size() - pos2); year = stoi(s1);

		error = this->check();

	} while (error);

}

bool Date::check()
{
	bool error = 0;
	if (month < 1 || month > 12)
	{
		cout << "Помилка. Значення місяця має бути не менше 1 і не більше 12. Будь ласка, спробуйте ввести ще раз" << endl;
		error = 1;
	}
	else if (month == 2 && day > 28)
	{

		if (this->leapYear() && day > 29)
		{
			cout << "Помилка. Максимальна кількість днів у лютому високосного року дорівнює 29." << endl;
			cout << "Будь ласка, спробуйте ввести ще раз" << endl;
			error = 1;
		}
		else if (!this->leapYear())
		{
			cout << "Помилка. Максимальна кількість днів у лютому звичайного року дорівнює 28." << endl;
			cout << "Будь ласка, спробуйте ввести ще раз" << endl;
			error = 1;
		}
	}
	else if (day > days_in_a_month[month - 1])
	{
		cout << "Помилка. Кількість днів перевищує максимальну, що дорівнює " << days_in_a_month[month - 1] << endl;
		cout << "Будь ласка, спробуйте ввести ще раз" << endl;
		error = 1;
	}
	return error;
}

Date Date::operator+=(int plus_days)
{

	while (plus_days >= 365)
	{
		if (this->leapYear() && month <= 2) plus_days -= 366;
		else plus_days -= 365;
		this->year = this->year + 1;
		if (this->leapYear() && month > 2) plus_days -= 1;
	}

	if (day + plus_days <= days_in_a_month[month - 1])
	{
		day += plus_days;
	}

	else
	{
		if (this->leapYear() && month == 2) { plus_days--; }
		plus_days -= days_in_a_month[month - 1] - day + 1; day = 1; month++;

		while (plus_days > days_in_a_month[month - 1])
		{
			plus_days -= days_in_a_month[month - 1];
			if (month + 1 > 12)
			{
				year++; month = 1;
			}
			else month++;

			if (this->leapYear() && month == 2) { plus_days--; }
		}
		day += plus_days;
	}

	return *this;
}

int Date::operator-(Date date)
{
	int days_difference = 0;
	days_difference = this->getTotalDays() - date.getTotalDays();
	return days_difference;
}

string Date::stringDate()
{
	string string_date;
	stringstream s1;
	s1 << day << "." << month << "." << year;
	s1 >> string_date;
	return string_date;
}