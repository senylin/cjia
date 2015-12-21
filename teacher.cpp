#include "stdafx.h"
#include "iostream"
#include <string>
using namespace std;
class Teacher{
private:
	int Tno;
	string Tname ;
	string Tsex ;
	int Tage ;
	string Tcollege ;//所属学院
public:
	Teacher(){
		Tno=0;
		Tname="";
		Tsex="";
		Tage=0;
		Tcollege="";
	};
	Teacher(int Tno ,string Tname ,string Tsex ,int Tage ,string Tcollege){
	this->Tno = Tno;
	this->Tname = Tname;
	this->Tsex = Tsex;
	this->Tage = Tage;
	this->Tcollege = Tcollege;
	};
	~Teacher(){};
    int Teacher::getTno(){
		return this->Tno;}
    string Teacher::getTname(){
		return this->Tname;}
    string Teacher::getTsex(){
		return this->Tsex;}
    int Teacher::getTage(){
		return this->Tage;}
    string Teacher::getTcollege(){
		return this->Tcollege;}
	void Teacher::toString(){
		cout<<"教师号："<<Tno<<"，教师名："<<Tname<<"，性别："<<Tsex<<"，年龄："<<Tage<<"，学院："<<Tcollege<<endl;
	}
};
