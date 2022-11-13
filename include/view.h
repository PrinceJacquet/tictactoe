#ifndef VIEW_H
#define VIEW_H

      
typedef enum RENDER_OPTION
{
	GAME = 0,
	MENU = 1,
    GAME_OVER = 2,
    HELP = 3
}RENDER_OPTION;

 
// View is responsible to present data to users
class View {
    public:
        View();// default constructor        
        void Render();
        void Render(RENDER_OPTION option );
        void Menu(char option);
    private:
        BOARD  m_board = {0};
};


#endif