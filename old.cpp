/*bool rec = false;

	const int SIZE = 10;
	int playerX = 0;
	int playerY = 0;
	int x = 0;
	int y = 0;

	int sleepBeforeMove = 200;

	char wall = '#';




	char map[SIZE][SIZE]
	{
		{'@','.','.','#','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','#','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'}
	};
;

	while (!rec)
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				move(i, j);
				waddch(vp,map[i][j]);
			}
		}
		wrefresh(vp);


		if (GetKeyState('D') & 0x8000)
		{
			if (map[playerY][playerX + 1] == wall) {

			}
			else if (playerX + 1 >= SIZE) {

			}
			else {
				sleep_for(milliseconds(sleepBeforeMove));
				char temp = map[y][x];
				map[y][x] = map[y][playerX + 1];
				map[y][playerX + 1] = temp;
				playerX++;
				x++;
			}
		}

		if (GetKeyState('A') & 0x8000)
		{
			if (map[playerY][playerX - 1] == wall) {

			}
			else if (playerX - 1 <= -1) {

			}
			else {
				sleep_for(milliseconds(sleepBeforeMove));
				char temp = map[y][x];
				map[y][x] = map[y][playerX - 1];
				map[y][playerX - 1] = temp;
				playerX--;
				x--;
			}
		}

		if (GetKeyState('S') & 0x8000)
		{
			if (map[playerY + 1][playerX] == wall) {

			}
			else if(map[playerY + 1][playerX] >= sizeof(map))
			{

			}
			else {
				sleep_for(milliseconds(sleepBeforeMove));
				char temp = map[y][x];
				map[y][x] = map[playerY + 1][x];
				map[playerY + 1][x] = temp;
				playerY++;
				y++;
			}

		}


		if (GetKeyState('W') & 0x8000)
		{
			if (map[playerY - 1][playerX] == wall) {

			}
			else if (map[playerY - 1][playerX] >= sizeof(map))
			{

			}
			else {
				sleep_for(milliseconds(sleepBeforeMove));
				char temp = map[y][x];
				map[y][x] = map[playerY - 1][x];
				map[playerY - 1][x] = temp;
				playerY--;
				y--;
			}
		}
		system("cls");
		endwin();
	}
}
*/