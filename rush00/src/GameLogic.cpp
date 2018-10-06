#include "GameLogic.hpp"
#include <ncurses.h>
# include <iostream>
# include <unistd.h>

GameLogic::GameLogic()
{

}

GameLogic::GameLogic(GameLogic const &gl)
{
	*this = gl;
	return ;
}

GameLogic &GameLogic::operator=(GameLogic const &gl)
{
	if (this != &gl)
	{
		
	}
	return (*this);
}

void GameLogic::gameStart()
{
	initscr();
	printw("Hello world!\n");
	cbreak();
	noecho();
	refresh();               
    getch();                     
    endwin();  
	// cbreak();
	// curs_set(0);
	// curs_set(0);
	// noecho();
}

GameLogic::~GameLogic()
{

}