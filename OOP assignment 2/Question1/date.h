#ifndef DATE_H
#define DATE_H

#include<iostream>

using namespace std;

class Date
{
private:
    int Day;
    int Month;
    int Year;
public:
    Date();
    Date(int Day,int Month,int Year);
    int getday();
    int getMonth();
    int getYear();
    Date& setday(int Day);
    Date& setMonth(int Month);
    Date& setYear(int Year);
    void print();
    void input();
    int compare(Date obj);
    Date incrementMonth();
    ~Date();
};
#endif

