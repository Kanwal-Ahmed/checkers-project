
#include<iostream>
#include "CheckersBoard.h"
using namespace std;

class whitePiece : public Board
{
public:
	int w_pieces(char b[8][8])
	{
		int bNum = 0;
		for (int ii = 0; ii < 8; ++ii)
		{
			for (int jj = 0; jj < 8; ++jj)
			{
				if (b[ii][jj] == 'w' || b[ii][jj] == 'W')
				{
					bNum++;
				}
			}
		}
		int wTaken = 12 - bNum;

		return wTaken;
	}

private:
	int wpieces;
	int wTaken;
};

