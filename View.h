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
        // View has no data members/attributes

        void addUserTask(TDList&);

        void printMenu() const;
        void printAbout() const;
        
};
#endif