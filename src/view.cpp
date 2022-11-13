#include "../include/view.h"
#include "../include/Controller.h"         

#include <iostream>    
#include <string>  

using namespace std;

extern Controller main_controller;

string fl = "\n  __game__ \n\n ";
string go = " Do you wish to play again ? \n\n ";
string mn = " ____ ____ ____ _________ ____ ____ ____ _________ ____ ____ ____ \n||t |||i |||c |||       |||t |||a |||c |||       |||t |||o |||e ||\n||__|||__|||__|||_______|||__|||__|||__|||_______|||__|||__|||__||\n|/__\\|/__\\|/__\\|/_______\\|/__\\|/__\\|/__\\|/_______\\|/__\\|/__\\|/__\\|\n\n\n ";
string ll = " \n What is your move ? (H -> Help , 1-9 -> Where to play, a-z -> Menu options ...)\n\n ";

// View is responsible to present data to 
View::View(){}    

//render game
void View::Render() { 
    main_controller.GetGame(m_board);
    cout << fl <<" X | O | X\n  ---------\n  X | O | X\n  ---------\n  X | O | X\n"<< ll <<endl;
}


void View::Render(RENDER_OPTION option ) { 
    switch(option){
        case GAME : main_controller.GetGame(m_board);
                    cout << fl <<"\n-----------\n "; 
                    for(int i =0;i<3;i++){
                        cout << m_board.board_3x3[i][0]<<" | "<<m_board.board_3x3[i][1]<<" | "<<m_board.board_3x3[i][2]<<"\n-----------\n ";
                    }
                    //cout << fl <<m_board[0]<<" | "<<m_board[1]<<" | "<<m_board[2]<<"\n  ---------\n"<<m_board[3]<<" | "<<m_board[4]<<" | "<<m_board[5]<<"\n  ---------\n "<<m_board[6]<<" | "<<m_board[7]<<" | "<<m_board[8]<<"\n  ---------\n"<< ll <<endl;
                    main_controller.GetInput();
                    break;   
        case MENU :
                    cout << mn << ll <<endl;
                    break;
        case GAME_OVER : 
                    break;
        case HELP : 
                    break;
        default: cout << go <<" X | O | X\n  ---------\n  X | O | X\n  ---------\n  X | O | X\n"<< ll <<endl;
    }           
}


void View::Menu(char option){
    cout << mn << ll << option << endl;
}