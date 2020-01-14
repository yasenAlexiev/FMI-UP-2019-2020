// This is the not so well coded task about finding path in a labyrinth.
// I'd suggest you do not follow the coding practices used here, they were used
// because we did not have much time and I wanted to upload the solution the
// same as you remember it. Global variables are not a good idea, do not use them as seen here.
#include <iostream>


// Sample 7x8 field
//S X X X X X X X
//O O O O O O O X
//X X X X O X X X
//O O O X O O O O
//X X O X X O X X
//X E O X X O O O
//O O O O O O O O

const int N = 7, M = 8;
char field[N][M];

void fillField()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> field[i][j];
		}
	}
}

void printCoordinates(int x, int y)
{
	std::cout << "[" << x << ", " << y << "] ";
}

bool isValidCell(int x, int y)
{
	return (x >= 0
		&& x < N
		&& y >= 0
		&& y < M
		&& field[x][y] == 'O')
		|| field[x][y] == 'E'
		|| field[x][y] == 'S';
}

bool calculatePath(int x, int y)
{
	char lastChar = field[x][y];

	if (field[x][y] == 'E')
	{
		return true;
	}

	if (!isValidCell(x, y))
	{
		return false;
	}

	field[x][y] = '*';
	if (calculatePath(x, y + 1))
	{
		return true;
	}
	if (calculatePath(x + 1, y))
	{
		return true;
	}
	if (calculatePath(x, y - 1))
	{
		return true;
	}

	if (calculatePath(x - 1, y))
	{
		return true;
	}

	field[x][y] = lastChar;

	return false;
}

void printRun()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cout << field[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
int main()
{
	fillField();
	int x = 0, y = 0;
	calculatePath(x, y);
	std::cout << std::endl;
	printRun();


	return 0;
}