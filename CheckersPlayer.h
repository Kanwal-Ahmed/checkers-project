#include<iostream>
#include<string.h>
#include <fstream>
#include<string>

using namespace std;

class CheckerPlayer
{
public:
	CheckerPlayer();
	CheckerPlayer(string w, string r);
	CheckerPlayer(CheckerPlayer& copy);
	void getplayername();
	void showplayerdata();
	int storeplayerdata();
	void viewallrecord();
	void turn();
	void king_piece(char b[8][8]);// turns pieces into kings if conditions are met

	friend istream& operator >> (istream& is, CheckerPlayer& cp)
	{
		return is >> cp.white_player >> cp.red_player;
	}

	friend ostream& operator << (ostream& io, CheckerPlayer& cp)
	{
		return io << " " << cp.white_player << " " << cp.red_player;
	}



private:
	string white_player;
	string red_player;
	int counter;
};
