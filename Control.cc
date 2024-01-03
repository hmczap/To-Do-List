#include "Control.h"

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
    task1->printFull(cout);
    task2->printFull(cout);
    task3->printFull(cout);
    task4->printFull(cout);

    cout<<"Changing Task 1: "<<endl;
    task1->setName("XXXXX");
    task1->setDescription("XXXXX");
    task1->setPriority(20);
    cout<<endl;

    cout<<"Testing print function"<<endl;
    task1->printFull(cout);
    task2->printFull(cout);
    task3->printFull(cout);
    task4->printFull(cout);

    delete task1;
    delete task2;
    delete task3;
    delete task4;
}

void Control::launch(){

    loadUserSettings();
    //loadViews();
    
    int l = 1;
    int userInput;

    while (l){
        view.printMenu();

        cin>>userInput;

        cout<<endl;
        switch (userInput) {
            case 0:
                l = 0; 
                break;
            case 1:
                view.printPendingTasks();
                break;
            case 2:
                view.printResolvedTasks();
                break;
            case 3:
                view.addUserTask();
                break;
            case 4: 
                view.resolveTask();
                break; 
            case 5:
                view.killTask();
                break;
            case 6:
                view.printAbout();
                break;   
            case 7:
                cout<<"[DEV] The following are possible colour codes that the user may select:"<<endl;    
                view.printColours();
            default:
                break;
        }
    }
}

void Control::loadUserSettings(){
    // read in user settings file
    // stored user color preferences
    //view.taskColour = "211";
}

void changeUserSettings(){
    // open and print contents of user settings file
    // store the current choices for each one
    // allow user to change task text colour, change task display mode, or exit
    // if user selects any option, store the choice in the local variables
    // write to the settings file on exit
}


