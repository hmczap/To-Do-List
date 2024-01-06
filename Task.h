#ifndef TASK_H
#define TASK_H

#define HIGH_PRIORITY 10
#define MOD_PRIORITY 5
#define LOW_PRIORITY 0

#include <string>
#include <iostream>
#include <ostream>
#include <iomanip>
#include <curses.h>

using namespace std;

class Task {
    friend ostream& operator<<(ostream&, const Task&);
    public:
        //Task(const string& name, const string& desc, const Date& date, Time& time);
        Task(const string& = "Untitled", const string& = "New task", int = 0);
        Task(const Task&);
        //~Task();

        const string& getName() const;
        const string& getDescription() const;
        int getPriority() const;

        /* Setters */
        void setName(const string&);
        void setDescription(const string&);
        void setPriority(int);
        void reducePriority();  // user can use this to fine-tune the order of tasks

        //void print(ostream&) const;
        void printFull(ostream&) const;
        void printCondensed(ostream&) const;

        // void saveTask(); to exernal file
        // void loadTask(); from external file

        bool operator==(const Task&) const;

    private:
        string taskName;
        string taskDescription;
        int priority;
};
#endif
