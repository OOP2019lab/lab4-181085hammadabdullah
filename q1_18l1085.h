#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <conio.h>
using namespace std;
class cricketteam{
private:
string * membernames;
int no_of_members;
char *teamName;
int Scoreinlast10matches[10];
int Rank;
string captain;

public:
	cricketteam();
	cricketteam(string name, int no_of_members);
	cricketteam(string filename);
	string getcaptain();
	void setcaptain(string Captain);
	int getrank();
	void setrank(int Rank);
	char *getteamname();
	void setteamname(char *Teamname);
	void getnoofmembers(int Noofmembers);
	void setnoofmembers(int Noofmembers);
	int getnoofmembers();
	void print();
	void inputteammemberName(string name);
	void inputscore(int score);
	int avgof10matches(int &avg);
	void printlatestscore();
	void takedataforanotherteam(cricketteam& anotherteam);
	bool betterteam(cricketteam& anotherteam);
	void deallocate(cricketteam arr);
	//~cricketteam();

};
