
#include "CheckersPlayer.h"
#include<iostream>
#include<string.h>
#include <fstream>
#include<string>

CheckerPlayer::CheckerPlayer()
{
	/*cout << "White Player=> ";
	white_player = "white";
	cout << "Red Player=>";
	red_player = "red";*/
}
CheckerPlayer::CheckerPlayer(string w, string r)
{
	cout << "White Player=>";
	white_player = w;
	cout << "Red Player=>";
	red_player = r;
}
CheckerPlayer::CheckerPlayer(CheckerPlayer& copy)
{
	cout << "White Player=>";
	white_player = copy.white_player;
	cout << "Red Player=>";
	red_player = copy.red_player;
}
void CheckerPlayer::getplayername()
{
	cout << "Enter Player1 name :" << endl;
	cin >> white_player;
	cout << "Enter Player2 name :" << endl;
	cin >> red_player;
}
void CheckerPlayer::showplayerdata()
{
	cout << "\n" << white_player << "\n" << red_player << endl;
}
void CheckerPlayer::turn()
{
	counter = 0;
	if (counter % 2 == 0 || counter == 0)
	{
		cout << "Red Turn" << endl;
	}
	else if (counter % 2 == 1)
	{
		cout << "White Turn" << endl;
	}
	++counter;
}
void CheckerPlayer::king_piece(char b[8][8])// turns pieces into kings if conditions are met
{
	for (int ii = 0; ii < 8; ++ii)
	{
		if (b[0][ii] == 'r')
		{
			b[0][ii] = 'R';
		}
		else if (b[7][ii] == 'w')
		{
			b[7][ii] = 'W';
		}
	}
}
int CheckerPlayer::storeplayerdata()
{
	if (white_player == "white", red_player == "red")
	{
		cout << "Players data not initialized";
		return (0);
	}
	else
	{
		ofstream checkplay;
		checkplay.open("checker.txt", ios::app);
		checkplay << *this;
		checkplay.close();
		return (1);
	}
}
void CheckerPlayer::viewallrecord()
{
	ifstream finput;
	CheckerPlayer temp;
	finput.open("checker.txt");
	if (!finput) {
		cout << "\nFile not found" << endl;
	}
	else
	{

		while (!finput.eof())
		{
			finput >> temp;
			temp.showplayerdata();
		}
		finput.close();
	}

}