#include "stdafx.h"
#include "iostream"
#include <string>
using namespace std;
class Student{
private:
	int StNo;
	int Stgrade ;	//学生年级   eg：大二、大一
	string StName ;
	string Stmajor ;
	string StCollege ;
	string Stsex ;
	int StAge ;
	int Stbirthday ;
	string StCity ;
	string StPhone ;
    	string StId ;
    	string StQQ  ;
    	float Stnowcredit ;
public:
	Student(){
		StNo=0;
		Stgrade=0;
		StName="";
		Stmajor="";
		StCollege="";
		Stsex="";
		StAge=0;
		Stbirthday=0;
		StCity="";
		StPhone="";
		StId="";
		StQQ="";
		Stnowcredit=0;
	};
	Student(int StNo,int Stgrade ,string StName ,string Stmajor ,string StCollege ,string Stsex ,
	int StAge ,int Stbirthday ,string StCity ,string StPhone ,string StId ,string StQQ ,
    float Stnowcredit){
	this->StNo = StNo;
	this->Stgrade = Stgrade;
	this->StName = StName;
	this->Stmajor = Stmajor;
	this->StCollege = StCollege;
	this->Stsex = Stsex;
	this->StAge = StAge;
	this->Stbirthday = Stbirthday;
	this->StCity = StCity;
	this->StPhone= StPhone;
	this->StId = StId;
	this->StQQ = StQQ;
	this->Stnowcredit = Stnowcredit;
	};
	~Student(){};
	int Student::getStNo(){
		return this->StNo;}
    int Student::getStgrade(){
		return this->Stgrade;}
	string Student::getStName(){
		return this->StName;}
    string Student::getStmajor(){
		return this->Stmajor;}
	string Student::getStCollege(){
		return this->StCollege;}
	string Student::getStsex(){
		return this->Stsex;}
	int Student::getStAge(){
		return this->StAge;}
	int Student::getStbirthday(){
		return this->Stbirthday;}
	string Student::getStCity(){
		return this->StCity;}
    string Student::getStPhone(){
		return this->StPhone;}
	string Student::getStId(){
		return this->StId;}
	string Student::getStQQ(){
		return this->StQQ;}
	float Student::getStnowcredit(){
		return this->Stnowcredit;}
	void Student::toString(){
		cout<<"学号："<<StNo<<"，年级："<<Stgrade<<"，姓名："<<StName<<"，专业："<<Stmajor
		<<"，学院："<<StCollege<<"，性别："<<Stsex<<"，年龄："<<StAge
		<<"，生日："<<Stbirthday<<"，家乡："<<StCity<<"，手机号："<<StPhone
		<<"，邮箱："<<StId<<"，QQ："<<StQQ<<"，当前学分："<<Stnowcredit<<endl;
	}
};
