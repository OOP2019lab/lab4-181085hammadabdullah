#include "stdafx.h"
#include "q1_18l1085.h"
int main(){
	string str;
	int a=0;int b=0;char *Teamname;int s=0;int avg=0;
	cricketteam c1=cricketteam("file1.txt");
	c1.print();
	cout<<endl;
	c1.printlatestscore();//Function For Print Latest Score With Captain Name And Team Name
	//Testing Of Getter and Setter Funcions
	cout<<"After Setting New Items :";
	c1.setcaptain("waseem Akram");//set New Captain
	str=c1.getcaptain();
	cout<<"The New Cpatain is :"<<str<<endl;
	c1.setrank(3);//Set New Rank
	a=c1.getrank();
	cout<<"The New Rank Is :"<<a<<endl;
	c1.setnoofmembers(12);//Set new No Of members
	b=c1.getnoofmembers();
	cout<<"The New No Of Members Is :"<<b<<endl;
	c1.setteamname("Pakistan Tigers");// Set New Team Name
	Teamname=c1.getteamname();
	cout<<"The New Team Name Is :"<<Teamname<<endl;
	//Getter and setter function End;
	//Input Functions
	//Function N0 1
	cout<<"Plzz Enter Name Of Member Of team :";
	getline(cin,str);
	c1.inputteammemberName(str);
	//Function No 2
	cout<<endl;
	cout<<"Plz Enter New Score Of Team :";
	cin>>s;
	c1.inputscore(s);
	//Input Function End
	//Average Of Last Ten Matchse
	int d=c1.avgof10matches(avg);
	cout<<"Average Of Ten Matches Are :"<<d<<endl;
	system("CLS");
	//Now Comparing Function starts
	cricketteam c2;
	c2.takedataforanotherteam(c2);
	c1.betterteam(c2);
	system("Pause");
	c1.deallocate(c1);
	c2.deallocate(c2);
	return 0;
}