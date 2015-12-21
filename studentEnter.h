#include "ADOStudent.h"
typedef list<manager> MANAGERLIST;
typedef list<Student> StudentLIST;
typedef list<Course> COURSELIST;
typedef list<StuCourse> SCLIST;

//1
void changePWD(Student s){
     int user = s.getStNo();
	 char kong[5];
     cin.getline(kong,5);
	  char npsw[20];
	 cout<<"请输入新密码(<20)"<<endl;
     cin.getline(npsw,20);
	 ADOManager am ;
     am.OnInitADOConn();
     if(am.updatePWD(user,npsw)){cout<<"修改成功"<<endl;}
	 else{cout<<"something is wrong"<<endl;}
	 am.ExitConnect();
	 return;
}
//2
void selectUS(Student s){
     s.toString();
	 cout<<"continue:?";
	 string con;
	 cin>>con;
	 return;
}
//3
void selectUSCLIST(Student s,SCLIST scl){
	   SCLIST::iterator J;
     for(J = scl.begin();J!=scl.end();++J)
	{StuCourse sc = *J;
     sc.toString();
	 }
	 cout<<"continue:?";
	 string con;
	 cin>>con;
	 return;
}
//4
void xuanke(Student s,SCLIST scl,COURSELIST ucl){
	void insSC(Student s,SCLIST scl,COURSELIST ucl);//xuanke
	void delSC(Student s,SCLIST scl,COURSELIST ucl);//tuike
	COURSELIST::iterator I;
	for(I= ucl.begin();I!=ucl.end();++I){
	Course c = *I;
	c.toString();
	}
	cout<<"当前学分："<<s.getStnowcredit()<<endl;
    cout<<"1、选课"<<endl;
    cout<<"2、退课"<<endl;
	cout<<"3、exit"<<endl;
	int n = 0;
	cout<<"请输入数字操作系统：";
	cin>>n;
	switch(n){
	case 1 :insSC(s,scl,ucl);break;
	case 2 :delSC(s,scl,ucl);break;
	case 3 :return;
	default :cout<<"输入有误，请再输入一遍"<<endl;
	}
	 return;
}
//4.1
void insSC(Student s,SCLIST scl,COURSELIST ucl){
     cout<<"请选择你的课程:"<<endl;
	 string cno;
	 cin>>cno;
    Course cou;
	COURSELIST::iterator I;
	for(I= ucl.begin();I!=ucl.end();++I){
	Course c = *I;
	if(c.getCno()==cno){cou = c;cout<<"课程存在"<<endl;}
	}
     SCLIST::iterator J;
     for(J = scl.begin();J!=scl.end();++J)
	{StuCourse sc = *J;
     if(sc.getCno()==cno){cout<<"此课程已选修"<<endl;return;}
	 }
     if(cou.getCno()!=""){
	 StuCourse sco(s.getStNo(),s.getStgrade(),s.getStName(),s.getStmajor(),cou.getCno(),cou.getCname(),cou.getTname(),cou.getCtype(),cou.getCcredit(),"1","0");
	 ADOManager am ;
     am.OnInitADOConn();
     if(am.insertSC(sco,s,cou)){cout<<"添加成功"<<endl;}
	 else{cout<<"something is wrong"<<endl;}
	 am.ExitConnect();
	 }
	 
}
//4.2
void delSC(Student s,SCLIST scl,COURSELIST ucl){
	cout<<"你的课程："<<endl;
	 SCLIST::iterator J;
	 	COURSELIST::iterator I;
     for(J = scl.begin();J!=scl.end();++J)
	 {StuCourse sc = *J;
     sc.toString();
	 }
     cout<<"这里是退课操作"<<endl;
     string cno;
	 StuCourse sco ;
	 Course cou;
	 cout<<"请输入课程号:";
	 cin>>cno;
	 bool exist = false;
	 for(I= ucl.begin();I!=ucl.end();++I){
	Course c = *I;
	if(c.getCno()==cno){cou = c;}
	}
    for(J = scl.begin();J!=scl.end();++J)
	 {StuCourse sc = *J;
	if(sc.getCno()==cno){exist = true;sco = sc;}
	 }
	if(exist){
	 ADOManager am ;
     am.OnInitADOConn();
	 
     if(am.delectSC(sco,s,cou)){cout<<"删除成功"<<endl;}
	 else{cout<<"something is wrong"<<endl;}
	 am.ExitConnect();
	}else{cout<<"这门课不存在"<<endl;return;}
}