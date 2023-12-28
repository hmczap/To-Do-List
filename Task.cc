#include "Task.h"

ostream& operator<<(ostream& ost, const Task& t){
    t.print(ost);
    return ost;
}

//bool compare(const Task& t1, const Task& t2){return t1.priority <= t2.priority;}

/*Task::Task(){
    taskName = "New task";
    taskDescription = ""

    //dueDate = Date();
    //deadline = Time();
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

/*const Date& Task::getDueDate() const{
    return dueDate;
}*/

/*const Time& Task::getDeadline() const{
    return deadline;
}*/

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


/*void Task::setDueDate(const Date& d){
    dueDate = Date(d);
}*/

/*void Task::setDeadline(const Time& t){
    deadline = Time(t);
}*/

void Task::print(ostream& ost) const{
    cout<<" -----------------------------------------"<<endl;
    cout<<"|    "<<taskName<<endl;
    cout<<"|    "<<taskDescription<<endl;
    //cout<<"|    Due: "<<dueDate<<" at "<<deadline<<endl;;
    cout<<"|    [DEBUG] Priority: "<<priority<<endl;
    cout<<" -----------------------------------------"<<endl;

}