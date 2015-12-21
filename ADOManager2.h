#include "ADOManager.h"
typedef list<manager> MANAGERLIST;
typedef list<Student> StudentLIST;
typedef list<Course> COURSELIST;
typedef list<StuCourse> SCLIST;

ADOManager::ADOManager(void){}
ADOManager::~ADOManager(void){cout<<"clear............"<<endl;}
//连接数据库
void ADOManager::OnInitADOConn(void)
{
  CoInitialize(NULL);
  pConn.CreateInstance(__uuidof(Connection));
   pRec.CreateInstance(__uuidof(Recordset));
	 try{
	 pConn->ConnectionString="Provider = SQLOLEDB.1;Persist Security Info = False;User ID=sa;Password=123456789;Initial Catalog =studentManager";
      pConn->Open("","","",adConnectUnspecified);
}
catch (_com_error e)
{
//显示错误信息
 cout<<"wrong OnInitADOConn"<<endl;
}
}
//断开连接
void ADOManager::ExitConnect(void)
{
//关闭记录集和连接
	if(pRec!=NULL){
		pRec.Release();
  	 pRec=NULL;
	}
pConn->Close();
::CoUninitialize();
}
//按用户名查询帐号
manager ADOManager::SelectByUser(string user){
	pRec.CreateInstance(__uuidof(Recordset));
	pRec= pConn->Execute("select * from Login",NULL,adCmdText);
	manager m;
	try
	{
	while(!pRec->adoEOF)
	{
		string user1 =(_bstr_t)pRec->GetCollect("users");
		string password = (_bstr_t)pRec->GetCollect("passwords");
		if(user1==user)
		{ manager m2(user1,password);
		 return m2;}
	//	cout<<password<<endl;
		//	cout<<"2"<<endl;
	    pRec->MoveNext();
	}
	return m;
	}catch(_com_error& e)
       {
        cout<<"wrong SelectByUser"<<endl;
	 }return m;
}
//查询所有帐号
MANAGERLIST ADOManager::SelectAll(){
	pRec.CreateInstance(__uuidof(Recordset));
	pRec= pConn->Execute("select * from Login",NULL,adCmdText);
	MANAGERLIST ml ;
	MANAGERLIST::iterator i;
	try
	{
	while(!pRec->adoEOF)
	{
		string user1 =(_bstr_t)pRec->GetCollect("users");
		string password = (_bstr_t)pRec->GetCollect("passwords");
        manager m2(user1,password);
		ml.push_front(m2);
	    pRec->MoveNext();
	}
   /* for(i = ml.begin();i!=ml.end();++i)
	{manager m3 = *i;cout<<m3.getPassword()<<" "; }
	cout<<endl;*/
	return ml;
	}catch(_com_error& e)
       {
        cout<<"wrong SelectAll"<<endl;
	 }return ml;
}
//查询用户名是否存在
bool ADOManager::userExist(string user){
	pRec.CreateInstance(__uuidof(Recordset));
	pRec= pConn->Execute("select * from Login",NULL,adCmdText);
    bool result = false;
	try
	{
	while(!pRec->adoEOF)
	{
		string user1 =(_bstr_t)pRec->GetCollect("users");
		string password = (_bstr_t)pRec->GetCollect("passwords");
        if(user1==user)result=true;
	    pRec->MoveNext();
	}
	return result;
	}catch(_com_error& e)
       {
        cout<<"wrong userExist"<<endl;
	 }return result;
}
//查询所有学生
StudentLIST ADOManager::SelectStuAll(){
pRec.CreateInstance(__uuidof(Recordset));
	pRec= pConn->Execute("select * from student_base",NULL,adCmdText);
	StudentLIST m2 ;
	StudentLIST::iterator i;
	try
	{
	while(!pRec->adoEOF)
	{
		string StNo =(_bstr_t)pRec->GetCollect("StNo");
		string Stgrade = (_bstr_t)pRec->GetCollect("Stgrade");
		string StName = (_bstr_t)pRec->GetCollect("StName");
		string Stmajor = (_bstr_t)pRec->GetCollect("Stmajor");
		string StCollege = (_bstr_t)pRec->GetCollect("StCollege");
		string Stsex = (_bstr_t)pRec->GetCollect("Stsex");
		string StAge = (_bstr_t)pRec->GetCollect("StAge");
		string Stbirthday = (_bstr_t)pRec->GetCollect("Stbirthday");
		string StCity = (_bstr_t)pRec->GetCollect("StCity");
		string StPhone = (_bstr_t)pRec->GetCollect("StPhone");
		string StId = (_bstr_t)pRec->GetCollect("StId");
		string StQQ = (_bstr_t)pRec->GetCollect("StQQ");
		string Stnowcredit = (_bstr_t)pRec->GetCollect("Stnowcredit");
        Student m(atoi(StNo.c_str()),atoi(Stgrade.c_str()),StName,Stmajor,StCollege,Stsex,atoi(StAge.c_str()),atoi(Stbirthday.c_str()),StCity,StPhone,StId,StQQ,atof(Stnowcredit.c_str()));
		m2.push_front(m);
	    pRec->MoveNext();
	}
   /* for(i = ml.begin();i!=ml.end();++i)
	{manager m3 = *i;cout<<m3.getPassword()<<" "; }
	cout<<endl;*/
	return m2;
	}catch(_com_error& e)
       {
        cout<<"wrong SelectStuAll"<<endl;
	 }return m2;
}
//查询所有学生
Student ADOManager::SelectStuById(int sno){
pRec.CreateInstance(__uuidof(Recordset));
	pRec= pConn->Execute("select * from student_base",NULL,adCmdText);
	Student s;
	try
	{
	while(!pRec->adoEOF)
	{
		string no =(_bstr_t)pRec->GetCollect("StNo");
		if(atoi(no.c_str())==sno){
		string StNo =(_bstr_t)pRec->GetCollect("StNo");
		string Stgrade = (_bstr_t)pRec->GetCollect("Stgrade");
		string StName = (_bstr_t)pRec->GetCollect("StName");
		string Stmajor = (_bstr_t)pRec->GetCollect("Stmajor");
		string StCollege = (_bstr_t)pRec->GetCollect("StCollege");
		string Stsex = (_bstr_t)pRec->GetCollect("Stsex");
		string StAge = (_bstr_t)pRec->GetCollect("StAge");
		string Stbirthday = (_bstr_t)pRec->GetCollect("Stbirthday");
		string StCity = (_bstr_t)pRec->GetCollect("StCity");
		string StPhone = (_bstr_t)pRec->GetCollect("StPhone");
		string StId = (_bstr_t)pRec->GetCollect("StId");
		string StQQ = (_bstr_t)pRec->GetCollect("StQQ");
		string Stnowcredit = (_bstr_t)pRec->GetCollect("Stnowcredit");
        Student m(atoi(StNo.c_str()),atoi(Stgrade.c_str()),StName,Stmajor,StCollege,Stsex,atoi(StAge.c_str()),atoi(Stbirthday.c_str()),StCity,StPhone,StId,StQQ,atof(Stnowcredit.c_str()));
		s=m;	return s;
		}
	    pRec->MoveNext();
	}
	return s;
	}catch(_com_error& e)
       {
        cout<<"wrong SelectStuById"<<endl;
	 }return s;
}
//int ->string 
string ADOManager::changeI(int a){
   char p[32];
   itoa(a,p,10);
   string s = p;
   return s;
}
//int ->string 
string ADOManager::changeF(float a){
  	ostringstream oss;
	oss<<a;
	string s(oss.str());
	return s;
}
//新增学生登录信息
/*bool ADOManager::insertStuLog(Student s)
{
	bool result=false;
		string no = changeI(s.getStNo());
		string cred = changeF(s.getStNo());
      pRec.CreateInstance(__uuidof(Recordset));
	try
	{ string in = "insert into login_student values(";
		string inserts = in+no+",'"+cred+"')";
		cout<<"0"<<endl;
		 _bstr_t ins = "";
		 cout<<inserts<<endl;
		 ins = inserts.c_str();
		pRec= pConn->Execute(ins,NULL,adCmdText);
		cout<<"1"<<endl;
         return result=true;
	}catch(_com_error& e)
       {
        cout<<"insertStuLog is wrong"<<endl;
	 }
	return result;
}*/
//新增学生信息
bool ADOManager::insertStu(Student s){
		bool result=false;
		string no = changeI(s.getStNo());
        string grade = changeI(s.getStgrade());
		string age = changeI(s.getStAge());
		string bir = changeI(s.getStbirthday());
		string cred = changeF(s.getStnowcredit());
      pRec.CreateInstance(__uuidof(Recordset));
	try
	{ string in = "insert into student_base(StNo,Stgrade,StName,Stmajor,StCollege,Stsex,StAge,Stbirthday,StCity,StPhone,StId,StQQ,Stnowcredit)values(";
		string inserts = in+no+","+grade+",'"+s.getStName()+"','"+s.getStmajor()+"','"+s.getStCollege()+"','"+s.getStsex()+"',"+age+","+bir+",'"+s.getStCity()+"','"+s.getStPhone()+"','"+s.getStId()+"','"+s.getStQQ()+"',"+cred+")";
		cout<<"0"<<endl;
		 _bstr_t ins = "";
		 cout<<inserts<<endl;
		 ins = inserts.c_str();
		pRec= pConn->Execute(ins,NULL,adCmdText);
     	string in2 = "insert into login_student values(";
		string inserts2 = in2+no+",'"+no+"')";
		cout<<"0"<<endl;
		 _bstr_t ins2 = "";
		 cout<<inserts2<<endl;
		 ins2 = inserts2.c_str();
		  pConn->Execute(ins2,NULL,adCmdText);
		cout<<"1"<<endl;
         return result=true;
	}catch(_com_error& e)
       {
        cout<<"insertStu is wrong"<<endl;
	 }
	return result;
}
//修改学生数据
bool ADOManager::updateStu(string sql){
     bool result = false;
	 pRec.CreateInstance(__uuidof(Recordset));
	 //string sql2 = "update student_base set student_base_name = 'wo' where student_base_num = '3'";
	 cout<<sql<<endl;
	 try
	{
     _bstr_t upd = "";
	 upd = sql.c_str();
	pRec= pConn->Execute(upd,NULL,adCmdText);
	result = true;
	return result;
	}catch(_com_error& e)
       {
        cout<<"输入的sql语句有误"<<endl;
	 }return result;

}
//查询课程信息
COURSELIST ADOManager::SelectCour(){
pRec.CreateInstance(__uuidof(Recordset));
	pRec= pConn->Execute("select * from course",NULL,adCmdText);
	COURSELIST cl ;
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
    for(i = cl.begin();i!=cl.end();++i)
	{Course c2 = *i;cout<<c2.getCno()<<" "; }
	cout<<endl;
	return cl;
	}catch(_com_error& e)
       {
        cout<<"wrong SelectCour"<<endl;
	 }return cl;
}
//新增课程
bool ADOManager::insertCour(Course c,string major2){
	bool result=false;
		char p[32];
		int n = c.getStgrade();
		itoa(n,p,10);
		string gra = p;
	char g[32];
	int a = c.getCyear();
		itoa(a,g,10);
		string year = g;
	char q[32];
	int b = c.getCterm();
		itoa(b,q,10);
		string term = q;
	char w[32];
	int e = c.getTno();
		itoa(e,w,10);
		string Tno = w;
	char r[32];
	int d = c.getCtype();
		itoa(d,r,10);
		string type = r;
	ostringstream oss;
	oss<<c.getCcredit();
	string cred(oss.str());
     pRec.CreateInstance(__uuidof(Recordset));
	try
	{ string in = "insert into course(Stgrade,Cyear,Cterm,Cno,Cname,Tno,Tname,Cplace,Ctime,Ccollege,Ctype,Ccredit) values(";
		string insertc = in+gra+","+year+","+term+",'"+c.getCno()+"','"+c.getCname()+"',"+Tno+",'"+c.getTname()+"','"+c.getCplace()+"','"+c.getCtime()+"','"+c.getCcollege()+"',"+type+","+cred+")";
		cout<<"0"<<endl;
		 _bstr_t insc = "";
		 cout<<insertc<<endl;
		 insc = insertc.c_str();
		pRec= pConn->Execute(insc,NULL,adCmdText);

		string in2 = "insert into major_course values(";
		string insert2 = in2+"'"+c.getCno()+"','"+c.getCname()+"','"+major2+"','"+c.getCcollege()+"')";
		cout<<"0"<<endl;
		 _bstr_t insc2 = "";
		 cout<<insert2<<endl;
		 insc2 = insert2.c_str();
	    pConn->Execute(insc2,NULL,adCmdText);
		cout<<"1"<<endl;
         return result=true;
	}catch(_com_error& e)
       {
        cout<<"insertCour is wrong"<<endl;
	 }
	return result;
}
//sql修改课程
bool ADOManager::updateCour(string sql){
  bool result = false;
	 pRec.CreateInstance(__uuidof(Recordset));
	 //string sql2 = "update student_base set student_base_name = 'wo' where student_base_num = '3'";
	 cout<<sql<<endl;
	 try
	{
     _bstr_t upd = "";
	 upd = sql.c_str();
	pRec= pConn->Execute(upd,NULL,adCmdText);
	result = true;
	return result;
	}catch(_com_error& e)
       {
        cout<<"输入的sql语句有误"<<endl;
	 }return result;
}
//查询学生课程s

SCLIST ADOManager::SelectSC(){
pRec.CreateInstance(__uuidof(Recordset));
	pRec= pConn->Execute("select * from student_course,student_base,course  where student_course.StNo=student_base.StNo and course.Cno=student_course.Cno ",NULL,adCmdText);
	SCLIST sc ;
	SCLIST::iterator i;
	try
	{
	while(!pRec->adoEOF)
	{
		string StNo =(_bstr_t)pRec->GetCollect("StNo");
		string Stgrade = (_bstr_t)pRec->GetCollect("Stgrade");
		string StName = (_bstr_t)pRec->GetCollect("StName");
		string Stmajor = (_bstr_t)pRec->GetCollect("Stmajor");
		string Cno = (_bstr_t)pRec->GetCollect("Cno");
		string Cname = (_bstr_t)pRec->GetCollect("Cname");
		string Tname = (_bstr_t)pRec->GetCollect("Tname");
		string Ctype = (_bstr_t)pRec->GetCollect("Ctype");
		string Ccredit = (_bstr_t)pRec->GetCollect("Ccredit");
		string SCstatus = (_bstr_t)pRec->GetCollect("SCstatus");
		string SCscore = (_bstr_t)pRec->GetCollect("SCscore");
        StuCourse stc(atoi(StNo.c_str()),atoi(Stgrade.c_str()),StName,Stmajor,Cno,Cname,Tname,atoi(Ctype.c_str()),atof(Ccredit.c_str()),SCstatus,SCscore);
		sc.push_front(stc);
	    pRec->MoveNext();
	}
	return sc;
	}catch(_com_error& e)
       {
        cout<<"wrong SelectSC"<<endl;
	 }return sc;
}
//修改学生成绩
bool ADOManager::updateScore(int sno,string cno,string score){
    bool result=false;
	 pRec.CreateInstance(__uuidof(Recordset));
	 string sql = "update student_course set SCstatus = '0',SCscore='";
     string sql2 = sql+score+"' where StNo="+changeI(sno)+" and Cno = '"+cno+"'";
//	 string sql2 = "update student_course set SCstatus = '0',SCscore='99' where StNo=1 and Cno = '1'";
	 _bstr_t upsc = "";
	 upsc = sql2.c_str();
	 cout<<sql2<<endl;
	 try{
    pRec= pConn->Execute(upsc,NULL,adCmdText);
	cout<<"successed"<<endl;
	result = true;
	return result;
	}catch(_com_error& e)
       {
        cout<<"wrong updateScore"<<endl;
	 }return result;
}
//增加教师
bool ADOManager::insertTeacher(int no,string name,string sex,int age,string college){
		bool result=false;
		string tno = changeI(no);
		string tage = changeI(age);
	try
	{ string in = "insert into teacher values(";
		string inserts = in+tno+",'"+name+"','"+sex+"',"+tage+",'"+college+"')";
		cout<<"0"<<endl;
		 _bstr_t ins = "";
		 cout<<inserts<<endl;
		 ins = inserts.c_str();
		pRec= pConn->Execute(ins,NULL,adCmdText);
		cout<<"1"<<endl;
         return result=true;
	}catch(_com_error& e)
       {
        cout<<"insertTeacher is wrong"<<endl;
	 }
	return result;
}