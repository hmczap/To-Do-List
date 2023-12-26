#include <iostream>
#include <exception>
#include "View.h"
//#include "Control.h"
//#include "Task.h"

using namespace std;

int main(){

    /*
    Controller control;
    control.launch();
    */
    
    int l = 1;
    int userInput;

    View* view = new View();

    while (l){
        view->printMenu();

        cin>>userInput;
        
        switch (userInput) {
            case 0:
                l = 0; 
                break;
            case 1:
                // view to do list
                cout<<"debug: viewing the list"<<endl;
                break;
            case 2:
                // add a task
                cout<<"debug: adding to the list"<<endl;
                break;
            case 3: 
                //  remove a task
                cout<<"debug: removing from the list"<<endl;
                break;        
            default:
                break;
        }

    }
    delete view;
    return 0;
}