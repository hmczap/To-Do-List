#ifndef VIEW_H
#define VIEW_H

#define MAX_BUF 80

#include <iostream>
#include <fstream>
#include <limits>
#include "TDList.h"
#include <curses.h>

using namespace std;

class View{
    public:
        View();
        ~View();

        void addUserTask(WINDOW*,WINDOW*);
        void addUserTask(const string&, const string&, int);
        void resolveTask(WINDOW*,WINDOW*);
        void killTask(WINDOW*,WINDOW*);

        void printMenu() const;
        void printMenu(WINDOW*) const;
        void printSettingsMenu() const;     /////////
        void printPendingTasks(WINDOW*) const;
        void printResolvedTasks(WINDOW*) const;

        void printSettings() const;         ///////
        void printAbout() const;
        void printColours() const;
        
    private:
        TDList list;
        string taskColour;
        int taskMode;

        void setTaskColour();
        void setTaskMode();
};
#endif
