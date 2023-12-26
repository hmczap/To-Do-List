#ifndef TDLIST_H
#define TDLIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Task.h"

using namespace std;

class TDList{
    public:
        TDList();
        ~TDList();

        void add(const Task&);
        void add(const string& name, const string& desc, const Date& date, Time& time);

        // remove task from pending list, add to list of resolved tasks
        void resolveTask(const Task&);
        void resolveTask(const string& name);

        // remove task from pending list, but do not resolve it
        void killTask(const Task&);
        void killTask(const string& name);

        const Task& getTask(const string& name) const;

        // size of pending tasks
		int getSize() const;

        // is the list of pending tasks full?
		bool isFull() const;

    private:
        vector<Task> pendingTasks;
        vector<Task> resolvedTasks;
        int numTasks;
};
#endif