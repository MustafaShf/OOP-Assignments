#include "date.h"
#include<iostream>
Date::Date()
    {
        cout<<" Default constructer\n";
        Day=1;
        Month=1;
        Year=1926;
    };
    Date::Date(int Day,int Month,int Year)
    {
        this->Day=Day;
        this->Month=Month;
        this->Year=Year;
    }
    int Date::getday()
    {
        return Day;
    }
    int Date::getMonth()
    {
        return Month;
    }
    int Date::getYear()
    {
        return Year;
    }
    Date& Date::setday(int Day)
    {
        this->Day=Day;
        return *this;
    }
    Date& Date::setMonth(int Month)
    {
        this->Month=Month;
        return *this;
    }
    Date& Date::setYear(int Year)
    {
        this->Year=Year;
        return *this;
    }
    void Date::print()
    {
        cout<<Day<<"/"<<Month<<"/"<<Year<<"\n";
    }
    void Date::input()
    {
        cout<<"Enter Day: \n";
        cin>>Day;
        if(Day<1 || Day>31)
        {
            cout<<"Invalid Day Input\n";
            cout<<"Enter Day: \n";
            cin>>Day;
        }
        cout<<"Enter Month: \n";
        cin>>Month;
         if(Month<1 || Month>12)
        {
            cout<<"Invalid Month Input\n";
             cout<<"Enter Month: \n";
            cin>>Month;
        }
        cout<<"Enter Year: \n";
        cin>>Year;
        
    }
int Date::compare(Date obj)
{
    if (this->Year > obj.getYear()) return 1;
    else if (this->Year < obj.getYear()) return -1;
    else 
    {
        if (this->Month > obj.getMonth()) return 1;
        else if (this->Month < obj.getMonth()) return -1;
        else 
        {
            if (this->Day > obj.getday()) return 1;
            else if (this->Day < obj.getday()) return -1;
            else return 0; 
        }
    }
    return 0;
}
Date Date::incrementMonth()
{
    Date temp=(*this);
    temp.Month++;
    return temp;
}

     Date::~Date()
    {
         cout<<"destructer\n";
    };