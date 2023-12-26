#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Time.h"

using namespace std;

class Task {
    friend ostream& operator<<(ostream&, const Task&);
    public:
        Task();
        Task(const string& name, const string& desc, const Date& date, Time& time);
        ~Task();
        // may need a copy constructor

        const string& getName() const;
        const string& getDescription() const;
        const string& getDueDate() const;
        const string& getDeadline() const;

        void setName(const string&);
        void setDescription(const string&);
        void setDueDate(const Date&);
        void setDeadline(const Time&);

        void print(ostream&) const;
        // saveTask to exernal file
        // loadTask from external file

    private:
        string taskName;
        string taskDescription;
        Date dueDate;
        Time deadline;
};
#endif