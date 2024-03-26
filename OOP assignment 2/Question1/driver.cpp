#include<iostream>
#include"date.h"

using namespace std;
int main()
{
    Date date1; 
    date1.print();
    //---------------------------------------
    Date independenceDay(14,8,2018);
    independenceDay.print();
    //date1.input();
    //-----------------------------------------
    date1.print();
    Date XmasDay;
    //--------------------------------------------
    XmasDay.setday(25).setMonth(12).setYear(2011).print();
    //-----------------------------------------
    cout<<XmasDay.getday()<<"/"<<XmasDay.getMonth()<<"/"<<XmasDay.getYear()<<"\n";
    //--------------------------------------
    cout<<XmasDay.compare(independenceDay);
    Date newDate;
    //--------------------------------
    newDate=date1.incrementMonth();
   newDate.print();
   date1.print();
    return 0;
}