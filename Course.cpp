#include "stdafx.h"
#include "iostream"
#include <string>
using namespace std;
class Course{
private:
	int Stgrade;   //�꼶
	int Cyear;	//���
	int Cterm;	//ѧ��    eg�����ǡ�������꼶���鿴��2014����ݵڡ�2��ѧ�ڿγ�
	string Cno;
	string Cname;
	int Tno;
	string Tname;
	string Cplace;
	string Ctime;
	string Ccollege;
	int Ctype;
	float Ccredit;
public:
	Course(){
		Stgrade=0;
		Cyear=0;
		Cterm=0;
		Cno="";
		Tno=0;
		Tname="";
		Cplace="";
		Ctime="";
		Ccollege="";
		Ctype=0;
		Ccredit=0;
	};
	Course(int Stgrade,int Cyear,int Cterm,string Cno,string Cname,int Tno,string Tname,string Cplace,string Ctime,string Ccollege,int Ctype,float Ccredit)
	{
	this->Stgrade = Stgrade;
	this->Cyear = Cyear;
	this->Cterm = Cterm;
	this->Cno = Cno;
	this->Cname = Cname;
	this->Tno = Tno;
	this->Tname = Tname;
	this->Cplace = Cplace;
	this->Ctime=Ctime;
	this->Ccollege = Ccollege;
	this->Ctype = Ctype;
	this->Ccredit = Ccredit;
	};
	~Course(){};
    int Course::getStgrade(){
		return this->Stgrade;}
    int Course::getCyear(){
		return this->Cyear;}
    int Course::getCterm(){
		return this->Cterm;}
    string Course::getCno(){
		return this->Cno;}
    string Course::getCname(){
		return this->Cname;}
    int Course::getTno(){
		return this->Tno;}
    string Course::getTname(){
		return this->Tname;}
    string Course::getCplace(){
		return this->Cplace;}
    string Course::getCtime(){
		return this->Ctime;}
    string Course::getCcollege(){
		return this->Ccollege;}
    int Course::getCtype(){
		return this->Ctype;}
    float Course::getCcredit(){
		return this->Ccredit;}
	void Course::toString(){
		cout<<"�꼶��"<<Stgrade<<"����ݣ�"<<Cyear<<"��ѧ�ڣ�"<<Cterm<<"���γ̺ţ�"<<Cno<<"���γ�����"<<Cname<<"����ʦ�ţ�"<<Tno<<"����ʦ����"<<Tname
		<<"���ص㣺"<<Cplace<<"��ʱ�䣺"<<Ctime<<"��ѧԺ��"<<Ccollege<<"�����ͣ�"<<Ctype<<"��ѧ�֣�"<<Ccredit<<endl;
	}
};
