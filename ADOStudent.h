#include "ADOManager.h"
typedef list<manager> MANAGERLIST;
typedef list<Student> StudentLIST;
typedef list<Course> COURSELIST;
typedef list<StuCourse> SCLIST;
//查询用户学生
stumanager ADOManager::SelectLSByUser(int user){
	pRec.CreateInstance(__uuidof(Recordset));
	pRec= pConn->Execute("select * from login_student",NULL,adCmdText);
	stumanager m;
	string user2 = changeI(user);
	try
	{
	while(!pRec->adoEOF)
	{
		string user1 =(_bstr_t)pRec->GetCollect("StNo");
		string password = (_bstr_t)pRec->GetCollect("passwords");
		if(user1==user2)
		{ stumanager m2(atoi(user1.c_str()),password);
		 return m2;}
	//	cout<<password<<endl;
		//	cout<<"2"<<endl;
	    pRec->MoveNext();
	}
	return m;
	}catch(_com_error& e)
       {
        cout<<"wrong SelectLSByUser"<<endl;
	 }return m;
}
//学生修改密码
bool ADOManager::updatePWD(int user,string psd){
	bool result = false;
	pRec.CreateInstance(__uuidof(Recordset));
	try
	{
		string up="update login_student set passwords = '";
		string upd = up+psd+"' where StNo ='"+changeI(user)+"'";
	    _bstr_t upda = "";
		 cout<<upd<<endl;
		 upda = upd.c_str();
	pRec= pConn->Execute(upda,NULL,adCmdText);
	result = true;
	return result;
	}catch(_com_error& e)
       {
        cout<<"wrong SelectLSByUser"<<endl;
	 }return result;
}
//查询专业课程信息
COURSELIST ADOManager::SelectCourByMajor(string major)
{
	pRec.CreateInstance(__uuidof(Recordset));
	string s = "select * from major_course,course where major_course.MCcno = course.Cno and major_course.MCmajor ='";
	string sel = s+major+"'";
	_bstr_t se="";
	se=sel.c_str();
	pRec= pConn->Execute(se,NULL,adCmdText);
	COURSELIST cl;
	COURSELIST::iterator i;
	try
	{
	while(!pRec->adoEOF)
	{
		string Stgrade =(_bstr_t)pRec->GetCollect("Stgrade");
		string Cyear = (_bstr_t)pRec->GetCollect("Cyear");
		string Cterm = (_bstr_t)pRec->GetCollect("Cterm");
		string Cno = (_bstr_t)pRec->GetCollect("Cno");
		string Cname = (_bstr_t)pRec->GetCollect("Cname");
		string Tno = (_bstr_t)pRec->GetCollect("Tno");
		string Tname = (_bstr_t)pRec->GetCollect("Tname");
		string Cplace = (_bstr_t)pRec->GetCollect("Cplace");
		string Ctime = (_bstr_t)pRec->GetCollect("Ctime");
		string Ccollege = (_bstr_t)pRec->GetCollect("Ccollege");
		string Ctype = (_bstr_t)pRec->GetCollect("Ctype");
		string Ccredit = (_bstr_t)pRec->GetCollect("Ccredit");
        Course c(atoi(Stgrade.c_str()),atoi(Cyear.c_str()),atoi(Cterm.c_str()),Cno,Cname,atoi(Tno.c_str()),Tname,Cplace,Ctime,Ccollege,atoi(Ctype.c_str()),atof(Ccredit.c_str()));
		cl.push_front(c);
	    pRec->MoveNext();
	}
	return cl;
	}catch(_com_error& e)
       {
        cout<<"wrong SelectLSByUser"<<endl;
	 }return cl;
}
//修改学生学分
bool ADOManager::updateCredit(Student s,float credit)
{
   bool result = false;
   float credit2 = s.getStnowcredit()+credit;
    pRec.CreateInstance(__uuidof(Recordset));
		try
	{ string up = "update student_base set Stnowcredit=";
		string upd = up+changeF(credit2)+" where StNo="+changeI(s.getStNo());
		cout<<"0"<<endl;
		 _bstr_t upda = "";
		 cout<<upd<<endl;
		 upda = upd.c_str();
		pRec= pConn->Execute(upda,NULL,adCmdText);
		cout<<"1"<<endl;
         return result=true;
	}catch(_com_error& e)
       {
        cout<<"updateCredit is wrong"<<endl;
	 }
	return result;
}
//判断课程是否已选

//选课
bool ADOManager::insertSC(StuCourse sc,Student s,Course c){
bool result=false;
		string no = changeI(sc.getStNo());
      pRec.CreateInstance(__uuidof(Recordset));
	try
	{ string in = "insert into student_course(StNo,Cno,SCscore,SCstatus)values(";
		string inserts = in+no+",'"+sc.getCno()+"','0','1')";
		cout<<"0"<<endl;
		 _bstr_t ins = "";
		 cout<<inserts<<endl;
		 ins = inserts.c_str();
		pRec= pConn->Execute(ins,NULL,adCmdText);
		if(updateCredit(s,c.getCcredit()))result = true;
		cout<<"1"<<endl;
	}catch(_com_error& e)
       {
        cout<<"insertSC is wrong"<<endl;
	 }
	return result;
}
//退课
bool ADOManager::delectSC(StuCourse sc,Student s,Course c){
        bool result=false;
		string no = changeI(sc.getStNo());
      pRec.CreateInstance(__uuidof(Recordset));
	try
	{ string de = "delete student_course where StNo = ";
		string delect = de+no+" and Cno='"+sc.getCno()+"'";
		cout<<"0"<<endl;
		 _bstr_t del = "";
		 cout<<delect<<endl;
		 del = delect.c_str();
		pRec= pConn->Execute(del,NULL,adCmdText);
		float cre = -(c.getCcredit());
		if(updateCredit(s,cre))result = true;
		cout<<"1"<<endl;
         return result=true;
	}catch(_com_error& e)
       {
        cout<<"delectSC is wrong"<<endl;
	 }
	return result;
}