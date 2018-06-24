
#include "CheckersBoard.h"
#include "CheckersPlayer.h"
#include <iostream>
#include <time.h>
#include <ctype.h>
using namespace std;

int main()
	{
		cout << "\n\n----WELCOME TO PLAY OUR CHAEKERS GAME----\n" << endl;
		cout << " ----CHECKERS GAME DATA RECORD---- " << endl;
		CheckerPlayer p;
		p.getplayername();
		p.storeplayerdata();
		cout << "\nHistory Of Players Who Tried Our Game : " << endl;
		p.viewallrecord();
		system("pause");
		srand(time(0));
		int i = 0, m = 0;
		Board play_game;
		play_game.instructions();
		system("pause");
		play_game.setpieces();
		play_game.printb();
		cout << "Computer Move...." << endl;
		do
		{
			play_game.findp();
			m = play_game.checkwin();
			if (m == 0)
			{
				i = 100;
			}
			play_game.printb();
			++i;
			play_game.human_move();
			m = play_game.checkwin();
			if (m == 0)
			{
				i = 100;
			}
			play_game.printb();
			++i;
		} while (i < 100);

	}
