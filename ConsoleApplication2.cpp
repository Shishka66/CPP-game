#include <iostream>
#include<ctime>
#include<string.h>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <curses.h>
#include <panel.h>
#include "player.h"
#include "levels.h"; 
#include "enemies.h";
#define _WIN32_WINNT 0x0500



int main()
{
	int width = 80;
#pragma region Statements
	setlocale(LC_CTYPE, "C-UTF-8");
	srand(time(NULL));
	using namespace std::this_thread;
	using namespace std::chrono;
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	// ^^^^ Это нужно что бы нельзя было растянуть окно
	initscr();
	noecho();
	start_color();
	curs_set(0);
	WINDOW* world = newwin(25, width, 0, 0);
	WINDOW* vp = newwin(25, width, 0, 0); //Вьюпорт
	WINDOW* textOutput = newwin(5, width, 25, 0);//текстовый выход
	WINDOW* popUp = newwin( 3, 35, 0, 10);//попап сообщения
	box(textOutput, 0, 0);
	box(vp, 0, 0);
	box(popUp,0,0);
	init_pair(1, COLOR_WHITE, COLOR_BLUE);//Белосиняя цветовая палитра
	wbkgd(vp, COLOR_PAIR(1));
	refresh();
	wrefresh(textOutput);
	wrefresh(vp);
	//всё выше - сетап для окон pdcurses
	World* wl = new World(vp, world);
	Player* pl = new Player(wl, vp, textOutput, world, 1, 1, '@');//объявляем игрока
	Enemy* en = new Enemy(vp, world,10,20,'A',pl);
#pragma endregion Statements 
// Объявления переменных и т.д

	WINDOW* currentWindow = vp;
	
	wl->addObject(5,5,'1','#');

	while (true) {
		switch (pl->getMove())
		{
			case('i'):
				break;
		default:
			en->getPlayerLocation();
			pl->display();
			en->display();
			wrefresh(vp);
			wrefresh(textOutput);

			break;
		}
	}
	return 0;
}