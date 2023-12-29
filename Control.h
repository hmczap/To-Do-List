#ifndef CONTROL_H
#define CONTROL_H

#include "View.h"
#include <iostream>
#include <string>
#include "Task.h"
#include "TDList.h"
#include <iostream>
#include <exception>
#include "defs.h"

using namespace std;

class Control{
    public:
        void launch();

    private:
        View view;
        string taskColour;
        int taskMode;

        void loadUserSettings();
        //void loadViews();
        void changeUserSettings();
        //void clean();
};
#endif
