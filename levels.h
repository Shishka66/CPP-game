#pragma once
#include "include/curses.h"

class World {
public:
	World(WINDOW* vp, WINDOW* wrld);
	void addObject(int y, int x, char object, char symbol);
	long moves = 0;
private:
	WINDOW* viewport;
	WINDOW* realmap;
};

World::World(WINDOW* vp, WINDOW* wrld) {
	viewport = vp;
	realmap = wrld;
}
void World::addObject(int y, int x,char object, char symbol) {
	mvwaddch(viewport, y, x, symbol);
	mvwaddch(realmap, y, x, object);
}