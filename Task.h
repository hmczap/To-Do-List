#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
#include "Date.h"

using namespace std;

class Task {
    public:
        Task();
        ~Task();

        const string& getName();
        const string& getDescription();
        getStartDate();
        getEndDate();

        setName();
        setDescription();
        setStartDate();
        setEndDate();

        //Task getTask() const;
        //bool addTask();
        //bool killTask();
        //bool resolveTask();
        // saveTask to exernal file
        // loadTask from external file

        // then write menu loop and 

    private:
        string name;
        string description;
        Date startDate
        Date endDate;
};
#endif