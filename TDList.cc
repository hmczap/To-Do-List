#include "TDList.h"

TDList::TDList(){
    numTasks = 0;
}

TDList::~TDList(){
    // may need this for later if I decide to employ a factory or something
    // the TDList is currently responsible for destroying its own tasks
    //Task* current = nullptr;
    /*while(numTasks > 0){
        killTask(pendingTasks[0]);
    }
    while(resolvedTasks.size() > 0){
        //current = resolvedTasks.back();
        resolvedTasks.pop_back();
        //delete current;
    }*/
}

bool compare(const Task& t1, const Task& t2){
    return t1.priority <= t2.priority;
}

void TDList::add(Task& t){
    pendingTasks.push_back(t);
    numTasks++;
    sort(pendingTasks.begin(), pendingTasks.end(), compare);
}

void TDList::add(const string& name, const string& desc, int p){
    //const Date& date, Time& time
    pendingTasks.push_back(Task(name, desc, p));
    numTasks++;
    sort(pendingTasks.begin(), pendingTasks.end(), compare);
    //add(*newTask);
}

// remove task from pending list, add to list of resolved tasks
void TDList::resolveTask(Task& t){
    //not implemented
}

void TDList::resolveTask(const string& name){
    //not implemented
}

// remove task from pending list, but do not resolve it
void TDList::killTask(Task& t){
    // not implemented
}

/*void TDList::killTask(const string& name){
    if (remove(name) == nullptr){
        cout<<"Unable to kill task: task '"<<name<<"' could not be located"<<endl;
        return;
    }
    // delete the task
    --numTasks;
}*/

bool TDList::findTask(const string& name, vector<Task>::iterator& taskIt){
    vector<Task>::iterator it;
    //int location = numTasks - 1;
    
    for (it = pendingTasks.begin(); it != pendingTasks.end(); ++it) {
        if ((*it).getName() == name){
            taskIt = it;
            //break;
            return true;
        }
        //location--;
    }
    //return location;
    return false;
}

// size of pending tasks
int TDList::getSize() const{
    return numTasks;
}

// is the list of pending tasks full?
bool TDList::isFull() const{
    return MAX_SIZE == numTasks;
}

void TDList::printPendingTasks() const{
    //vector<Task>::iterator rit;
    for (auto rit = pendingTasks.rbegin(); rit != pendingTasks.rend(); ++rit){
        (*rit).print(cout);
        cout<<endl;
    }
}

void TDList::printResolvedTasks() const{
    //vector<Task>::iterator rit;
    for (auto rit = resolvedTasks.rbegin(); rit != resolvedTasks.rend(); ++rit){
        (*rit).print(cout);
        cout<<endl;
    }
}

//Task* remove(const Task& t){}

Task* TDList::remove(const string& name){
    Task* t = nullptr;
    vector<Task>::iterator it;

    //int location = findTask(name, it);
    //if (location > 0){
    if (!findTask(name, it)){
        t = &(*it);
        // (*it) is a task
        // t is a pointer to the task
        pendingTasks.erase(it);
    }
    return t;
}
