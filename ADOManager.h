#if !defined(AFX_ADOCONN_H__56A56674_91DC_43BB_BD09_9A0C8995161E__INCLUDED_)
#define AFX_ADOCONN_H__56A56674_91DC_43BB_BD09_9A0C8995161E__INCLUDED_
#include "manager.cpp"
#include "student.cpp"
#include "Course.cpp"
#include "StuCour.cpp"
#include "stumanager.cpp"
#include "stdafx.h"  
#include <iostream>    
#include <list>
#include <string>   
#include <algorithm>
#include <sstream>
//步骤1：添加对ADO的支持  
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")    
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef list<manager> MANAGERLIST;
typedef list<Student> StudentLIST;
typedef list<Course> COURSELIST;
typedef list<StuCourse> SCLIST;

class ADOManager{
public:
_ConnectionPtr pConn;
_RecordsetPtr pRec;
_CommandPtr pCmd;
ADOManager(void);
~ADOManager(void);
void OnInitADOConn(void);//链接数据库
void ExitConnect(void);//关闭数据库
manager SelectByUser(string user);//查询用户by用户名
MANAGERLIST SelectAll();//查询所有用户
bool userExist(string user);//查询用户存在
Student SelectStuById(int sno);//查询学生信息by学号
StudentLIST SelectStuAll();//查询所有学生
bool insertStu(Student s);//增加学生信息
bool updateStu(string sql);//修改学生sql
COURSELIST SelectCour();//查询课程
bool insertCour(Course c,string major2);//增加课程信息
bool insertTeacher(int no,string name,string sex,int age,string college);//增加教师
bool updateCour(string sql);//修改Course sql
SCLIST SelectSC();//查询学生课程情况
bool updateScore(int sno,string cno,string score);//修改学生成绩
stumanager SelectLSByUser(int user);////查询用户学生
bool updatePWD(int user,string psd);//学生修改密码
COURSELIST SelectCourByMajor(string major);//查询专业课程信息
bool updateCredit(Student s,float credit);//修改学生学分
bool insertSC(StuCourse sc,Student s,Course c);//选课
bool delectSC(StuCourse sc,Student s,Course c);//退课
string changeI(int a);//int ->string
string changeF(float a);//float->string
//_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);

};
#endif // !defined(AFX_ADOCONN_H__56A56674_91DC_43BB_BD09_9A0C8995161E__INCLUDED_)