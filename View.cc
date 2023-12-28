#include "View.h"

void View::addUserTask(TDList& list){
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


void View::printMenu() const{
    cout<<"----- Menu -----"<<endl;
    cout<<"  0: Exit"<<endl;
    cout<<"  1: View your to-do list"<<endl;
    cout<<"  2: Add a task"<<endl;
    cout<<"  3: Remove a task"<<endl;
    cout<<"  4: About this application"<<endl;
    cout<<endl;
    cout<<"Enter your selection: ";
}

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