#ifndef TASK_H
#define TASK_H

#define HIGH_PRIORITY 10
#define MOD_PRIORITY 5
#define LOW_PRIORITY 0

#include <string>
#include <iostream>
#include <ostream>
#include <iomanip>
//#include "Date.h"
//#include "Time.h"

using namespace std;

class Task {
    friend ostream& operator<<(ostream&, const Task&);
    friend bool compare(const Task&, const Task&);
    public:
        //Task(const string& name, const string& desc, const Date& date, Time& time);
        Task(const string& = "Untitled", const string& = "New task", int = 0);
        Task(const Task&);
        //~Task();

        const string& getName() const;
        const string& getDescription() const;
        int getPriority() const;
        //const string& getDueDate() const;
        //const string& getDeadline() const;

        /* Setters */
        void setName(const string&);
        void setDescription(const string&);
        void setPriority(int);
        void reducePriority();  // user can use this to fine-tune the order of tasks
        //void setDueDate(const Date&);
        //void setDeadline(const Time&);

        void print(ostream&) const;
        // saveTask to exernal file
        // loadTask from external file

        bool operator==(const Task&) const;

    private:
        string taskName;
        string taskDescription;
        int priority;
        //Date dueDate;
        //Time deadline;
};
#endif