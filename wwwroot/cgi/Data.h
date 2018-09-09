#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <string>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	Date(const Date& d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
	}
	~Date()
	{
		;
	}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}
		return *this;
	}
	void Print_Date();
	int GetMonthDay(int year, int month);
	bool CheckLegality();
	Date& operator+=(int day);    //求某个日期day天后的日期是哪一天
	Date& operator-=(int day);	  //求某个日期day天前的日期是哪一天
	bool operator>(const Date& d);
	bool operator==(const Date& d);

	

	Date& operator++();           //前置++

	int operator-(const Date& d); //求两个日期相差多少天

public:
	int _year;
	int _month;
	int _day;
};
