#ifndef MODEL_H
#define MODEL_H

#include <string>


typedef enum GAME_STATUS
{
	STOPPED = 0,
	RUNNING = 1,
    WON = 2,
    DRAWN = 3
}GAME_STATUS;

typedef union BOARD
{
    char  board_3x3[3][3];
    char  board_9[9];
} BOARD;

// Model is responsible for data get and set

class Player {
    public :
        // default constructor
        Player();
        std::string SetName( const std::string &newName);
        int SetScore( int newScore);
        bool ToggleTurn(void);
        bool SetTurn(int new_turn);
        bool GetTurn();
    private:
        std::string m_name = "";
        int m_score = 0;
        bool m_turn = 0;
};

class Model {
    public:
        // default constructor
        Model();
        Model(const std::string &data);
        std::string Data();
        void SetData(const std::string &data);
        void SetBoard();
        void GetBoard(BOARD board);
        void Move(char new_move);
        GAME_STATUS CheckGame(void);
        
    private:
        Player m_player1;
        Player m_player2;
        std::string m_data;
        GAME_STATUS m_gameStatus = STOPPED;
        
        /* 

          board

        1 | 2 | 3
        ---------
        4 | 5 | 6
        ---------
        7 | 8 | 9

        */
        BOARD m_board = {0};
        
};

#endif


