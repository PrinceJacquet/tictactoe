#include "../include/model.h"

using namespace std;


// Model is responsible for data get and set

Player::Player(){// default constructor
    SetName("player");
    SetScore(0);
} 
        
string Player::SetName( const string &newName){
    m_name = newName;
    return m_name;
}

int Player::SetScore( int newScore){
    m_score = newScore;
    return m_score;
}


bool Player::ToggleTurn(void){
    m_turn = !m_turn;
    return (bool) m_turn;
}

bool Player::SetTurn(int new_turn){
    m_turn = new_turn;
    return (bool) m_turn ;
}

bool Player::GetTurn(){
    return (bool) m_turn ;
}


Model::Model() { // default constructor
    m_gameStatus = RUNNING;
    m_player1.SetTurn(1);
    m_player2.SetTurn(0);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            m_board.board_3x3[i][j]='-';
        }
    }
} 

Model::Model(const string &data) {
    m_gameStatus = RUNNING;
    SetData(data);
}

string Model::Data(){
    return m_data;
}
 
void Model::SetData(const string &data) {
    m_data = data;
   
}

void Model::SetBoard(){
    //return this->board;
}


void Model::GetBoard(BOARD board){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board.board_3x3[i][j]=m_board.board_3x3[i][j];
        }
    }
}

void Model::Move(char new_move){
    m_player1.GetTurn()?  m_board.board_9[new_move - '1'] = 'X': m_board.board_9[new_move - '1'] = 'O';
    m_player1.ToggleTurn();
    m_player2.ToggleTurn();

}


GAME_STATUS Model::CheckGame(void){
    int not_played = 0;


    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board.board_3x3[i][j]=m_board.board_3x3[i][j];
        }
    }
    int win[8][3] = {{1,2,3},{1,4,7},{1,5,9},{2,5,8},{3,5,7},{3,6,9},{4,5,6},{7,8,9}};
    for(int i =0; i<8;i++){
        if(win[i][0] == '-' || win[i][0] == '0' ) continue;
        if(win[i][0] == win[i][1] && win[i][0] == win[i][2]){

        }
    }
    
}