
#include "include/curses.h"
#include "player.h"
class Enemy {
public:
	Enemy(WINDOW* win, WINDOW* world, int y, int x, char c,Player* player);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void getPlayerLocation();
	void display();
	int xLoc, yLoc, xMax, yMax;
	char prevChar;
	bool moved = false;
private:
	char character;
	WINDOW* curwin;
	WINDOW* map;
	Player* mc;
	World* wl;
	bool canMove = true;
};


Enemy::Enemy(WINDOW* win, WINDOW* world, int y, int x, char c,Player* player) {
	curwin = win;
	map = world;
	yLoc = y;
	xLoc = x;
	mc = player;
	getmaxyx(curwin, yMax, xMax);
	character = c;
}


#pragma region Move
void Enemy::moveUp() {
	char nextChar = mvwinch(curwin, yLoc - 1, xLoc);

	if (yLoc > 1) {
		if (nextChar != ' ') {
			prevChar = nextChar;
			
			if (moved == false) {
				mvwaddch(curwin, yLoc, xLoc, ' ');
				yLoc--;
				
				moved = true;
			}
		}
		else if (nextChar == ' ') {
			if (moved == true) {
				mvwaddch(curwin, yLoc, xLoc, prevChar);
				yLoc--;
				
				moved = false;
			}
			else if (moved == false) {
				mvwaddch(curwin, yLoc, xLoc, ' ');
				yLoc--;
				
			}
		}
	}

	if (yLoc < 1)
		yLoc = 1;
}
void Enemy::moveDown() {
	char nextChar = mvwinch(curwin, yLoc + 1, xLoc);
	if (yLoc < yMax - 2) {
		if (nextChar != ' ') {
			prevChar = nextChar;
			if (moved == false) {
				mvwaddch(curwin, yLoc, xLoc, ' ');
				yLoc++;
				moved = true;
			}
		}
		else if (nextChar == ' ') {
			if (moved == true) {
				mvwaddch(curwin, yLoc, xLoc, prevChar);
				yLoc++;
				moved = false;
			}
			else if (moved == false) {
				mvwaddch(curwin, yLoc, xLoc, ' ');
				yLoc++;
			}
		}
	}
	if (yLoc > yMax - 2)
		yLoc = yMax - 2;
}
void Enemy::moveLeft() {
	char nextChar = mvwinch(curwin, yLoc, xLoc - 1);
	if (xLoc > 1) {
		if (nextChar != ' ') {
			prevChar = nextChar;
			
			if (moved == false) {
				mvwaddch(curwin, yLoc, xLoc, ' ');
				xLoc--;
				
				moved = true;
			}
		}
		else if (nextChar == ' ') {
			if (moved == true) {
				mvwaddch(curwin, yLoc, xLoc, prevChar);
				xLoc--;
				
				moved = false;
			}
			else if (moved == false) {
				mvwaddch(curwin, yLoc, xLoc, ' ');
				xLoc--;
				
			}
		}
	}
	if (xLoc < 1)
		xLoc = 1;
}
void Enemy::moveRight()
{
	char nextChar = mvwinch(curwin, yLoc, xLoc + 1);
	if (xLoc < xMax - 2) {
		if (nextChar != ' ') {
			prevChar = nextChar;
			if (moved == false) {
				mvwaddch(curwin, yLoc, xLoc, ' ');
				xLoc++;
				moved = true;
			}
		}
		else if (nextChar == ' ') {
			if (moved == true) {
				mvwaddch(curwin, yLoc, xLoc, prevChar);
				xLoc++;
				moved = false;
			}
			else if (moved == false) {
				mvwaddch(curwin, yLoc, xLoc, ' ');
				xLoc++;
			}
		}
	}
	if (xLoc > xMax - 2)
		xLoc = xMax - 2;
}
#pragma endregion Move 
//Регион для методов Move

void Enemy::getPlayerLocation() {
	if (canMove == true) {
		if (xLoc > mc->xLoc) {
			moveLeft();
			canMove = false;
		}
		else if (xLoc < mc->xLoc) {
			moveRight();
			canMove = false;
		}
		else if (yLoc > mc->yLoc) {
			moveUp();
			canMove = false;
		}
		else if (yLoc < mc->yLoc) {
			moveDown();
			canMove = false;
		}
	}
	else if (canMove == false)
	{
		display();
		canMove = true;
	}
		wrefresh(curwin);
	}


void Enemy::display()
{
	mvwaddch(curwin, yLoc, xLoc, character);
}