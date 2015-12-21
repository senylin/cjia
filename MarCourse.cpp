#include "stdafx.h"
#include "iostream"
#include <string>
using namespace std;
class major_course{
private:
	int StNo;
	string Cno ;
	string SCstatus ;
	string SCscore ;
public:
	major_course(){};
	major_course(int StNo,string Cno ,string SCstatus ,string SCscore ){
		this->StNo = StNo;
		this->Cno = Cno;
		this->SCstatus = SCstatus;
		this->SCscore = SCscore;
	};
	~major_course(){};
    int major_course::getStNo(){
		return this->StNo;}
    string major_course::getCno(){
		return this->Cno;}
    string major_course::getSCstatus(){
		return this->SCstatus;}
    string major_course::getSCscore(){
		return this->SCscore;}
};
