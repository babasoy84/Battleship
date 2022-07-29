#include<iostream>
#include<Windows.h>
#include<conio.h>

using namespace std;

#define white 15
#define blue 3
#define yellow 6
#define red 4
#define green 2
#define b_green 10
#define cyan 11
#define gray 8
#define right 77
#define left 75
#define up 72
#define down 80
#define enter 13
#define space 32
#define ship 111
#define ship_color yellow
#define cursor_color yellow
#define number_color blue

void print_s(char** square, const int size, int x = -1, int y = -1) {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, number_color);
	cout << "\n    0 1 2 3 4 5 6 7 8 9\n";
	char arr[10]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	for (int i = 0; i < size; i++)
	{
		SetConsoleTextAttribute(color, number_color);
		cout << "  " << arr[i] << " ";
		SetConsoleTextAttribute(color, white);
		for (int j = 0; j < size; j++)
		{
			if (square[i][j] == 'x')
			{
				SetConsoleTextAttribute(color, red);
			}
			else if (square[i][j] == char(251))
			{
				SetConsoleTextAttribute(color, green);
			}
			else if (square[i][j] == char(ship))
			{
				SetConsoleTextAttribute(color, ship_color);
			}
			else if (i == x && j == y)
			{
				SetConsoleTextAttribute(color, cursor_color);
			}
			cout << square[i][j] << " ";
			SetConsoleTextAttribute(color, white);
		}
		cout << endl;
	}
}

void init(char**& square, const int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			square[i][j] = 254;
		}
	}
}

int count_s(char** square, char rotate, int x, int y) {
	if (x > 0 && x < 9 && y > 0 && y < 9)
	{
		if (rotate == 'y')
		{
			y++;
			if (square[x][y] == ship)
			{
				if (y == 9)
				{
					if (square[x - 1][y - 1] == ship || square[x + 1][y - 1] == ship)
					{
						return -100;
					}
					else
					{
						return 1 + count_s(square, rotate, x, y);
					}
				}
				else
				{
					if (square[x - 1][y - 1] == ship || square[x + 1][y + 1] == ship || square[x - 1][y + 1] == ship || square[x + 1][y - 1] == ship)
					{
						return -100;
					}
					else
					{
						return 1 + count_s(square, rotate, x, y);
					}
				}
			}
			else
			{
				return 0;
			}
		}
		else if (rotate == 'x')
		{
			x++;
			if (square[x][y] == ship)
			{
				if (x == 9)
				{
					if (square[x - 1][y - 1] == ship || square[x - 1][y + 1] == ship)
					{
						return -100;
					}
					else
					{
						return 1 + count_s(square, rotate, x, y);
					}
				}
				else
				{
					if (square[x - 1][y - 1] == ship || square[x + 1][y + 1] == ship || square[x - 1][y + 1] == ship || square[x + 1][y - 1] == ship)
					{
						return -100;
					}
					else
					{
						return 1 + count_s(square, rotate, x, y);
					}
				}
			}
			else
			{
				return 0;
			}
		}
	}
	else if (x == 0)
	{
		if (y == 0)
		{
			if (rotate == 'y')
			{
				y++;
				if (square[x][y] == ship)
				{
					if (square[x + 1][y + 1] == ship)
					{
						return -100;
					}
					else
					{
						return 1 + count_s(square, rotate, x, y);
					}
				}
				else
				{
					return 0;
				}
			}
			else if (rotate == 'x')
			{
				x++;
				if (square[x][y] == ship)
				{
					if (square[x + 1][y + 1] == ship)
					{
						return -100;
					}
					else
					{
						return 1 + count_s(square, rotate, x, y);
					}
				}
				else
				{
					return 0;
				}
			}
		}
		else if (y == 9)
		{
			if (rotate == 'y')
			{
				return 0;
			}
			else if (rotate == 'x')
			{
				x++;
				if (square[x][y] == ship)
				{
					if (square[x + 1][y - 1] == ship)
					{
						return -100;
					}
					else
					{
						return 1 + count_s(square, rotate, x, y);
					}
				}
				else
				{
					return 0;
				}
			}
		}
		else if (y > 0 && y < 9)
		{
			if (rotate == 'y')
			{
				y++;
				if (square[x][y] == ship)
				{
					if (y == 9)
					{
						if (square[x + 1][y - 1] == ship)
						{
							return -100;
						}
						else
						{
							return 1 + count_s(square, rotate, x, y);
						}
					}
					else
					{
						if (square[x + 1][y + 1] == ship || square[x + 1][y - 1] == ship)
						{
							return -100;
						}
						else
						{
							return 1 + count_s(square, rotate, x, y);
						}
					}
				}
				else
				{
					return 0;
				}
			}
			else if (rotate == 'x')
			{
				x++;
				if (square[x][y] == ship)
				{
					if (square[x + 1][y + 1] == ship || square[x + 1][y - 1] == ship)
					{
						return -100;
					}
					else
					{
						return 1 + count_s(square, rotate, x, y);
					}
				}
				else
				{
					return 0;
				}
			}
		}
	}
	else if (y == 0)
	{
		if (x == 9)
		{
			if (rotate == 'y')
			{
				y++;
				if (square[x][y] == ship)
				{
					if (square[x - 1][y + 1] == ship)
					{
						return -100;
					}
					else
					{
						return 1 + count_s(square, rotate, x, y);
					}
				}
				else
				{
					return 0;
				}
			}
			else if (rotate == 'x')
			{
				return 0;
			}
		}
		else if (x > 0 && x < 9)
		{
			if (rotate == 'y')
			{
				y++;
				if (square[x][y] == ship)
				{
					if (square[x + 1][y + 1] == ship || square[x - 1][y + 1] == ship)
					{
						return -100;
					}
					else
					{
						return 1 + count_s(square, rotate, x, y);
					}
				}
				else
				{
					return 0;
				}
			}
			else if (rotate == 'x')
			{
				x++;
				if (square[x][y] == ship)
				{
					if (x == 9)
					{
						if (square[x - 1][y + 1] == ship)
						{
							return -100;
						}
						else
						{
							return 1 + count_s(square, rotate, x, y);
						}
					}
					else
					{
						if (square[x + 1][y + 1] == ship || square[x - 1][y + 1] == ship)
						{
							return -100;
						}
						else
						{
							return 1 + count_s(square, rotate, x, y);
						}
					}
				}
				else
				{
					return 0;
				}
			}
		}
	}
	else if (x == 9)
	{
		if (y == 9)
		{
			return 0;
		}
		else if (y > 0 && y < 9)
		{
			if (rotate == 'y')
			{
				y++;
				if (square[x][y] == ship)
				{
					if (y == 9)
					{
						if (square[x - 1][y - 1] == ship)
						{
							return -100;
						}
						else
						{
							return 1 + count_s(square, rotate, x, y);
						}
					}
					else
					{
						if (square[x - 1][y - 1] == ship || square[x - 1][y + 1] == ship)
						{
							return -100;
						}
						else
						{
							return 1 + count_s(square, rotate, x, y);
						}
					}
				}
				else
				{
					return 0;
				}
			}
			else if (rotate == 'x')
			{
				return 0;
			}
		}
	}
	else if (y == 9)
	{
		if (x > 0 && x < 9)
		{
			if (rotate == 'y')
			{
				return 0;
			}
			else if (rotate == 'x')
			{
				x++;
				if (square[x][y] == ship)
				{
					if (x == 9)
					{
						if (square[x - 1][y - 1] == ship)
						{
							return -100;
						}
						else
						{
							return 1 + count_s(square, rotate, x, y);
						}
					}
					else
					{
						if (square[x - 1][y - 1] == ship || square[x + 1][y - 1] == ship)
						{
							return -100;
						}
						else
						{
							return 1 + count_s(square, rotate, x, y);
						}
					}
				}
				else
				{
					return 0;
				}
			}
		}
	}
}

bool check(char** square, int size) {
	int count = 0, count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0;
	char rotate = 'a';
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			rotate = 'a';
			count = 0;
			if (i > 0 && i < 9 && j > 0 && j < 9)
			{
				if (square[i][j] == ship && square[i - 1][j] != ship && square[i][j - 1] != ship)
				{
					if (square[i - 1][j - 1] == ship || square[i + 1][j + 1] == ship || square[i - 1][j + 1] == ship || square[i + 1][j - 1] == ship)
					{
						return false;
					}
					else
					{
						if (square[i][j + 1] == ship && square[i + 1][j] == ship)
						{
							return false;
						}
						else if (square[i][j + 1] == ship)
						{
							rotate = 'y';
						}
						else if (square[i + 1][j] == ship)
						{
							rotate = 'x';
						}
						else
						{
							count = 1;
						}
						if (rotate != 'a')
						{
							count = 1 + count_s(square, rotate, i, j);
						}
					}
				}
			}
			else if (i == 0)
			{
				if (j == 0)
				{
					if (square[i][j] == ship)
					{
						if (square[i + 1][j + 1] == ship)
						{
							return false;
						}
						else
						{
							if (square[i][j + 1] == ship && square[i + 1][j] == ship)
							{
								return false;
							}
							else if (square[i][j + 1] == ship)
							{
								rotate = 'y';
							}
							else if (square[i + 1][j] == ship)
							{
								rotate = 'x';
							}
							else
							{
								count = 1;
							}
							if (rotate != 'a')
							{
								count = 1 + count_s(square, rotate, i, j);
							}
						}
					}
				}
				else if (j == 9)
				{
					if (square[i][j] == ship && square[i][j - 1] != ship)
					{
						if (square[i + 1][j - 1] == ship)
						{
							return false;
						}
						else
						{
							if (square[i + 1][j] == ship)
							{
								rotate = 'x';
							}
							else
							{
								count = 1;
							}
							if (rotate != 'a')
							{
								count = 1 + count_s(square, rotate, i, j);
							}
						}
					}
				}
				else if (j > 0 && j < 9)
				{
					if (square[i][j] == ship && square[i][j - 1] != ship)
					{
						if (square[i + 1][j + 1] == ship || square[i + 1][j - 1] == ship)
						{
							return false;
						}
						else
						{
							if (square[i][j + 1] == ship && square[i + 1][j] == ship)
							{
								return false;
							}
							else if (square[i][j + 1] == ship)
							{
								rotate = 'y';
							}
							else if (square[i + 1][j] == ship)
							{
								rotate = 'x';
							}
							else
							{
								count = 1;
							}
							if (rotate != 'a')
							{
								count = 1 + count_s(square, rotate, i, j);
							}
						}
					}
				}
			}
			else if (j == 0)
			{
				if (i == 9)
				{
					if (square[i][j] == ship && square[i - 1][j] != ship && square[i][j - 1] != ship)
					{
						if (square[i - 1][j + 1] == ship)
						{
							return false;
						}
						else
						{
							if (square[i][j + 1] == ship)
							{
								rotate = 'y';
							}
							else
							{
								count = 1;
							}
							if (rotate != 'a')
							{
								count = 1 + count_s(square, rotate, i, j);
							}
						}
					}
				}
				else if (i > 0 && i < 9)
				{
					if (square[i][j] == ship && square[i - 1][j] != ship)
					{
						if (square[i + 1][j + 1] == ship || square[i - 1][j + 1] == ship)
						{
							return false;
						}
						else
						{
							if (square[i][j + 1] == ship && square[i + 1][j] == ship)
							{
								return false;
							}
							else if (square[i][j + 1] == ship)
							{
								rotate = 'y';
							}
							else if (square[i + 1][j] == ship)
							{
								rotate = 'x';
							}
							else
							{
								count = 1;
							}
							if (rotate != 'a')
							{
								count = 1 + count_s(square, rotate, i, j);
							}
						}
					}
				}
			}
			else if (i == 9)
			{
				if (j == 9)
				{
					if (square[i][j] == ship && square[i - 1][j] != ship && square[i][j - 1] != ship)
					{
						if (square[i - 1][j - 1] == ship)
						{
							return false;
						}
						else
						{
							count = 1;
						}
					}
				}
				else if (j > 0 && j < 9)
				{
					if (square[i][j] == ship && square[i - 1][j] != ship && square[i][j - 1] != ship)
					{
						if (square[i - 1][j - 1] == ship || square[i - 1][j + 1] == ship)
						{
							return false;
						}
						else
						{
							if (square[i][j + 1] == ship)
							{
								rotate = 'y';
							}
							else
							{
								count = 1;
							}
							if (rotate != 'a')
							{
								count = 1 + count_s(square, rotate, i, j);
							}
						}
					}
				}
			}
			else if (j == 9)
			{
				if (i > 0 && i < 9)
				{
					if (square[i][j] == ship && square[i - 1][j] != ship && square[i][j - 1] != ship)
					{
						if (square[i - 1][j - 1] == ship || square[i + 1][j - 1] == ship)
						{
							return false;
						}
						else
						{
							if (square[i + 1][j] == ship)
							{
								rotate = 'x';
							}
							else
							{
								count = 1;
							}
							if (rotate != 'a')
							{
								count = 1 + count_s(square, rotate, i, j);
							}
						}
					}
				}
			}
			if (count == 0)
			{

			}
			else if (count == 1)
			{
				count_1++;
			}
			else if (count == 2)
			{
				count_2++;
			}
			else if (count == 3)
			{
				count_3++;
			}
			else if (count == 4)
			{
				count_4++;
			}
			else
			{
				return false;
			}
		}
	}
	if (count_1 == 5 && count_2 == 4 && count_3 == 3 && count_4 == 2)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool check_s(char**& s, char r, int size, int x, int y, int c) {
	if (c == 1)
	{
		if (x > 0 && x < 9 && y > 0 && y < 9)
		{
			if (s[x][y] == ship && s[x + 1][y + 1] != ship && s[x + 1][y - 1] != ship && s[x - 1][y + 1] != ship && s[x - 1][y - 1] != ship && s[x][y + 1] != ship && s[x][y - 1] != ship && s[x - 1][y] != ship && s[x + 1][y] != ship)
			{
				return true;
			}
			else
			{
				s[x][y] = 254;
				return false;
			}
		}
		else if (x == 0)
		{
			if (y == 0)
			{
				if (s[x][y] == ship && s[x + 1][y + 1] != ship && s[x][y + 1] != ship && s[x + 1][y] != ship)
				{
					return true;
				}
				else
				{
					s[x][y] = 254;
					return false;
				}
			}
			else if (y > 0 && y < 9)
			{
				if (s[x][y] == ship && s[x + 1][y + 1] != ship && s[x + 1][y - 1] != ship && s[x][y + 1] != ship && s[x][y - 1] != ship && s[x + 1][y] != ship)
				{
					return true;
				}
				else
				{
					s[x][y] = 254;
					return false;
				}
			}
			else if (y == 9)
			{
				if (s[x][y] == ship && s[x + 1][y - 1] != ship && s[x][y - 1] != ship && s[x + 1][y] != ship)
				{
					return true;
				}
				else
				{
					s[x][y] = 254;
					return false;
				}
			}
		}
		else if (x > 0 && x < 9)
		{
			if (y == 0)
			{
				if (s[x][y] == ship && s[x + 1][y + 1] != ship && s[x - 1][y + 1] != ship && s[x][y + 1] != ship && s[x - 1][y] != ship && s[x + 1][y] != ship)
				{
					return true;
				}
				else
				{
					s[x][y] = 254;
					return false;
				}
			}
			else if (y == 9)
			{
				if (s[x][y] == ship && s[x + 1][y - 1] != ship && s[x - 1][y - 1] != ship && s[x][y - 1] != ship && s[x - 1][y] != ship && s[x + 1][y] != ship)
				{
					return true;
				}
				else
				{
					s[x][y] = 254;
					return false;
				}
			}
		}
		else if (x == 9)
		{
			if (y == 0)
			{
				if (s[x][y] == ship && s[x - 1][y + 1] != ship && s[x][y + 1] != ship && s[x - 1][y] != ship)
				{
					return true;
				}
				else
				{
					s[x][y] = 254;
					return false;
				}
			}
			else if (y > 0 && y < 9)
			{
				if (s[x][y] == ship && s[x - 1][y + 1] != ship && s[x - 1][y - 1] != ship && s[x][y + 1] != ship && s[x][y - 1] != ship && s[x - 1][y] != ship)
				{
					return true;
				}
				else
				{
					s[x][y] = 254;
					return false;
				}
			}
			else if (y == 9)
			{
				if (s[x][y] == ship && s[x - 1][y - 1] != ship && s[x][y - 1] != ship && s[x - 1][y] != ship)
				{
					return true;
				}
				else
				{
					s[x][y] = 254;
					return false;
				}
			}
		}
		else
		{
			s[x][y] = 254;
			return false;
		}
	}
	else if (c == 2)
	{
		if (r == 'r')
		{
			if (y < 9)
			{
				if (check_s(s, r, size, x, y, 1))
				{
					s[x][y] = 254;
					s[x][y + 1] = ship;
					if (check_s(s, r, size, x, y + 1, 1))
					{
						s[x][y] = ship;
						s[x][y + 1] = 254;
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				s[x][y] = 254;
				return false;
			}
		}
		else if (r == 'l')
		{
			if (y > 0)
			{
				if (check_s(s, r, size, x, y, 1))
				{
					s[x][y] = 254;
					s[x][y - 1] = ship;
					if (check_s(s, size, r, x, y - 1, 1))
					{
						s[x][y] = ship;
						s[x][y - 1] = 254;
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				s[x][y] = 254;
				return false;
			}
		}
		else if (r == 'u')
		{
			if (x > 0)
			{
				if (check_s(s, r, size, x, y, 1))
				{
					s[x][y] = 254;
					s[x - 1][y] = ship;
					if (check_s(s, size, r, x - 1, y, 1))
					{
						s[x][y] = ship;
						s[x - 1][y] = 254;
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				s[x][y] = 254;
				return false;
			}
		}
		else if (r == 'd')
		{
			if (x < 9)
			{
				if (check_s(s, r, size, x, y, 1))
				{
					s[x][y] = 254;
					s[x + 1][y] = ship;
					if (check_s(s, size, r, x + 1, y, 1))
					{
						s[x][y] = ship;
						s[x + 1][y] = 254;
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				s[x][y] = 254;
				return false;
			}
		}
		else
		{
			s[x][y] = 254;
			return false;
		}
	}
	else if (c == 3)
	{
		if (r == 'r')
		{
			if (y < 8)
			{
				if (check_s(s, r, size, x, y, 1))
				{
					s[x][y] = 254;
					s[x][y + 1] = ship;
					if (check_s(s, r, size, x, y + 1, 1))
					{
						s[x][y + 1] = 254;
						s[x][y + 2] = ship;
						if (check_s(s, r, size, x, y + 2, 1))
						{
							s[x][y + 2] = 254;
							s[x][y] = ship;
							return true;
						}
						else
						{
							s[x][y + 2] = 254;
							s[x][y] = ship;
							return false;
						}
					}
					else
					{
						s[x][y + 1] = 254;
						s[x][y] = ship;
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				s[x][y] = 254;
				return false;
			}
		}
		else if (r == 'l')
		{
			if (y > 1)
			{
				if (check_s(s, r, size, x, y, 1))
				{
					s[x][y] = 254;
					s[x][y - 1] = ship;
					if (check_s(s, r, size, x, y - 1, 1))
					{
						s[x][y - 1] = 254;
						s[x][y - 2] = ship;
						if (check_s(s, r, size, x, y - 2, 1))
						{
							s[x][y - 2] = 254;
							s[x][y] = ship;
							return true;
						}
						else
						{
							s[x][y - 2] = 254;
							s[x][y] = ship;
							return false;
						}
					}
					else
					{
						s[x][y - 1] = 254;
						s[x][y] = ship;
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				s[x][y] = 254;
				return false;
			}
		}
		else if (r == 'u')
		{
			if (x > 1)
			{
				if (check_s(s, r, size, x, y, 1))
				{
					s[x][y] = 254;
					s[x - 1][y] = ship;
					if (check_s(s, r, size, x - 1, y, 1))
					{
						s[x - 1][y] = 254;
						s[x - 2][y] = ship;
						if (check_s(s, r, size, x - 2, y, 1))
						{
							s[x - 2][y] = 254;
							s[x][y] = ship;
							return true;
						}
						else
						{
							s[x - 2][y] = 254;
							s[x][y] = ship;
							return false;
						}
					}
					else
					{
						s[x - 1][y] = 254;
						s[x][y] = ship;
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				s[x][y] = 254;
				return false;
			}
		}
		else if (r == 'd')
		{
			if (x < 8)
			{
				if (check_s(s, r, size, x, y, 1))
				{
					s[x][y] = 254;
					s[x + 1][y] = ship;
					if (check_s(s, r, size, x + 1, y, 1))
					{
						s[x + 1][y] = 254;
						s[x + 2][y] = ship;
						if (check_s(s, r, size, x + 2, y, 1))
						{
							s[x + 2][y] = 254;
							s[x][y] = ship;
							return true;
						}
						else
						{
							s[x + 2][y] = 254;
							s[x][y] = ship;
							return false;
						}
					}
					else
					{
						s[x + 1][y] = 254;
						s[x][y] = ship;
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				s[x][y] = 254;
				return false;
			}
		}
		else
		{
			s[x][y] = 254;
			return false;
		}
	}
	else if (c == 4)
	{
		if (r == 'r')
		{
			if (y < 7)
			{
				if (check_s(s, r, size, x, y, 1))
				{
					s[x][y] = 254;
					s[x][y + 1] = ship;
					if (check_s(s, r, size, x, y + 1, 1))
					{
						s[x][y + 1] = 254;
						s[x][y + 2] = ship;
						if (check_s(s, r, size, x, y + 2, 1))
						{
							s[x][y + 2] = 254;
							s[x][y + 3] = ship;
							if (check_s(s, r, size, x, y + 3, 1))
							{
								s[x][y + 3] = 254;
								s[x][y] = ship;
								return true;
							}
							else
							{
								s[x][y + 3] = 254;
								s[x][y] = ship;
								return false;
							}
						}
						else
						{
							s[x][y + 2] = 254;
							s[x][y] = ship;
							return false;
						}
					}
					else
					{
						s[x][y] = ship;
						s[x][y + 1] = 254;
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				s[x][y] = 254;
				return false;
			}
		}
		else if (r == 'l')
		{
			if (y > 2)
			{
				if (check_s(s, r, size, x, y, 1))
				{
					s[x][y] = 254;
					s[x][y - 1] = ship;
					if (check_s(s, r, size, x, y - 1, 1))
					{
						s[x][y - 1] = 254;
						s[x][y - 2] = ship;
						if (check_s(s, r, size, x, y - 2, 1))
						{
							s[x][y - 2] = 254;
							s[x][y - 3] = ship;
							if (check_s(s, r, size, x, y - 3, 1))
							{
								s[x][y - 3] = 254;
								s[x][y] = ship;
								return true;
							}
							else
							{
								s[x][y - 3] = 254;
								s[x][y] = ship;
								return false;
							}
						}
						else
						{
							s[x][y - 2] = 254;
							s[x][y] = ship;
							return false;
						}
					}
					else
					{
						s[x][y] = ship;
						s[x][y - 1] = 254;
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				s[x][y] = 254;
				return false;
			}
		}
		else if (r == 'u')
		{
			if (x > 2)
			{
				if (check_s(s, r, size, x, y, 1))
				{
					s[x][y] = 254;
					s[x - 1][y] = ship;
					if (check_s(s, r, size, x - 1, y, 1))
					{
						s[x - 1][y] = 254;
						s[x - 2][y] = ship;
						if (check_s(s, r, size, x - 2, y, 1))
						{
							s[x - 2][y] = 254;
							s[x - 3][y] = ship;
							if (check_s(s, r, size, x - 3, y, 1))
							{
								s[x - 3][y] = 254;
								s[x][y] = ship;
								return true;
							}
							else
							{
								s[x - 3][y] = 254;
								s[x][y] = ship;
								return false;
							}
						}
						else
						{
							s[x - 2][y] = 254;
							s[x][y] = ship;
							return false;
						}
					}
					else
					{
						s[x][y] = ship;
						s[x - 1][y] = 254;
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				s[x][y] = 254;
				return false;
			}
		}
		else if (r == 'd')
		{
			if (x < 7)
			{
				if (check_s(s, r, size, x, y, 1))
				{
					s[x][y] = 254;
					s[x + 1][y] = ship;
					if (check_s(s, r, size, x + 1, y, 1))
					{
						s[x + 1][y] = 254;
						s[x + 2][y] = ship;
						if (check_s(s, r, size, x + 2, y, 1))
						{
							s[x + 2][y] = 254;
							s[x + 3][y] = ship;
							if (check_s(s, r, size, x + 3, y, 1))
							{
								s[x + 3][y] = 254;
								s[x][y] = ship;
								return true;
							}
							else
							{
								s[x + 3][y] = 254;
								s[x][y] = ship;
								return false;
							}
						}
						else
						{
							s[x + 2][y] = 254;
							s[x][y] = ship;
							return false;
						}
					}
					else
					{
						s[x][y] = ship;
						s[x + 1][y] = 254;
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				s[x][y] = 254;
				return false;
			}
		}
		else
		{
			s[x][y] = 254;
			return false;
		}
	}
	else
	{
		s[x][y] = 254;
		return false;
	}
}

void init_c(char**& comp_s, int size) {
	int x, y, r, count;
	char rotate{};
	bool b;
	do
	{
		count = 0;
		int x = 0, y = 0;
		b = true;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				comp_s[i][j] = 254;
			}
		}
		for (int i = 0; i < 2 && b; i++)
		{
			r = rand() % 4;
			if (r == 0)
				rotate = 'r';
			else if (r == 1)
				rotate = 'l';
			else if (r == 2)
				rotate = 'u';
			else if (r == 3)
				rotate = 'd';
			do
			{
				do
				{
					x = rand() % 10;
					y = rand() % 10;
				} while (comp_s[x][y] == ship);
				comp_s[x][y] = ship;
				count++;
				if (count > 100)
				{
					b = false;
					break;
				}
			} while (not check_s(comp_s, rotate, size, x, y, 4));
			if (rotate == 'r' && b)
			{
				comp_s[x][y + 1] = ship;
				comp_s[x][y + 2] = ship;
				comp_s[x][y + 3] = ship;
			}
			else if (rotate == 'l' && b)
			{
				comp_s[x][y - 1] = ship;
				comp_s[x][y - 2] = ship;
				comp_s[x][y - 3] = ship;
			}
			else if (rotate == 'u' && b)
			{
				comp_s[x - 1][y] = ship;
				comp_s[x - 2][y] = ship;
				comp_s[x - 3][y] = ship;
			}
			else if (rotate == 'd' && b)
			{
				comp_s[x + 1][y] = ship;
				comp_s[x + 2][y] = ship;
				comp_s[x + 3][y] = ship;
			}
		}
		for (int i = 0; i < 3 && b; i++)
		{
			count = 0;
			r = rand() % 4;
			if (r == 0)
				rotate = 'r';
			else if (r == 1)
				rotate = 'l';
			else if (r == 2)
				rotate = 'u';
			else if (r == 3)
				rotate = 'd';
			do
			{
				do
				{
					x = rand() % 10;
					y = rand() % 10;
				} while (comp_s[x][y] == ship);
				comp_s[x][y] = ship;
				count++;
				if (count > 100)
				{
					b = false;
					break;
				}
			} while (not check_s(comp_s, rotate, size, x, y, 3));
			if (rotate == 'r' && b)
			{
				comp_s[x][y + 1] = ship;
				comp_s[x][y + 2] = ship;
			}
			else if (rotate == 'l' && b)
			{
				comp_s[x][y - 1] = ship;
				comp_s[x][y - 2] = ship;
			}
			else if (rotate == 'u' && b)
			{
				comp_s[x - 1][y] = ship;
				comp_s[x - 2][y] = ship;
			}
			else if (rotate == 'd' && b)
			{
				comp_s[x + 1][y] = ship;
				comp_s[x + 2][y] = ship;
			}
		}
		for (int i = 0; i < 4 && b; i++)
		{
			count = 0;
			r = rand() % 4;
			if (r == 0)
				rotate = 'r';
			else if (r == 1)
				rotate = 'l';
			else if (r == 2)
				rotate = 'u';
			else if (r == 3)
				rotate = 'd';
			do
			{
				do
				{
					x = rand() % 10;
					y = rand() % 10;
				} while (comp_s[x][y] == ship);
				comp_s[x][y] = ship;
				count++;
				if (count > 100)
				{
					b = false;
					break;
				}
			} while (not check_s(comp_s, rotate, size, x, y, 2));
			if (rotate == 'r' && b)
				comp_s[x][y + 1] = ship;
			else if (rotate == 'l' && b)
				comp_s[x][y - 1] = ship;
			else if (rotate == 'u' && b)
				comp_s[x - 1][y] = ship;
			else if (rotate == 'd' && b)
				comp_s[x + 1][y] = ship;
		}
		for (int i = 0; i < 5 && b; i++)
		{
			count = 0;
			do
			{
				do
				{
					x = rand() % 10;
					y = rand() % 10;
				} while (comp_s[x][y] == ship);
				count++;
				if (count > 100)
				{
					b = false;
					break;
				}
				comp_s[x][y] = ship;
			} while (not check_s(comp_s, 'r', size, x, y, 1));
		}

	} while (not check(comp_s, size));
}

bool check_xy(char** s, int size, int x, int y) {
	if (x > 0 && x < 9 && y > 0 && y < 9)
	{
		if (s[x + 1][y + 1] != char(251) && s[x + 1][y - 1] != char(251) && s[x - 1][y + 1] != char(251) && s[x - 1][y - 1] != char(251) && s[x][y + 1] != char(251) && s[x][y - 1] != char(251) && s[x - 1][y] != char(251) && s[x + 1][y] != char(251))
			return true;
		else
			return false;
	}
	else if (x == 0)
	{
		if (y == 0)
		{
			if (s[x + 1][y + 1] != char(251) && s[x][y + 1] != char(251) && s[x + 1][y] != char(251))
				return true;
			else
				return false;
		}
		else if (y > 0 && y < 9)
		{
			if (s[x + 1][y + 1] != char(251) && s[x + 1][y - 1] != char(251) && s[x][y + 1] != char(251) && s[x][y - 1] != char(251) && s[x + 1][y] != char(251))
				return true;
			else
				return false;
		}
		else if (y == 9)
		{
			if (s[x + 1][y - 1] != char(251) && s[x][y - 1] != char(251) && s[x + 1][y] != char(251))
				return true;
			else
				return false;
		}
	}
	else if (x > 0 && x < 9)
	{
		if (y == 0)
		{
			if (s[x + 1][y + 1] != char(251) && s[x - 1][y + 1] != char(251) && s[x][y + 1] != char(251) && s[x - 1][y] != char(251) && s[x + 1][y] != char(251))
				return true;
			else
				return false;
		}
		else if (y == 9)
		{
			if (s[x + 1][y - 1] != char(251) && s[x - 1][y - 1] != char(251) && s[x][y - 1] != char(251) && s[x - 1][y] != char(251) && s[x + 1][y] != char(251))
				return true;
			else
				return false;
		}
	}
	else if (x == 9)
	{
		if (y == 0)
		{
			if (s[x - 1][y + 1] != char(251) && s[x][y + 1] != char(251) && s[x - 1][y] != char(251))
				return true;
			else
				return false;
		}
		else if (y > 0 && y < 9)
		{
			if (s[x - 1][y + 1] != char(251) && s[x - 1][y - 1] != char(251) && s[x][y + 1] != char(251) && s[x][y - 1] != char(251) && s[x - 1][y] != char(251))
				return true;
			else
				return false;
		}
		else if (y == 9)
		{
			if (s[x - 1][y - 1] != char(251) && s[x][y - 1] != char(251) && s[x - 1][y] != char(251))
				return true;
			else
				return false;
		}
	}
	else
		return false;
}

void main() {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(0));
	const int size = 10;
	char** square = new char* [size] {};
	char** comp_s = new char* [size] {};
	char** square_c = new char* [size] {};
	int x = 4, y = 4, count = 0, count_c = 0, c_x = -1, c_y = -1;
	char c = 0;
	for (int i = 0; i < size; i++)
	{
		square[i] = new char[size] {};
	}
	for (int i = 0; i < size; i++)
	{
		comp_s[i] = new char[size] {};
	}
	for (int i = 0; i < size; i++)
	{
		square_c[i] = new char[size] {};
	}
	init(square, size);
	while (count <= 30)
	{
		system("cls");
		print_s(square, size, x, y);
		if (count == 30)
		{
			if (check(square, size))
			{
				break;
			}
			else
			{
				cout << "\n ------------------ Please Try Again ------------------ \n";
				Sleep(1500);
				init(square, size);
				count = 0;
				continue;
			}
		}
		c = _getch();
		if (c == -32)
		{
			c = _getch();
			if (c == right)
			{
				if (y == 9)
					y = -1;
				if (square[x][y + 1] == ship)
				{
					int i = 0;
					do
					{
						if (y + 1 < 10)
						{
							y++;
						}
						else
						{
							y = 0;
						}
						i++;
					} while (square[x][y] == ship && i < 10);
				}
				else
					y++;
			}
			else if (c == left)
			{
				if (y == 0)
					y = 10;
				if (square[x][y - 1] == ship)
				{
					int i = 0;
					do
					{
						if (y - 1 >= 0)
							y--;
						else
							y = 9;
						i++;
					} while (square[x][y] == ship && i < 10);
				}
				else
					y--;
			}
			else if (c == up)
			{
				if (x == 0)
					x = 10;
				if (square[x - 1][y] == ship)
				{
					int i = 0;
					do
					{
						if (x - 1 >= 0)
							x--;
						else
							x = 9;
						i++;
					} while (square[x][y] == ship && i < 10);
				}
				else
					x--;
			}
			else if (c == down)
			{
				if (x == 9)
					x = -1;
				if (square[x + 1][y] == ship)
				{
					int i = 0;
					do
					{
						if (x + 1 < 10)
						{
							x++;
						}
						else
						{
							x = 0;
						}
						i++;
					} while (square[x][y] == ship && i < 10);
				}
				else
					x++;
			}
			square[x][y] = 254;
		}
		else if (c == enter)
		{
			if (square[x][y] != ship)
			{
				square[x][y] = ship;
				count++;
			}
		}
		else if (c == space)
		{
			init(square, size);
			count = 0;
		}
	}
	init_c(comp_s, size);
	init(square_c, size);
	x = 4;
	y = 4;
	count = 0;
	while (count < 30 && count_c < 30)
	{
		system("cls");
		print_s(square, size, c_x, c_y);
		print_s(square_c, size, x, y);
		c = _getch();
		if (c == -32)
		{
			c = _getch();
			if (c == right)
			{
				if (y == 9)
					y = -1;
				if (square_c[x][y + 1] == 'x' || square_c[x][y + 1] == char(251))
				{
					int i = 0;
					do
					{
						if (y + 1 < 10)
						{
							y++;
						}
						else
						{
							y = 0;
						}
						i++;
					} while ((square_c[x][y] == 'x' || square_c[x][y] == char(251)) && i < 10);
				}
				else
					y++;
			}
			else if (c == left)
			{
				if (y == 0)
					y = 10;
				if (square_c[x][y - 1] == 'x' || square_c[x][y - 1] == char(251))
				{
					int i = 0;
					do
					{
						if (y - 1 >= 0)
							y--;
						else
							y = 9;
						i++;
					} while ((square_c[x][y] == 'x' || square_c[x][y] == char(251)) && i < 10);
				}
				else
					y--;
			}
			else if (c == up)
			{
				if (x == 0)
				{
					x = 10;
				}
				if (square_c[x - 1][y] == 'x' || square_c[x - 1][y] == char(251))
				{
					int i = 0;
					do
					{
						if (x - 1 >= 0)
						{
							x--;
						}
						else
						{
							x = 9;
						}
						i++;
					} while ((square_c[x][y] == 'x' || square_c[x][y] == char(251)) && i < 10);
				}
				else
				{
					x--;
				}
			}
			else if (c == down)
			{
				if (x == 9)
				{
					x = -1;
				}
				if (square_c[x + 1][y] == 'x' || square_c[x + 1][y] == char(251))
				{
					int i = 0;
					do
					{
						if (x + 1 < 10)
						{
							x++;
						}
						else
						{
							x = 0;
						}
						i++;
					} while ((square_c[x][y] == 'x' || square_c[x][y] == char(251)) && i < 10);
				}
				else
				{
					x++;
				}
			}
			square_c[x][y] = 254;
		}
		else if (c == enter)
		{
			if (square_c[x][y] != 'x' && square_c[x][y] != char(251))
			{
				if (comp_s[x][y] == char(ship))
				{
					square_c[x][y] = char(251);
					count++;
				}
				else
				{
					square_c[x][y] = 'x';
					while (count_c < 30)
					{
						system("cls");
						print_s(square, size, c_x, c_y);
						print_s(square_c, size, x, y);
						c_x = rand() % 10;
						c_y = rand() % 10;
						while ((square[c_x][c_y] == 'x' || square[c_x][c_y] == char(251)) && not check_xy(square, size, c_x, c_y))
						{
							c_x = rand() % 10;
							c_y = rand() % 10;
						}
						Sleep(500);
						if (square[c_x][c_y] == char(ship))
						{
							square[c_x][c_y] = char(251);
							count_c++;
						}
						else
						{
							square[c_x][c_y] = 'x';
							break;
						}
					}
				}
			}
		}
	}
	if (count == 30)
	{
		SetConsoleTextAttribute(color, green);
		cout << " \n\n\n -------------------- Your Win -------------------- \n";
		SetConsoleTextAttribute(color, white);
	}
	else
	{
		SetConsoleTextAttribute(color, red);
		cout << " \n\n\n -------------------- Computer Win -------------------- \n";
		SetConsoleTextAttribute(color, white);
	}
}