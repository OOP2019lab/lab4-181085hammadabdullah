
#include "stdafx.h"
#include "q1_18l1085.h"
cricketteam::cricketteam(){
	int Scoreinlast10matches[10];
	for(int i=0;i<10;i++){
		Scoreinlast10matches[i]=0;
	}
	 Rank=0;
	 no_of_members=0;
	teamName=nullptr;
	 membernames=nullptr;
}
cricketteam::cricketteam(string name, int No_of_members){
		teamName = new char[name.length() + 1];
		int i=0;
		for(;i<name.length();i++){
		teamName[i] = name[i];
		}
		teamName[i]='\0';
		no_of_members = No_of_members;
		membernames = new string[no_of_members];
		Rank = 0;
		i=0;
		for(;i<10;i++){
			Scoreinlast10matches[i] = 0;
		}
		captain = "";
}
cricketteam::cricketteam(string filename){
	ifstream fin(filename.c_str());
	string arr;
	int a=0;
	getline(fin, arr);
	int index = 0;
	for(;arr[index]!=':';index++)
	{
	}
	teamName = new char[arr.length() - index];
	index++;
	int j=0;
	for(int i=index;i<arr.length();i++,j++){
		teamName[j]=arr[i];
	}
	teamName[j]='\0';
	getline(fin,arr,':');
	fin>>a;
	no_of_members=a;
	membernames=new string[no_of_members];
	getline(fin,arr);//Line To skip Prevois Line
	for(int i=0;i<no_of_members;i++)
	{
		getline(fin,arr);
		membernames[i] = arr;
	}
	getline(fin,arr,':');
	fin>>a;
	Rank=a;
	getline(fin,arr);//Line To skip Prevois Line
	index=0;
	cout<<endl;
	//..................................................................
	getline(fin, arr);
	for(;arr[index]!=':';index++)
	{
	}
	captain = new char[arr.length() - index];
	index++;
	j=0;
	for(int i=index-1;i<arr.length();i++,j++){
		captain[j]=arr[i];
	}
	j=0;
	captain[j]='\0';
	string str[5];
	getline(fin,arr,':');
	while(!fin.eof()){
		getline(fin,arr,',');
		a=stoi(arr);
		Scoreinlast10matches[j]=a;
		j++;
	}
}
void cricketteam::print(){

	cout<<"The Name Of Team is :"<<teamName<<endl;
	cout<<"The Total Members Are :"<<no_of_members<<endl;
	cout<<"The Members Are:"<<endl;
	for(int i=0;i<no_of_members;i++){
		cout<<membernames[i]<<endl;
	}
	cout<<"The Rank Is :"<<Rank<<endl;
	cout<<"The Captain Is :"<<captain<<endl;
	cout<<"The SCore Is :"<<endl;
	for(int i=0;i<10;i++){
		cout<<Scoreinlast10matches[i]<<",";
	}

}
void cricketteam::setcaptain(string Captain){

	captain=Captain;
}
string cricketteam::getcaptain(){

	return captain;
}
void cricketteam::setrank(int rank){
	Rank=rank;
}
int cricketteam::getrank(){
	return Rank;
}
void cricketteam::setnoofmembers(int NOofmembers){
	no_of_members=NOofmembers;
}
int cricketteam::getnoofmembers(){
	return no_of_members;
}
void cricketteam::setteamname(char *Teamname){
	if(teamName!=nullptr){
		teamName=Teamname;
	}
	else{//Case In Which there is no teamName Before
	int i=0;
	for(;Teamname[i]!='\0';i++){
	}
	teamName=new char[i+1];
	teamName=Teamname;
}
}
char *cricketteam::getteamname(){
	return teamName;
}
void cricketteam:: inputteammemberName(string name){
int i=0;
for(;membernames[i]!="\0"  && i<=no_of_members;i++){          //Count The Team Members
}
if(i>=no_of_members){
cout<<"No Space For New Member :";
}
else if(i<no_of_members){
	membernames[i]=name;
}
}
void cricketteam::inputscore(int score){
int i=0;
for(;Scoreinlast10matches[i]!=0;i++){//To calculate Number Of score Matches
}
if(i>=10){
	for(int j=i;j<10;j++){//Case If Score Array Is Full And we have to shift that numbers to left;
		Scoreinlast10matches[j]=Scoreinlast10matches[j+1];
		}
	Scoreinlast10matches[9]=score;
}
else if(i<10){
	Scoreinlast10matches[i]=score;
}
}
int cricketteam::avgof10matches(int &avg){
	int sum=0;
	for(int i=0;i<10;i++){
		sum=sum+Scoreinlast10matches[i];
	}
	avg=sum/10;
	return avg;
}
void cricketteam::printlatestscore(){
int i=0;
for(;Scoreinlast10matches[i]!=0 && i<10;i++){//To Find out Latest Score From Score arraY;
}
	cout<<"The Latest Socre Of Team Is :"<<Scoreinlast10matches[i-1]<<endl;
	cout<<"The Captain Of Team is :"<<captain<<endl;
	cout<<"The Team Name Is :"<<teamName<<endl;
}
bool cricketteam::betterteam(cricketteam& anotherteam){
	
	int avg1=0;
	int avg2=0;
	int sum=0;
	for(int i=0;i<10;i++){
	sum=sum+anotherteam.Scoreinlast10matches[i];
	}
	avg1=sum/10;
	sum=0;
	for(int i=0;i<10;i++){
	sum=sum+Scoreinlast10matches[i];
	}
	avg2=sum/10;
	if(avg1>avg2){
		cout<<anotherteam.teamName<<" is Better Than "<<teamName;
		return true;
	}
	 if(avg1<avg2){
	cout<<teamName<<" is Better Than "<<anotherteam.teamName;
		return false;
	}
}
void cricketteam::takedataforanotherteam(cricketteam& anotherteam){
	string arr;
	getline(cin,arr);
cout<<"Enter Name Of Team :";
getline(cin,arr);
int a=arr.length();
anotherteam.teamName=new char[a+1];
int i=0;
for(;arr[i]!='\0';i++){
anotherteam.teamName[i]=arr[i];
}
i=0;
cout<<"Enter Your NO Of Members :";
cin>>a;
anotherteam.no_of_members=a;
anotherteam.membernames=new string[anotherteam.no_of_members];
getline(cin,arr);
cout<<"Enter Your Members Name :";
for(int j=0;j<anotherteam.no_of_members-1;j++){
getline(cin,arr);
anotherteam.membernames[j]=arr;
}
getline(cin,arr);
cout<<"Enter Name Of Captain :";
getline(cin,arr);
a=arr.length();
anotherteam.captain=new char[a];
i=0;
for(;arr[i]!='\0';i++){
	captain[i]=arr[i];
}
cout<<"Enter Rank Of Team :";
cin>>a;
anotherteam.Rank=a;
cout<<"Enter Your Score Of LAst 10 Matches :";
for(int g=0;g<10;g++){
cin>>a;
anotherteam.Scoreinlast10matches[g]=a;
}
}
//cricketteam::~cricketteam(){
//	delete [] membernames;
//	delete [] teamName;
//} This Destrutor Calls Automatically And Crash The Program

