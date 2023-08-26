#include "util.h"

void move_cursor(int x, int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	
	SetConsoleCursorPosition(consoleHandle, coordinates);
}

