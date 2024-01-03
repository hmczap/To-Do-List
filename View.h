#ifndef VIEW_H
#define VIEW_H

#define MAX_BUF 80

#include <iostream>
#include <fstream>
#include <limits>
#include "TDList.h"

using namespace std;

class View{
    public:
        View();
        ~View();

        void addUserTask();
        void resolveTask();
        void killTask();

        void printMenu() const;
        void printSettingsMenu() const;     /////////
        void printPendingTasks() const;
        void printResolvedTasks() const;

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
