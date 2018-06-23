#include <iostream>
#include <time.h>
#include <ctype.h>

using namespace std;
class Board 
{
public:
	~Board() {};
	Board();
	void printb();
	void human_move();
	void computer_move();
	void instructions();
	void setpieces();
	int checkwin();
	int trymove(int r, int c);
	void findp();

private:
	char cboard[9][9];

};
