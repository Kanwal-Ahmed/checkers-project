
#include<iostream>
#include "CheckersBoard.h"
using namespace std;

class blackPiece : public Board
{
public:
	int b_pieces(char b[8][8])
	{
		int bNum = 0;
		for (int ii = 0; ii < 8; ++ii)
		{
			for (int jj = 0; jj < 8; ++jj)
			{
				if (b[ii][jj] == 'b' || b[ii][jj] == 'B')
				{
					bNum++;
				}
			}
		}
		int bTaken = 12 - bNum;

		return bTaken;
	}

private:
	int bpieces;
	int bTaken;
};
