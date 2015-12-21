#include "ManagerEnter.h"
#include "studentEnter.h"
using namespace std; 
typedef list<manager> MANAGERLIST;
typedef list<Student> StudentLIST;
typedef list<Course> COURSELIST;
typedef list<StuCourse> SCLIST;
int main(){
	bool managerEnter();
//	Enter();
while(true){
	while(true){
cout<<"This is 学生选课管理系统！！！！！！！！"<<endl;
cout<<"please input your userid"<<endl;
cout<<"用户名Manager：";
if(managerEnter())break;
}
	
}
return 0;
}
//
bool managerEnter(){
	void managerMain();
	void stuMain(int user);
     bool result = false;
    char user[20];
    cin.getline(user,20);
    CoInitialize(NULL);
ADOManager am ;
am.OnInitADOConn();
bool UE = am.userExist(user);
if(UE==false){
    
	cout<<"管理员不存在 student:";
    char stu[20];
    cin.getline(stu,20);
	string st = stu;
   int stu2 = atoi(st.c_str());
	stumanager s;
	s = am.SelectLSByUser(stu2);
	if(s.getStNo()!=0){
    cout<<"please input your password"<<endl;
    cout<<"密码:";
    char ps[20];
    cin.getline(ps,20);
	if(!(ps ==s.getpassword())){cout<<"密码错误！"<<endl;return result;}
	else{cout<<"欢迎来到学生选课系统  "<<user<<endl;
     am.ExitConnect();
      stuMain(stu2);}
	}else{
	cout<<"该用户名不存在！"<<endl;return result;}
}
else{
cout<<"管理员登录"<<endl;
cout<<"please input your password"<<endl;
cout<<"密码:";
char psw[20];
  cin.getline(psw,20);
manager m = am.SelectByUser(user);
if(!(psw ==m.getPassword())){cout<<"密码错误！"<<endl;return result;}

cout<<"欢迎来到学生选课系统（管理员）"<<endl;
am.ExitConnect();
managerMain();}

return result = true;
}
//
void managerMain()
{
	void selectAllStu();
	void selectStuById();
	void selectStuByMajor();
	void insertStu();
	void updateStu();
	void course();
	void selectCour();
	void updateStuGrade();
	void insTeacher();
	int n;
	while(true){
cout<<"1、查询所有学生信息"<<endl;
cout<<"2、查询学生信息by学号"<<endl;
cout<<"3、查询学生信息by专业"<<endl;
cout<<"4、增加一学生信息"<<endl;
cout<<"5、修改一学生信息"<<endl;
cout<<"6、课程的增删改查"<<endl;
cout<<"7、选课信息的查询"<<endl;
cout<<"8、对学生成绩修改"<<endl;
cout<<"9、新增教师"<<endl;
cout<<"10、退出"<<endl;
	cout<<"请输入数字操作系统：";
	cin>>n;
	switch(n){
	case 1 :selectAllStu();break;
	case 2 :selectStuById();break;
	case 3 :selectStuByMajor();break;
    case 4 :insertStu();break;
	case 5 :updateStu();break;
	case 6 :course();break;
	case 7 :selectCour();break;
	case 8 :updateStuGrade();break;
	case 9 :insTeacher();break;
	case 10 :return;
	default :cout<<"输入有误，请再输入一遍"<<endl;
	}
	}
		cout<<"管理员退出"<<endl;

}

//
void stuMain(int user){
	Student US;//学生信息
    StuCourse USC;
    SCLIST SCLI;//学生选课信息
    SCLIST::iterator J;
    COURSELIST UCL;//学生能选的课的信息
    COURSELIST::iterator I;
	void changePWD(Student s);
	void selectUS(Student s);
	void selectUSCLIST(Student s,SCLIST scl);
	void xuanke(Student s,SCLIST scl,COURSELIST ucl);
	ADOManager am ;
am.OnInitADOConn();
US = am.SelectStuById(user);
US.toString();
/*
COURSELIST cl;
COURSELIST::iterator i;
cl = am.SelectCour();*/
UCL = am.SelectCourByMajor(US.getStmajor());
SCLI = am.SelectSC();
for(J = SCLI.begin();J!=SCLI.end();++J)
	{StuCourse sc = *J;
    if(sc.getCname()==US.getStName())
	{	J=SCLI.erase(J);} 
} 
am.ExitConnect();
    int n =0;
	while(true){
cout<<"1、修改个人密码"<<endl;
cout<<"2、查询个人信息"<<endl;
cout<<"3、查询个人课程信息"<<endl;
cout<<"4、选课ing。。。"<<endl;
cout<<"5、退出选课系统"<<endl;
	cout<<"请输入数字操作系统：";
	cin>>n;
	switch(n){
    case 1 :changePWD(US);break;
	case 2 :selectUS(US);break;
	case 3 :selectUSCLIST(US,SCLI);break;
	case 4 :xuanke(US,SCLI,UCL);break;
	case 5 :return;
	default :cout<<"输入有误，请再输入一遍"<<endl;
	}
	}
	cout<<US.getStName()<<" 退出"<<endl;
}
