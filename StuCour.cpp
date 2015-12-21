#include "stdafx.h"
#include "iostream"
#include <string>
using namespace std;
class StuCourse{
private:
	//St开头的是学生，C开头的是课程，T开头的是老师，SC开头的是选课
	int StNo;		
	int Stgrade;	//学生年级
	string StName;	
	string Stmajor;
	string Cno ;
	string Cname;
	string Tname;
	int Ctype;
	float Ccredit;
	string SCstatus ;
	string SCscore ;
public:
	StuCourse(){
        StNo=0;
        Stgrade=0;
        StName="";
        Stmajor="";
        Cno="";
        Cname="";
        Tname="";
        Ctype=0;
        Ccredit=0;
        SCstatus="";
        SCscore="";
	};
	StuCourse(int StNo,int Stgrade,string StName,string Stmajor,string Cno ,string Cname,string Tname,int Ctype,float Ccredit,string SCstatus ,string SCscore ){
		this->StNo = StNo;
		this->Stgrade = Stgrade;
		this->StName = StName;
		this->Stmajor = Stmajor;
		this->Cno = Cno;
		this->Cname = Cname;
		this->Tname = Tname;
		this->Ctype = Ctype;
		this->Ccredit = Ccredit;
		this->SCstatus = SCstatus;
		this->SCscore = SCscore;
	};
	~StuCourse(){};
    int StuCourse::getStNo(){
		return this->StNo;}
	int StuCourse::getStgrade(){
		return this->Stgrade;}
	string StuCourse::getStName(){
		return this->StName;}
	string StuCourse::getStmajor(){
		return this->Stmajor;}
    string StuCourse::getCno(){
		return this->Cno;}
	string StuCourse::getCname(){
		return this->Cname;}
	string StuCourse::getTname(){
		return this->Tname;}
	int StuCourse::getCtype(){
		return this->Ctype;}
	float StuCourse::getCcredit(){
		return this->Ccredit;}
    string StuCourse::getSCstatus(){
		return this->SCstatus;}
    string StuCourse::getSCscore(){
		return this->SCscore;}
		
	void StuCourse::toString(){
	   cout<<"学号："<<StNo<<",年级："<<Stgrade<<",姓名："<<StName<<",专业："<<Stmajor<<",课程号："<<Cno<<",课程名："<<Cname<<",老师："<<Tname<<",类型："<<
	   Ctype<<",学分："<<Ccredit<<",状态："<<SCstatus<<",成绩："<<SCscore<<endl;
	}
};
