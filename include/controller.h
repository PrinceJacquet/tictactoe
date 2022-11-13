#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../include/model.h"
#include "../include/view.h"
 
#define MAX_INPUT_LINE_SIZE 100
#define VALID_INPUT_SIZE 5


// Controller link Model & View
class Controller {
    public:
        Controller();// default constructor
        
        // when application starts
        void OnLoad();
        void Menu();
        void GetGame(BOARD board);
        void GetInput(void);
        bool isValid(char * X);
        bool isValid(char X);
    private:
    View m_view;
    Model m_model;
};


#endif