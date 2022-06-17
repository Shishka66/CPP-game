#include "include/curses.h"
#include "levels.h";
#ifndef  _PLAYER_H_
#define _PLAYER_H_
//класс "игрок"
class Player
{
public:
	Player(World* w, WINDOW * win, WINDOW * output , WINDOW* world, int y, int x, char c);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	int getMove();
	void display();
	void uniInter();
	char prevChar;
	char interChar;
	bool moved = false;
	int xLoc, yLoc, xMax, yMax;
private:
	char character;
	WINDOW * curwin;
	WINDOW* outWin;
	WINDOW* map;
	World* wl;


};

//конструктор игрока
Player::Player(World* w,WINDOW* win, WINDOW* output, WINDOW* world, int y, int x, char c) {
	curwin = win;
	outWin = output;
	map = world;
	yLoc = y;
	xLoc = x;
	wl = w;
	getmaxyx(curwin, yMax, xMax);
	keypad(curwin, true);
	character = c;
}



#pragma region Move
void Player::moveUp() {
	char nextChar = mvwinch(curwin, yLoc - 1, xLoc);

	if (yLoc > 1) {
		if (nextChar != ' ') {
			prevChar = nextChar;
			wl->moves++;
			if (moved == false) {
				mvwaddch(curwin, yLoc, xLoc, ' ');
				yLoc--;
				wl->moves++;
				moved = true;
			}
		}
		else if (nextChar == ' ') {
			if (moved == true) {
				mvwaddch(curwin, yLoc, xLoc, prevChar);
				yLoc--;
				wl->moves++;
				moved = false;
			}
			else if (moved == false) {
				mvwaddch(curwin, yLoc, xLoc, ' ');
				yLoc--;
				wl->moves++;
			}
		}
	}

	if (yLoc < 1)
		yLoc = 1;
}
void Player::moveDown() {
	char nextChar = mvwinch(curwin, yLoc + 1, xLoc);
	if (yLoc < yMax - 2) {
		if (nextChar != ' ') {
			prevChar = nextChar;
			wl->moves++;
			if (moved == false) {
				mvwaddch(curwin, yLoc, xLoc, ' ');
				yLoc++;
				wl->moves++;
				moved = true;
			}
		}
		else if (nextChar == ' ') {
			if (moved == true) {
				mvwaddch(curwin, yLoc, xLoc, prevChar);
				yLoc++;
				wl->moves++;
				moved = false;
			}
			else if (moved == false) {
				mvwaddch(curwin, yLoc, xLoc, ' ');
				yLoc++;
				wl->moves++;
			}
		}
	}
	if (yLoc > yMax - 2)
		yLoc = yMax - 2;
}
void Player::moveLeft() {
	char nextChar = mvwinch(curwin, yLoc, xLoc - 1);
	if(xLoc > 1){
		if (nextChar != ' ') {
			prevChar = nextChar;
			wl->moves++;
			if (moved == false) {
				mvwaddch(curwin, yLoc, xLoc, ' ');
				xLoc--;
				wl->moves++;
				moved = true;
			}
		}
		else if (nextChar == ' ') {
			if (moved == true) {
				mvwaddch(curwin, yLoc, xLoc, prevChar);
				xLoc--;
				wl->moves++;
				moved = false;
			}
			else if (moved == false) {
				mvwaddch(curwin, yLoc, xLoc, ' ');
				xLoc--;
				wl->moves++;
			}
		}
	}
	if (xLoc < 1)
		xLoc = 1;
}
void Player::moveRight()
 {
	char nextChar = mvwinch(curwin, yLoc, xLoc + 1);
	if (xLoc < xMax - 2) {
		if (nextChar != ' ') {
			prevChar = nextChar;
			wl->moves++;
			if (moved == false) {
				mvwaddch(curwin, yLoc, xLoc, ' ');
				xLoc++;
				wl->moves++;
				moved = true;
			}
		}
		else if (nextChar == ' ') {
			if (moved == true) {
				mvwaddch(curwin, yLoc, xLoc, prevChar);
				xLoc++;
				wl->moves++;
				moved = false;
			}
			else if (moved == false) {
				mvwaddch(curwin, yLoc, xLoc, ' ');
				xLoc++;
				wl->moves++;
			}
		}
	}
	if (xLoc > xMax - 2)
		xLoc = xMax - 2;
}
#pragma endregion Move 
//Регион для методов Move

#pragma region Interract

void Player::uniInter() {
	werase(outWin);
	box(outWin, 0, 0);
	mvwaddstr(outWin, 1, 1, "В какую сторону взаимодействовать?");
	wrefresh(outWin);
	int dir = wgetch(curwin);
	if (dir == KEY_UP) {
		interChar = mvwinch(map, yLoc - 1, xLoc);
		werase(outWin);
		box(outWin, 0, 0);
	}
	else if (dir == KEY_DOWN) {
		interChar = mvwinch(map, yLoc + 1, xLoc);
		werase(outWin);
		box(outWin, 0, 0);
	}
	else if (dir == KEY_LEFT) {
		interChar = mvwinch(map, yLoc, xLoc - 1);
		werase(outWin);
		box(outWin, 0, 0);
	}
	else if (dir == KEY_RIGHT) {
		interChar = mvwinch(map, yLoc, xLoc + 1);
		werase(outWin);
		box(outWin, 0, 0);
	}
	else{
		werase(outWin);
		box(outWin, 0, 0);
		mvwaddstr(outWin, 1, 1, "Неверный ввод.");
	}
	switch (interChar)
	{
	case('#'):
		mvwaddstr(outWin, 1, 1, "Решётка.");
		break;
	case('1'):
		mvwaddstr(outWin, 1, 1,"Это не решётка.");
		break;
	default:
		break;
	}
}
#pragma endregion
//Регион для взаимодействия с миром.
int Player::getMove()
{
	werase(outWin);
	box(outWin, 0, 0);
	int choice = wgetch(curwin);
	switch (choice) {
	case KEY_UP:
		moveUp();
		break;
	case KEY_DOWN:
		moveDown(); 
		break;

	case KEY_LEFT:
		moveLeft();
		break;

	case KEY_RIGHT:
		moveRight();
		break;
	case 'e': // взаимодействие
		uniInter();
		break;
	case '0':
		//это типа портал на другой уровень, доделать когда будут готовы разные уровни.
		break;
	default:
		break;
	}
	wrefresh(curwin);
	return choice;
}

void Player::display() {
	mvwaddch(curwin, yLoc, xLoc, character);
}
#endif
