#include "View.h"

View::View(){
    //unneeded for now, since the TDLIST should exist...
    // maybe store the TDList on the heap???
    taskMode = 1;
    taskColour = "211";
}

View::~View(){
    //should this delete the contents of the lists?
}

void View::addUserTask(WINDOW* in, WINDOW* out){
    clear();
    refresh();

    char name[MAX_BUF];
    char description[MAX_BUF + 170];
    char p = '\0';
    int priority;

    int x = 0;
    int y = 1;

    //cout<<endl;
    mvprintw(y, x, "Adding a new task to the list: \n");
    y+=2;
    //cout<<endl;

    mvprintw(y++, x, "Enter task name: ");
    refresh();
    do{
        cin.getline(name, MAX_BUF, '\n');
    } while (name[0] == '\n' || name[0] == '\r' || name[0] == '\0');
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    mvprintw(y++, x, "Enter task description [OPTIONAL]: ");
    refresh();
    cin.getline(description, MAX_BUF + 170, '\n');
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    mvprintw(y++, x, "Enter task priority ([H] High, [M] Moderate, [L] Low): ");
    refresh();
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
    //cout<<endl;
}

void View::addUserTask(const string& name, const string& description, int priority){
    list.add(name, description, priority);
}


void View::resolveTask(WINDOW* in, WINDOW* out){
    char name[MAX_BUF];

    cout<<"Enter task name: ";
    do{
        cin.getline(name, MAX_BUF, '\n');
    } while (name[0] == '\n' || name[0] == '\r' || name[0] == '\0');

    list.resolveTask(name);
    cout<<endl;
}

void View::killTask(WINDOW* in, WINDOW* out){
    char name[MAX_BUF];

    cout<<"Enter task name: ";
    do{
        cin.getline(name, MAX_BUF, '\n');
    } while (name[0] == '\n' || name[0] == '\r' || name[0] == '\0');

    list.killTask(name);
    cout<<endl;
}

void View::printMenu(WINDOW* win) const{
    int y, x;
    getmaxyx(win, y, x);
    //mvprintw(endl;
    mvwprintw(win,1, x/2-8, "----- Menu -----");
    mvwprintw(win,4, 75, "0: Exit");
    mvwprintw(win,3, 1, "1: View pending tasks");
    mvwprintw(win,4, 1, "2: View resolved tasks");
    mvwprintw(win,3, 25, "3: Add a task");
    mvwprintw(win,4, 25, "4: Resolve a task");
    mvwprintw(win,3, 50, "5: Remove a task");
    mvwprintw(win,4, 50, "6: About");
    mvwprintw(win,3, 75, "7: DEBUG options");
    //mvprintw(;
    //mvprintw(y++, x, "Enter your selection: ");
    refresh();
}

void View::printMenu() const{
    int y = 10;
    int x = 3;
    //mvprintw(endl;
    mvprintw(y++, x, "----- Menu -----");
    mvprintw(y++, x, "  0: Exit");
    mvprintw(y++, x, "  1: View the list of pending tasks");
    mvprintw(y++, x, "  2: View the list of resolved tasks");
    mvprintw(y++, x, "  3: Add a task to your to-do list");
    mvprintw(y++, x, "  4: Resolve a completed task");
    mvprintw(y++, x, "  5: Remove a task from the to-do list");
    mvprintw(y++, x, "  6: About this application");
    mvprintw(y++, x, "  7: DEBUG text colour options");
    //mvprintw(;
    mvprintw(y++, x, "Enter your selection: ");
    refresh();
}

void View::printSettingsMenu() const{} //////////////

void View::printPendingTasks(WINDOW* out) const{
    clear();
    refresh();    

    cout<<"\033[38;5;"+taskColour+"m";
    this->list.printPendingTasks();
    cout<<"\033[0m";

    getch();
    refresh();
    //wrefresh(out);
}

void View::printResolvedTasks(WINDOW* out) const{
    clear();
    refresh();

    cout<<"\033[38;5;"+taskColour+"m";
    this->list.printResolvedTasks();
    cout<<"\033[0m";

    getch();
    refresh();
}

void View::printSettings() const{}         ///////

void View::printAbout() const{
    ifstream aboutFile;
    aboutFile.open("data/about.txt"); 
    string line;
    int y = 1;
    char selection;
    
    clear();
    refresh();

    if (!aboutFile){
        printw("Error: about data is missing!");
        refresh();
        return;
        //exit(1);
    }

    cout<<endl;
    while (!aboutFile.eof()) {
        //if (!getline(aboutFile, line)) {break;}

        getline(aboutFile, line);
        //cout<<line<<endl;
        mvprintw(y++, 0, "%s\n", line.data());
        refresh();
    }
    //cout<<endl;
    aboutFile.close();

    // clear characters from the input stream;
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<"Press any key to return to menu"<<endl;
    //cin.get();
    getch();
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
    /*cout<<"Select the desired text colour: ";
    cin.getline(input, 3, '\n');
    if (atoi(input) > 0 && atoi(input) < 256){
        cout<<input<<endl;
        cout<<taskColour<<endl;
        //this->taskColour = input;
    }*/
}

void setTaskColour(){

}

void setTaskMode(){

}

