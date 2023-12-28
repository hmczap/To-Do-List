#include <iostream>
#include <exception>
#include "View.h"
//#include "Control.h"
#include "Task.h"
#include "TDList.h"

using namespace std;

void testTask(){
    Task* task1 = new Task("name1", "desc1", 3);
    Task* task2 = new Task("name2", "desc2", 2);
    Task* task3 = new Task("name3", "desc3", 1);
    Task* task4 = new Task(*task1);

    cout<<"Task 1: "<<endl;
    cout<<task1->getName()<<endl;
    cout<<task1->getDescription()<<endl;
    cout<<task1->getPriority()<<endl;
    cout<<endl;
    cout<<"Task 4: "<<endl;
    cout<<task4->getName()<<endl;
    cout<<task4->getDescription()<<endl;
    cout<<task4->getPriority()<<endl;
    cout<<endl;

    cout<<"Testing print function"<<endl;
    task1->print(cout);
    task2->print(cout);
    task3->print(cout);
    task4->print(cout);

    cout<<"Changing Task 1: "<<endl;
    task1->setName("XXXXX");
    task1->setDescription("XXXXX");
    task1->setPriority(20);
    cout<<endl;

    cout<<"Testing print function"<<endl;
    task1->print(cout);
    task2->print(cout);
    task3->print(cout);
    task4->print(cout);

    delete task1;
    delete task2;
    delete task3;
    delete task4;
}

int main(){

    /*
    Controller control;
    control.launch();
    */
    
    int l = 1;
    int userInput;

    View* view = new View();

    /* Test code for a Task *////////////////
    //testTask();
    TDList list;
    /*Task* task1 = new Task("name1", "desc1", 3);
    Task* task2 = new Task("name2", "desc2", 2);
    Task* task3 = new Task("name3", "desc3", 1);
    Task* task4 = nullptr;
    Task* tasks[3] = {task3, task2, task1};
    for (int i = 0; i < 3; ++i){
        list.add(*tasks[i]);
        cout<<"Number of tasks on the list: "<<list.getSize()<<endl;
    }*/
    ////////////////////////

    while (l){
        view->printMenu();

        cin>>userInput;
        
        switch (userInput) {
            case 0:
                l = 0; 
                break;
            case 1:
                // view to do list
                list.printPendingTasks();
                break;
            case 2:
                // add a task
                view->addUserTask(list);
                break;
            case 3: 
                //  remove a task
                cout<<"debug: removing from the list"<<endl;
                break; 
            case 4:
                cout<<"debug: printing about app"<<endl;
                view->printAbout();
                break;       
            default:
                break;
        }
    }
    /*delete task1;
    delete task2;
    delete task3;
    if (task4 != nullptr) {delete task4;}*/
    delete view;// do i need to do this?
    return 0;
}