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
cout<<"This is ѧ��ѡ�ι���ϵͳ����������������"<<endl;
cout<<"please input your userid"<<endl;
cout<<"�û���Manager��";
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
    
	cout<<"����Ա������ student:";
    char stu[20];
    cin.getline(stu,20);
	string st = stu;
   int stu2 = atoi(st.c_str());
	stumanager s;
	s = am.SelectLSByUser(stu2);
	if(s.getStNo()!=0){
    cout<<"please input your password"<<endl;
    cout<<"����:";
    char ps[20];
    cin.getline(ps,20);
	if(!(ps ==s.getpassword())){cout<<"�������"<<endl;return result;}
	else{cout<<"��ӭ����ѧ��ѡ��ϵͳ  "<<user<<endl;
     am.ExitConnect();
      stuMain(stu2);}
	}else{
	cout<<"���û��������ڣ�"<<endl;return result;}
}
else{
cout<<"����Ա��¼"<<endl;
cout<<"please input your password"<<endl;
cout<<"����:";
char psw[20];
  cin.getline(psw,20);
manager m = am.SelectByUser(user);
if(!(psw ==m.getPassword())){cout<<"�������"<<endl;return result;}

cout<<"��ӭ����ѧ��ѡ��ϵͳ������Ա��"<<endl;
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
cout<<"1����ѯ����ѧ����Ϣ"<<endl;
cout<<"2����ѯѧ����Ϣbyѧ��"<<endl;
cout<<"3����ѯѧ����Ϣbyרҵ"<<endl;
cout<<"4������һѧ����Ϣ"<<endl;
cout<<"5���޸�һѧ����Ϣ"<<endl;
cout<<"6���γ̵���ɾ�Ĳ�"<<endl;
cout<<"7��ѡ����Ϣ�Ĳ�ѯ"<<endl;
cout<<"8����ѧ���ɼ��޸�"<<endl;
cout<<"9��������ʦ"<<endl;
cout<<"10���˳�"<<endl;
	cout<<"���������ֲ���ϵͳ��";
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
	default :cout<<"����������������һ��"<<endl;
	}
	}
		cout<<"����Ա�˳�"<<endl;

}

//
void stuMain(int user){
	Student US;//ѧ����Ϣ
    StuCourse USC;
    SCLIST SCLI;//ѧ��ѡ����Ϣ
    SCLIST::iterator J;
    COURSELIST UCL;//ѧ����ѡ�Ŀε���Ϣ
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
cout<<"1���޸ĸ�������"<<endl;
cout<<"2����ѯ������Ϣ"<<endl;
cout<<"3����ѯ���˿γ���Ϣ"<<endl;
cout<<"4��ѡ��ing������"<<endl;
cout<<"5���˳�ѡ��ϵͳ"<<endl;
	cout<<"���������ֲ���ϵͳ��";
	cin>>n;
	switch(n){
    case 1 :changePWD(US);break;
	case 2 :selectUS(US);break;
	case 3 :selectUSCLIST(US,SCLI);break;
	case 4 :xuanke(US,SCLI,UCL);break;
	case 5 :return;
	default :cout<<"����������������һ��"<<endl;
	}
	}
	cout<<US.getStName()<<" �˳�"<<endl;
}
