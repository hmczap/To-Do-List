#include "View.h"

View::View(){
    //unneeded for now, since the TDLIST should exist...
    // maybe store the TDList on the heap???
}

View::~View(){
    //should this delete the contents of the lists?
}

void View::addUserTask(){
    char name[MAX_BUF];
    char description[MAX_BUF + 170];
    char p = '\0';
    int priority;

    cout<<endl;
    cout<<"Adding a new task to the list: "<<endl;
    cout<<endl;

    cout<<"Enter task name: ";
    do{
        cin.getline(name, MAX_BUF, '\n');
    } while (name[0] == '\n' || name[0] == '\r' || name[0] == '\0');
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout<<"Enter task description [OPTIONAL]: ";
    cin.getline(description, MAX_BUF + 170, '\n');
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout<<"Enter task priority ([H] High, [M] Moderate, [L] Low): ";
    p = cin.get();
    switch (p){
        case 'H':
            priority = HIGH_PRIORITY;
            break;
        case 'M':
            priority = MOD_PRIORITY;
            break;
        default:
            priority = LOW_PRIORITY;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    list.add(name, description, priority);
    cout<<endl;
}

void View::resolveTask(){
    char name[MAX_BUF];

    cout<<"Enter task name: ";
    do{
        cin.getline(name, MAX_BUF, '\n');
    } while (name[0] == '\n' || name[0] == '\r' || name[0] == '\0');

    list.resolveTask(name);
    cout<<endl;
}

void View::killTask(){
    char name[MAX_BUF];

    cout<<"Enter task name: ";
    do{
        cin.getline(name, MAX_BUF, '\n');
    } while (name[0] == '\n' || name[0] == '\r' || name[0] == '\0');

    list.killTask(name);
    cout<<endl;
}

void View::printMenu() const{
    cout<<"----- Menu -----"<<endl;
    cout<<"  0: Exit"<<endl;
    cout<<"  1: View the list of pending tasks"<<endl;
    cout<<"  2: View the list of resolved tasks"<<endl;
    cout<<"  3: Add a task to your to-do list"<<endl;
    cout<<"  4: Resolve a completed task"<<endl;
    cout<<"  5: Remove a task from the to-do list"<<endl;
    cout<<"  6: About this application"<<endl;
    cout<<"  7: DEBUG text colour options"<<endl;
    cout<<endl;
    cout<<"Enter your selection: ";
}


//void View::printToDoList() const{}         ///////

void View::printPendingTasks() const{
    this->list.printPendingTasks();
}

void View::printResolvedTasks() const{
    this->list.printResolvedTasks();
}

void View::printSettings() const{}         ///////


void View::printAbout() const{
    ifstream aboutFile;
    aboutFile.open("data/about.txt"); 
    string line;
    char selection;

    if (!aboutFile){
        cout<<"Error: about data is missing!"<<endl;
        return;
        //exit(1);
    }

    cout<<endl;
    while (!aboutFile.eof()) {
        //if (!getline(aboutFile, line)) {break;}

        getline(aboutFile, line);
        cout<<line<<endl;
    }
    cout<<endl;
    aboutFile.close();

    // clear characters from the input stream;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<"Press [ENTER] to return to menu"<<endl;
    cin.get();
}

void View::printColours() const{
    //int col;

    for (int i = 1; i < 256; ++i){
        string v = "\033[38;5;";
        cout<<v+to_string(i)+"m"<<i<<"\033[0m"<<" ";
        if (i%20 == 0){
            cout<<endl;
        }
    }
    cout<<"\n"<<endl;
    //cout<<"Select the desired text colour: ";
}

