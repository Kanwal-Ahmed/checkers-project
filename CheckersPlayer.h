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
	void getWplayername();
  void getBplayername();
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
	cout << "Enter HumanPlayer name :" << endl;
	cin >> white_player;
}

void CheckerPlayer::getWplayername()
{
	cout << "Enter Player name :" << endl;
	cin >> white_player;
}

void CheckerPlayer::getBplayername()
{
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
	if (white_player == "white")
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