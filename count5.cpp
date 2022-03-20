#include<iostream>
#include<string>
#include<fstream>
#include<cstdio>
using namespace std;

int main(){
string name,location,branch;
int id;
fstream myfile;
myfile.open("assign5.txt",ios::app|ios::out);
int c=0;
do{
cout<<"enter 1 to enter student detail and 2 to find student"<<endl;
cin>>c;
switch(c){

case 1: cout<<"enter student name,id,branch,location"<<endl;
	cin>>name>>id>>branch>>location;
	myfile<<name<<" ";
	myfile<<id<<" ";
	myfile<<branch<<" ";
	myfile<<location<<endl;	
	break;
case 2: myfile.close();
	myfile.open("assign5.txt",ios::in);
	string i;
	int flag=0;
	string str;
	cout<<"enter id of student"<<endl;
	cin>>i;
	int line_count=0;
	int line=0;
	while(getline(myfile,str)){ 
	line_count+=1;
	for(int j=0;j<str.length();j++){
	if(str[j]==i[0]){
	flag=1;
	line=line_count;
	break;
			}
		}
	}
	
	try{
	if(flag==0){
	throw flag;
	break;
		
		}
	else{
	string read;
	myfile.close();
	myfile.open("assign5.txt",ios::in);
	for(int j=1;j<=line;j++){
	getline(myfile,read);
		}
	cout<<read<<endl;
	break;}
		}
		
	catch(int x){
		cout<<"student id not found"<<endl;
	
			}
	
	


}





}while(c!=3);
myfile.close();





return 0;
}
