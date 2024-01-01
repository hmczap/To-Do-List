#ifndef TDLIST_H
#define TDLIST_H

#define MAX_SIZE 265

//#include <iostream>
//#include <string>
//#include <iomanip>
//#include <cstdlib>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Task.h"

using namespace std;

// store tasks in order of reverse priority.
// I would expect users to add tasks arbitrarily, and most likely remove tasks
// in order of decreasing priority 

// it is easiest to remove from the back, so store higher priority tasks
// at the end. 

// in the future, perhaps switch to a new DS (deque).
// i would rather make this functional for now, especially since the to do list is 
// limited in size and will probably not see much difference between the DS at 
// such a small scale

class TDList{
    //friend bool compare(const Task&, const Task&);
    friend bool compare(unique_ptr<Task>&, unique_ptr<Task>&);
    public:
        TDList();
        //TDList(const TDList&) = delete;
        //TDList& operator=(const TDList&) = delete;
        ~TDList();

        // add task to the list of pending tasks
        void add(Task&);
        //void add(const string& name, const string& desc, const Date& date, Time& time);
        void add(const string& name, const string& desc, int p);

        // remove task from pending list, add to list of resolved tasks
        //void resolveTask(Task&);
        void resolveTask(const string& name);

        // remove task from pending list, but do not resolve it
        //void killTask(Task&);
        void killTask(const string& name);

        bool findTask(const string&, vector<unique_ptr<Task>>::iterator&);

        void printPendingTasks() const;
        void printResolvedTasks() const;

        // size of pending tasks
		int getSize() const;

        // is the list of pending tasks full?
		bool isFull() const;

    private:
        vector<unique_ptr<Task>> pendingTasks;
        vector<unique_ptr<Task>> resolvedTasks;
        int numTasks;

        // remove task from pending list and return a ptr to it
        //Task* remove(const Task&);
        unique_ptr<Task> remove(vector<unique_ptr<Task>>::iterator&);
};
#endif