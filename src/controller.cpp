#include "../include/controller.h"

#include "../include/model.h"
#include "../include/view.h"

#include <iostream>
#include <string.h>

using namespace std;
 
// Controller combines Model and View

Controller::Controller(){}


//
void Controller::OnLoad(){ 
    Controller::Menu();
}


//
void Controller::GetInput(){ 
    // char input[MAX_INPUT_LINE_SIZE] = {0};
    // do {
         
    //     cout<<"> "; 
    //     cin.get(input,MAX_INPUT_LINE_SIZE);
    // }while(!Controller::isValid(input));



    char input;
    do {
         
        cout<<"> "; 
        cin >> input;
    }while(!Controller::isValid(input));


    if(input >= 'a' && input <= 'z')
    {
        m_view.Menu(input);
    }else if(input >= '1' && input <= '9'){
        m_model.Move(input);
        m_view.Render(GAME);
        switch(m_model.CheckGame()){
            case WON: 
                    cout << "WON \n"; 
                    break;
            case DRAWN: 
                    cout << "DRAWN \n";
                    break;
            case RUNNING:
                    cout << "RUNNING \n";
                    break; 
            default :
                    cout << "default \n";
        }
    }else if(input == 'H'){
        m_view.Render(HELP);
    }else {
        cout << "ERROR BRO :" << input <<endl;
        
    }
    
}

//
void Controller::Menu(){ 
    // RENDER_OPTION menu = MENU;
    m_view.Render(MENU);
}




void Controller::GetGame(BOARD board){
   m_model.GetBoard(board);
}


bool Controller::isValid(char * X){
    
    //check number 
    char number[9][2] = {"1","2","3","4","5","6","7","8","9"};
    for(int i = 1; i <= 9; i++){
        if(strcmp(X,number[i-1])==0){
            return 1;
        }
    }

    //check help
    if(strcmp(X,"H")==0){
            return 1;
    }

    //check Menu
    char menu[26][2] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    for(int i = 1; i <= 26; i++){
        if(strcmp(X,menu[i-1])==0){
            return 1;
        }
    }

    return 0;
}



bool Controller::isValid(char X){
    

    for(int i = 'a'; i <= 'z'; i++){
        if(X == i){
            return 1;
        }
    }

    //check help
    if(X =='H'){
        return 1;
    }

    for(int i = '1'; i <= '9'; i++){
        if(X == i){
            return 1;
        }
    }

    return 0;
}