#include "stdafx.h"
#include "iostream"
#include <string>
using namespace std;
class StuCourse{
private:
	//St��ͷ����ѧ����C��ͷ���ǿγ̣�T��ͷ������ʦ��SC��ͷ����ѡ��
	int StNo;		
	int Stgrade;	//ѧ���꼶
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
	   cout<<"ѧ�ţ�"<<StNo<<",�꼶��"<<Stgrade<<",������"<<StName<<",רҵ��"<<Stmajor<<",�γ̺ţ�"<<Cno<<",�γ�����"<<Cname<<",��ʦ��"<<Tname<<",���ͣ�"<<
	   Ctype<<",ѧ�֣�"<<Ccredit<<",״̬��"<<SCstatus<<",�ɼ���"<<SCscore<<endl;
	}
};
