#include "Task.h"

ostream& Task::operator<<(ostream& ost, const Task& t){
    t.print(ost);
    return ost;
}

Task::Task(){
    taskName = "New task";
    taskDescription = ""
    //dueDate = Date();
    //deadline = Time();
}

Task::Task(const string& name, const string& desc, const Date& date, Time& time);

Task::~Task();

const string& Task::getName() const{
    return taskName;
}

const string& Task::getDescription() const{
    return taskDescription;
}

const Date& Task::getDueDate() const{
    return dueDate;
}

const Time& Task::getDeadline() const{
    return deadline;
}


void Task::setName(const string& name){
    taskName = name;
}

void Task::setDescription(const string& desc){
    taskDescription = desc;
}

void Task::setDueDate(const Date& d){
    dueDate = Date(d);
}

void Task::setDeadline(const Time& t){
    deadline = Time(t);
}

void Task::print(ostream& ost) const{
    cout<<" -----------------------------------------"<<endl;
    cout<<"|    "<<taskName<<endl;
    cout<<"|    "<<taskDescription<<endl;
    cout<<"|    Due: "<<dueDate<<" at "<<deadline<<endl;;
    cout<<" -----------------------------------------"<<endl;

}