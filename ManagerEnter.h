#include "ADOManager2.h"
typedef list<manager> MANAGERLIST;
typedef list<Student> StudentLIST;
typedef list<Course> COURSELIST;
typedef list<StuCourse> SCLIST;

//1
void selectAllStu(){
	cout<<"这里是学生信息：。。。"<<endl;
 CoInitialize(NULL);
  ADOManager am ;
  am.OnInitADOConn();
  StudentLIST sall = am.SelectStuAll();
  StudentLIST::iterator j;
    for(j = sall.begin();j!=sall.end();++j)
	{Student s = *j;s.toString();}
	cout<<endl;
  am.ExitConnect();
  while(true){
cout<<"continue?y/n"<<endl;
char ans;
cin>>ans;
if(ans=='y')break;}
return;
}
//2
void selectStuById(){
	cout<<"请输入学号1：";
	int sno ;
	cin>>sno;
 CoInitialize(NULL);
  ADOManager am ;
  am.OnInitADOConn();
  Student s1 = am.SelectStuById(sno);
  //wrong
  if(s1.getStName()==""){
     cout<<"你所查询的学号不存在"<<endl;
	 return;
  }
    s1.toString();
  am.ExitConnect();
  while(true){
cout<<"continue?y/n"<<endl;
char ans;
cin>>ans;
if(ans=='y')break;}
return;
}
//3
void selectStuByMajor(){
	cout<<"请输入该专业名"<<endl;
	string major;
	cin>>major;
CoInitialize(NULL);
  ADOManager am ;
  am.OnInitADOConn();
  StudentLIST sall = am.SelectStuAll();
  StudentLIST::iterator j;
  Student s1;
    for(j = sall.begin();j!=sall.end();++j)
	{Student s = *j;
	if(s.getStmajor()==major){
		s1 = s;
		s.toString();}
	}
  if(s1.getStmajor()==""){
     cout<<"你所查询的专业不存在"<<endl;
	 return;
  }
	cout<<endl;
  am.ExitConnect();
  while(true){
cout<<"continue?y/n"<<endl;
char ans;
cin>>ans;
if(ans=='y')break;}
return;
}
//4
void insertStu(){
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
cout<<"请输入学生基本信息："<<endl;
cout<<"StNo.:";cin>>StNo;
cout<<"Stgrade:";cin>>Stgrade;
cout<<"StName:";cin>>StName;
cout<<"Stmajor:";cin>>Stmajor;
cout<<"StCollege:";cin>>StCollege;
cout<<"Stsex:";cin>>Stsex;
cout<<"StAge:";cin>>StAge;
cout<<"Stbirthday:";cin>>Stbirthday;
cout<<"StCity:";cin>>StCity;
cout<<"StPhone:";cin>>StPhone;
cout<<"StId:";cin>>StId;
cout<<"StQQ:";cin>>StQQ;
cout<<"Stnowcredit:";cin>>Stnowcredit;
Student ns(StNo,Stgrade,StName,Stmajor,StCollege,Stsex,StAge,Stbirthday,StCity,StPhone,StId,StQQ,Stnowcredit);
CoInitialize(NULL);
 ADOManager am ;
  am.OnInitADOConn();
  cout<<"3"<<endl;
  if(am.insertStu(ns))cout<<"success"<<endl;
  else{cout<<"failed"<<endl;}
  am.ExitConnect();
cout<<"end"<<endl;
return;
}
//5
void updateStu(){
	char str[100];
	char kong;
	while(true){
cout<<"pass?(string<100)"<<endl;
cin.get(kong);
cout<<"请输入修改语句"<<endl;
cin.getline(str,100);
CoInitialize(NULL);
 ADOManager am ;
  am.OnInitADOConn();
  if(am.updateStu(str)){cout<<"结果：success"<<endl;}
  else{cout<<"结果：failed"<<endl;}
  am.ExitConnect();
cout<<"continue?y/n"<<endl;
char ans;
cin>>ans;
if(ans=='y')break;}

return;
}
//6
void course(){
	void sqlCourse();
	void sqlCourseByMajor();
	void sqlCourseByTeach();
	void insCourse();
	void updateCourse();
	  while(true){
	cout<<"这里是课程操作："<<endl;
	int n;
	cout<<"1、查询课程所有"<<endl;
	cout<<"2、查询学院开设的课程"<<endl;
	cout<<"3、查询教师课程"<<endl;
	cout<<"4、增加课程信息"<<endl;
	cout<<"5、其他课程操作bySql"<<endl;
	cout<<"6、退出该界面"<<endl;
	cin>>n;
	switch(n){
	case 1 :sqlCourse();break;
	case 2 :sqlCourseByMajor();break;
	case 3 :sqlCourseByTeach();break;
	case 4 :insCourse();break;
	case 5 :updateCourse();break;
	case 6 :return;
	default:cout<<"错误操作"<<endl;break;
	}
cout<<"是否退出?y/n"<<endl;
string ans;
cin>>ans;
if(ans=="n")break;}
return;
}
//6.1
void sqlCourse(){
CoInitialize(NULL);
  ADOManager am ;
  am.OnInitADOConn();
  COURSELIST call = am.SelectCour();
  COURSELIST::iterator j;
    for(j = call.begin();j!=call.end();++j)
	{Course c = *j;c.toString();}
	cout<<endl;
  am.ExitConnect();
  while(true){
cout<<"continue?y/n"<<endl;
string ans;
cin>>ans;
if(ans=="y")break;}
return;
}
//6.2
void sqlCourseByMajor(){
	cout<<"查询："<<endl<<"学院:   ";
	string col;
	cin>>col;
CoInitialize(NULL);
  ADOManager am ;
  am.OnInitADOConn();
  COURSELIST call = am.SelectCour();
  COURSELIST::iterator j;
   Course end;
    for(j = call.begin();j!=call.end();++j)
	{
		Course c = *j;
		if(col == c.getCcollege())
		{  
			end = c;
			end.toString();}
	}
	if(end.getCname()=="")
	{
	cout<<"该专业不存在"<<endl;
	}
	cout<<endl;
  am.ExitConnect();
  while(true){
cout<<"continue?y/n"<<endl;
string ans;
cin>>ans;
if(ans=="y")break;}
return;
}
//6.3
void sqlCourseByTeach(){
	cout<<"查询："<<endl<<"教师:   ";
	string tea;
	cin>>tea;
CoInitialize(NULL);
  ADOManager am ;
  am.OnInitADOConn();
  COURSELIST call = am.SelectCour();
  COURSELIST::iterator j;
   Course end;
    for(j = call.begin();j!=call.end();++j)
	{
		Course c = *j;
		if(tea == c.getTname())
		{  
			end = c;
			end.toString();}
	}
	if(end.getCname()=="")
	{
	cout<<"该老师不存在"<<endl;
	}
	cout<<endl;
  am.ExitConnect();
  while(true){
cout<<"continue?y/n"<<endl;
string ans;
cin>>ans;
if(ans=="y")break;}
return;
}
//6.4
void insCourse(){
	int Stgrade;//
	int Cyear;
	int Cterm;
	string Cno;
	string Cname;
	int Tno;//教师编号
	string Tname;
	string Cplace;
	string Ctime;
	string Ccollege;//学院
	int Ctype;//主副修
	float Ccredit;//学分
cout<<"请输入course基本信息："<<endl;
cout<<"Stgrade.:";cin>>Stgrade;
cout<<"Cyear:";cin>>Cyear;
cout<<"Cterm:";cin>>Cterm;
cout<<"Cno:";cin>>Cno;
cout<<"Cname:";cin>>Cname;
cout<<"Tno:";cin>>Tno;
cout<<"Tname:";cin>>Tname;
cout<<"Cplace:";cin>>Cplace;
cout<<"Ctime:";cin>>Ctime;
cout<<"Ccollege:";cin>>Ccollege;
cout<<"Ctype:";cin>>Ctype;
cout<<"Ccredit:";cin>>Ccredit;
Course co(Stgrade,Cyear,Cterm,Cno,Cname,Tno,Tname,Cplace,Ctime,Ccollege,Ctype,Ccredit);
string major2;
cout<<"可读专业：";cin>>major2;
CoInitialize(NULL);
 ADOManager am ;
  am.OnInitADOConn();
  cout<<"3"<<endl;
  if(am.insertCour(co,major2))cout<<"success"<<endl;
  else{cout<<"failed"<<endl;}
  am.ExitConnect();
cout<<"end"<<endl;
return;
}
//6.5
void updateCourse(){
	char str[100];
	char kong;
	while(true){
cout<<"pass?(string<100)"<<endl;
cin.get(kong);
cout<<"请输入修改语句"<<endl;
cin.getline(str,100);
CoInitialize(NULL);
 ADOManager am ;
  am.OnInitADOConn();
  if(am.updateStu(str)){cout<<"结果：success"<<endl;}
  else{cout<<"结果：failed"<<endl;}
  am.ExitConnect();
cout<<"continue?y/n"<<endl;
string ans;
cin>>ans;
if(ans=="y")break;}
return;
}
//7
void selectCour(){
cout<<"这里是课程信息：。。。"<<endl;
CoInitialize(NULL);
ADOManager am ;
  am.OnInitADOConn();
  SCLIST scl = am.SelectSC();
  SCLIST::iterator j;
    for(j = scl.begin();j!=scl.end();++j)
	{ StuCourse sc= *j;
     sc.toString();
	}
	cout<<endl;
  am.ExitConnect();
  while(true){
cout<<"continue?y/n"<<endl;
string ans;
cin>>ans;
if(ans=="y")break;}
return;
}
//8
void updateStuGrade(){
	int sno;
	string cno;
	string score;
	string judge;
cout<<"请在这里修改成绩:"<<endl;
cout<<"该学生学号：";
cin>>sno;
cout<<endl<<"课程号：";
cin>>cno;
cout<<endl<<"该成绩？：";
cin>>score;
cout<<endl<<"Sure????(yes)"<<endl;
cin>>judge;
if(judge!="yes")return;
else{
CoInitialize(NULL);
ADOManager am ;
  am.OnInitADOConn();
  if(am.updateScore(sno,cno,score))cout<<"OK"<<endl;
  else{cout<<"something wrong here!"<<endl;}
	cout<<endl;
  am.ExitConnect();
}
  while(true){
cout<<"continue?y/n"<<endl;
string ans;
cin>>ans;
if(ans=="y")break;}
return;
}
//9
void insTeacher(){
	int Tno;//教师编号
	string Tname;
	string Tsex;
	int Tage;
	string Tcollege;//学院
cout<<"请输入teacher基本信息："<<endl;
cout<<"Tno.:";cin>>Tno;
cout<<"Tname:";cin>>Tname;
cout<<"Tsex:";cin>>Tsex;
cout<<"Tcollege:";cin>>Tcollege;
cout<<"Tage:";cin>>Tage;
CoInitialize(NULL);
 ADOManager am ;
  am.OnInitADOConn();
  cout<<"3"<<endl;
  if(am.insertTeacher(Tno,Tname,Tsex,Tage,Tcollege))cout<<"success"<<endl;
  else{cout<<"failed"<<endl;}
  am.ExitConnect();
cout<<"end"<<endl;
return;
}