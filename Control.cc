#include "Control.h"

void Control::launch(){
    //loadUserSettings();
    initCurses();
    printHomepage();
    clear();

    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);

    WINDOW* inputWindow = newwin(3, xmax-12, ymax-5, 5);
    WINDOW* menuWindow = newwin(6, xmax-12, ymax-11, 5);
    WINDOW* outputWindow = newwin(ymax-13, xmax-12, 2, 5);   

    //loadViews();

    int l = 1;
    int userInput;

    while (l){
        box(inputWindow, 0, 0);
        box(menuWindow, 0, 0);
        box(outputWindow, 0, 0);

        mvwprintw(inputWindow, 1, 1, "Enter your selection: ");    //22 chars
        view.printMenu(menuWindow);
        refresh();

        wrefresh(menuWindow);
        wrefresh(outputWindow);
        wrefresh(inputWindow);

        userInput = wgetch(inputWindow); //doesn't directly work...
        //printw("%d", userInput);
        //cin>>userInput;
        //noecho();

        //cout<<endl;
        switch (userInput) {
            case '0':
                l = 0; 
                break;
            case '1':
                view.printPendingTasks(outputWindow);
                break;
            case '2':
                view.printResolvedTasks(outputWindow);
                break;
            case '3':
                view.addUserTask(inputWindow, outputWindow);
                break;
            case '4': 
                view.resolveTask(inputWindow, outputWindow);
                break; 
            case '5':
                view.killTask(inputWindow, outputWindow);
                break;
            case '6':
                view.printAbout();
                clear();
                break;   
            case '7':
                cout<<"[DEV] The following are possible colour codes that the user may select:"<<endl;    
                view.printColours();
            default:
                break;
        }
    }
    
    endwin();
}


void Control::initCurses(){
    initscr();
    cbreak();
    use_default_colors();
    noecho();
}

void Control::loadUserSettings(){
    // read in user settings file
    // stored user color preferences
    //view.taskColour = "211";
    ifstream userdata("user_data/user_settings.json");
    
    if (!userdata){
        cout<<"New session - no user data or settings restored"<<endl;
        return;
    }
    // load data from JSON or query the DB
    // call view->setTaskMode,and view->setTaskColour to modify the settings

    // iterate through the pending list, and call view.addUserTask(name, desc, priority) 
    // for each stored task.
}

void Control::changeUserSettings(){
    // open and print contents of user settings file
    // store the current choices for each one
    // allow user to change task text colour, change task display mode, or exit
    // if user selects any option, store the choice in the local variables
    // write to the settings file on exit
}


void Control::printHomepage(){
    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);

    //mvwprintw(win, 1, 1, "string here");
    mvprintw(ymax/2, xmax/3, "To-Do List");
    mvprintw(ymax/2 + 1, xmax/3, "Press any key to continue");
    getch();
}

void Control::loadViews(){
    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);

    WINDOW * inputWindow = newwin(3, xmax-12, ymax-5, 5);
    WINDOW * menuWindow = newwin(5, xmax-12, ymax-10, 5);
    //outputWindow = newwin(0, 0, 0, 0);   

    box(inputWindow, 0, 0);
    refresh();
    box(menuWindow, 0, 0);
    refresh();
    move(ymax-6, xmax/2);

    mvwprintw(inputWindow, 1, 1, "Enter your selection: ");    //22 chars
    view.printMenu(menuWindow);
    refresh();
    wrefresh(inputWindow);
}


