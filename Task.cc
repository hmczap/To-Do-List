#include "Task.h"

ostream& operator<<(ostream& ost, const Task& t){
    t.printFull(ost);
    return ost;
}

/*Task::Task(){
    taskName = "New task";
    taskDescription = ""
}*/

Task::Task(const string& name, const string& desc, int p):
    taskName(name), taskDescription(desc), priority(p) {}

Task::Task(const Task& t){
    //(this->taskName).string::assign(t.taskName);
    this->taskName = t.taskName;
    this->taskDescription = t.taskDescription;
    this->priority = t.priority;
}


//Task::~Task();

bool Task::operator==(const Task& t) const{
    return (taskName == t.taskName && 
            taskDescription == t.taskDescription && 
            priority == t.priority);
}

const string& Task::getName() const{
    return taskName;
}

const string& Task::getDescription() const{
    return taskDescription;
}

int Task::getPriority() const{
    return priority;
}

void Task::setName(const string& name){
    taskName = name;
}

void Task::setDescription(const string& desc){
    taskDescription = desc;
}

void Task::setPriority(int p){
    priority = p;
}

void Task::reducePriority(){
    setPriority(priority - 1);
}

void Task::printFull(ostream& ost) const{
    printw("%s\n", taskName.data());
    printw("%s\n", taskDescription.data());
    refresh();
    //ost<<"> "<<setw(48)<<left<<taskName<<endl;
    //ost<<"    "<<setw(48)<<left<<taskDescription<<endl;
    //ost<<"|    [DEBUG] Priority: "<<priority<<endl;
}

void Task::printCondensed(ostream& ost) const{
    printw("%s\n", taskName.data());
    refresh();
    //ost<<"> "<<setw(48)<<left<<taskName<<endl;
}
