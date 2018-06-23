
#include "CheckersBoard.h"
#include <iostream>
#include <time.h>
#include <ctype.h>

Board::Board()
{
	char w = 177;
	int row, column, side = 0, top = 0;
	cout << "\n\n  Initializing the Checkers Board........" << endl;
	cout << "    0  1  2  3  4  5  6  7 " << endl;
	cout << "----------------------------" << endl;
	for (row = 0;row<8;row++)
	{
		cout << side << " |";
		++side;

		for (column = 0;column<8;column++)
			if ((row + column) % 2 == 0)
				cboard[row][column] = w;
			else
				cboard[row][column] = 0;
		cout << "|" << endl;
	}
	cout << "----------------------------" << endl;
}
void Board::computer_move()
{ }
void Board::setpieces()
{
	int row = 0, column = 0;
	for (row = 1;row <= 8;row++)
		for (column = 1;column <= 8;column++)
		{
			if ((row + column) % 2 == 0 && row <= 3)
				cboard[row][column] = 'w';
			else if ((row + column) % 2 == 0 && row>2 && row <= 5)
				cboard[row][column] = 177;
			else if ((row + column) % 2 == 0 && row>5 && row <= 8)
				cboard[row][column] = 'b';
			else
				cboard[row][column] = 0;
		}
}
int Board::checkwin()
{
	int i, j;
	for (i = 1;i <= 8;++i)
		for (j = 1;j <= 8;++j)
		{
			if (cboard[i][j] == 'w' || cboard[i][j] == 'b')
			{
				cout << "\nContinue playing....." << endl;
				return (1);
			}
			else if (cboard[i][j] != 'w')
			{
				cout << "\nCOMPUTER WINS!!!\n" << endl;
				return(0);
			}
			else if (cboard[i][j] != 'b')
			{
				cout << "\nHUMAN WINS!!!!\n" << endl;
				return(0);
			}
		}
}
void Board::findp()
{
	int i, v = 0, j;
	do
	{
		for (i = 0;i <= 7;++i)
		{
			for (j = 0;j <= 7;++j)
			{
				if (cboard[i][j] == 'b')
				{
					v = trymove(i, j);
					if (v == 1)
					{
						i = 10;
						j = 10;
					}
				}
				else
					cout << "INVALID MOVE" << endl;
			}
			cout << "\n\n" << endl;
		}
	} while (v != 1);
}
int Board::trymove(int r, int c)                                    // R AND C REPRESENT ORIGINAL LOCATION OF THE PIECE
{
	if (r>1 && c>1)
	{
		if (cboard[r][c] == 'b')
		{
			cout << "Computer1: " << r << " " << c << endl;
			cboard[r][c] = 177;
			cboard[r - 1][c - 1] = 'b';
			cout << "The computer moves from row: " << r << endl;
			cout << "The computer moves from column: " << c << endl;
			cout << "To row: " << r - 1 << endl;
			cout << "To column: " << c - 1 << endl;
			return(1);
		}
		else if (cboard[r][c] == 177)
		{
			cout << "Computer2" << endl;
			cboard[r][c] = 177;
			cboard[r - 1][c + 1] = 'b';
			cout << "The computer moves from row: " << r << endl;
			cout << "The computer moves from column: " << c << endl;
			cout << "To row: " << r - 1 << endl;
			cout << "To column: " << c + 1 << endl;
			return(1);
		}
		else if (cboard[r - 1][c - 1] == 'w'&&cboard[r - 2][c - 2] == 177)
		{
			cboard[r][c] == 177;
			cboard[r - 1][c - 1] == 177;
			cboard[r - 2][c - 2] == 'b';
			return(1);
		}
	}
}

void Board::instructions()
{
	int i = 0;
	char s = 4;
	for (i = 0;i <= 53;++i)
	{
		cout << s;
	}
	cout << "\n **WELCOME TO PLAY OUR CHECKERS GAME** \n\n";
	cout << endl << s << "  THESE ARE THE INSTRUCTION FOR CHECKERS!          \n " << s << endl;
	cout << s << "  1) The computer is represented by a 'q'           " << s << endl;
	cout << s << "  2) The human is represented by a 'h'              " << s << endl;
	cout << s << "  3) When a piece is kinged it will be capitalized  " << s << endl;
	cout << s << "  4) When a piece is kinged it may move backwards   " << s << endl;
	cout << s << "  5) The computer will move first each time       \n\n  " << s << endl;
	for (i = 0;i <= 53;++i)
	{
		cout << s;
	}
	cout << endl;
}
void Board::printb()
{
	char w = 177;
	int row, column;
	cout << "    1  2  3  4  5  6  7  8" << endl;
	cout << "----------------------------" << endl;
	for (row = 1;row <= 8;row++)
	{
		cout << row << " |";
		for (column = 1;column <= 8;column++)
			if ((row + column) % 2 == 0)
				cout << w << cboard[row][column] << w;
			else
				cout << " " << cboard[row][column] << " ";
		cout << "|" << endl;

	}
	cout << "----------------------------" << endl;
}
void Board::human_move()
{
	int oldrow = 1, oldcolumn = 1, row = 1, column = 1;
	char w = 177, h = 104;
	do
	{
		cout << "Enter the row of the piece you would like to move from: " << endl;
		cin >> oldrow;
		cout << "Enter the column of the piece you would like to move from: " << endl;
		cin >> oldcolumn;
		cout << "Enter the new row you would like to move the piece to: " << endl;
		cin >> row;
		cout << "Enter the new column you would like to move the piece to: " << endl;
		cin >> column;
		if (cboard[row][column] == 0)
		{
			cout << "INVALID MOVE" << endl;
			oldrow = 0;
		}
		if (oldrow >= 1 && oldcolumn >= 1)
		{
			if (cboard[oldrow][oldcolumn] != 'w')
			{
				cout << "INVALID MOVE" << endl;
				oldrow = 0;
			}
			else if (cboard[oldrow][oldcolumn] == 'w')
			{
				cout << "Computer1" << endl;
				cboard[oldrow][oldcolumn] = 177;
				cboard[row - 1][column - 1] = 177;
				cboard[row][column] = 'w';
			}
			else if (cboard[row - 1][column - 1] == 'w')
			{
				cout << "HELLO AGAIN" << endl;
				cboard[oldrow][oldcolumn] = 177;
				cboard[row - 1][column - 1] = 177;
				cboard[row][column] = 'w';
			}
			else
			{
				cout << "INVALID MOVE 2\n\n" << endl;
			}
		}
		cout << "The user moves from row: " << oldrow << endl;
		cout << "The user moves from column: " << oldcolumn << endl;
		cout << "To row: " << row << endl;
		cout << "To column: " << column << endl;

	} while (oldrow<1 || oldcolumn<1 || row<1 || column<1 || oldrow>8 || oldcolumn>8 || row>8 || column>8);
}