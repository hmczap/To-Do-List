#include "TDList.h"

TDList::TDList(){
    numTasks = 0;
}

TDList::~TDList(){}

bool compare(unique_ptr<Task>& t1, unique_ptr<Task>& t2){
    return t1->getPriority() <= t2->getPriority();
}

void TDList::add(Task& t){
    pendingTasks.push_back(make_unique<Task>(t));
    numTasks++;
    sort(pendingTasks.begin(), pendingTasks.end(), compare);
}

void TDList::add(const string& name, const string& desc, int p){
    pendingTasks.push_back(make_unique<Task>(Task(name, desc, p)));
    numTasks++;
    sort(pendingTasks.begin(), pendingTasks.end(), compare);
}

void TDList::resolveTask(const string& name){
    vector<unique_ptr<Task>>::iterator it;

    if (!findTask(name, it)){
        printw("Unable to resolve task: '%s' could not be located", name.data());
        refresh();
        return;
    }
    unique_ptr<Task> removedTask = move(remove(it));
    --numTasks;
    resolvedTasks.push_back(move(removedTask));
    return;
}

void TDList::killTask(const string& name){
    vector<unique_ptr<Task>>::iterator it;
        // try to find the task. if no, then print err, do nothing

    if (!findTask(name, it)){
        printw("Unable to resolve task: '%s' could not be located", name.data());;
        refresh();
        return;
    }
    unique_ptr<Task> removedTask = move(remove(it));
    // delete the task
    --numTasks;
    return;
}

bool TDList::findTask(const string& name, vector<unique_ptr<Task>>::iterator& taskIt){
    vector<unique_ptr<Task>>::iterator it;
    
    for (it = pendingTasks.begin(); it != pendingTasks.end(); ++it) {
        if ((*it)->getName() == name){
            taskIt = it;
            return true;
        }
    }
    return false;
}

int TDList::getSize() const{
    return numTasks;
}

bool TDList::isFull() const{
    return MAX_SIZE == numTasks;
}

void TDList::printPendingTasks() const{
    string line(50, '_');
    printw("%s\n", line.data()); //cout<<line<<endl;
    refresh();
    for (auto rit = pendingTasks.rbegin(); rit != pendingTasks.rend(); ++rit){
        //cout<<endl;
        (*rit)->printFull(cout);
        refresh();
    }
    printw("%s\n", line.data());
    refresh();
}

void TDList::printResolvedTasks() const{
    string line(50, '_');
    printw("%s\n", line.data());
    refresh();
    for (auto rit = resolvedTasks.rbegin(); rit != resolvedTasks.rend(); ++rit){
        //cout<<endl;
        (*rit)->printFull(cout);
        refresh();
    }
    printw("%s\n", line.data());
    refresh();
}

unique_ptr<Task> TDList::remove(vector<unique_ptr<Task>>::iterator& taskIt){
    unique_ptr<Task> t = move(*taskIt);
    pendingTasks.erase(taskIt);
    return t;
}
