#ifndef DATE_H
#define DATE_H

#include <string>
#include <ostream>

class Date{
    friend ostream& operator<<(ostream&, const Date&);
    friend Date& operator+(const Date&);
    public:
        Date();
        Date(int, int, int, int, int, int);

        int getYear();
        int getMonth();
        int getDay();
        int getHour();
        int getMin();
        int getSec();

        void setYear(int);
        void setMonth(int);
        void setDay(int);
        void setHour(int);
        void setMin(int);
        void setSec(int)

        void printDate();
        void printTime();
        void printDateandTime();

    private:
        int year;
        int month;
        int day;

        int hour;
        int minute;
        int second;
};
#endif