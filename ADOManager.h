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
//����1����Ӷ�ADO��֧��  
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
void OnInitADOConn(void);//�������ݿ�
void ExitConnect(void);//�ر����ݿ�
manager SelectByUser(string user);//��ѯ�û�by�û���
MANAGERLIST SelectAll();//��ѯ�����û�
bool userExist(string user);//��ѯ�û�����
Student SelectStuById(int sno);//��ѯѧ����Ϣbyѧ��
StudentLIST SelectStuAll();//��ѯ����ѧ��
bool insertStu(Student s);//����ѧ����Ϣ
bool updateStu(string sql);//�޸�ѧ��sql
COURSELIST SelectCour();//��ѯ�γ�
bool insertCour(Course c,string major2);//���ӿγ���Ϣ
bool insertTeacher(int no,string name,string sex,int age,string college);//���ӽ�ʦ
bool updateCour(string sql);//�޸�Course sql
SCLIST SelectSC();//��ѯѧ���γ����
bool updateScore(int sno,string cno,string score);//�޸�ѧ���ɼ�
stumanager SelectLSByUser(int user);////��ѯ�û�ѧ��
bool updatePWD(int user,string psd);//ѧ���޸�����
COURSELIST SelectCourByMajor(string major);//��ѯרҵ�γ���Ϣ
bool updateCredit(Student s,float credit);//�޸�ѧ��ѧ��
bool insertSC(StuCourse sc,Student s,Course c);//ѡ��
bool delectSC(StuCourse sc,Student s,Course c);//�˿�
string changeI(int a);//int ->string
string changeF(float a);//float->string
//_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);

};
#endif // !defined(AFX_ADOCONN_H__56A56674_91DC_43BB_BD09_9A0C8995161E__INCLUDED_)