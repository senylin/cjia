create database studentManager
ON
(	name=studentManager_Data,
	filename='D:\SQL_table\studentManagerData.mdf',
	size =10,
	maxsize =50,
	filegrowth=5
)
LOG ON
(	name=personsManager_Log,
	filename='D:\SQL_table\studentManagerData.ldf',
	size =5,
	maxsize =25,
	filegrowth=5
)
create table login
(
	users varchar(12) default'manager' not null,
	passwords varchar(20) not null
)
create table login_student
(
	StNo int not null constraint login_student_name_Prim primary key,
	passwords varchar(20) not null
)
select * from login_student
insert into login_student values(1,'123')
create table student_base
(	
	StNo int not null ,
	Stgrade int not null,
	StName varchar(16) not null,
	Stmajor varchar(16) not null,
	StCollege varchar(20) not null,
	Stsex char(2) default '��' not null,
	StAge int,
	Stbirthday int,
	StCity varchar(30) not null,
	StPhone varchar(20),
	StId varchar(20),
	StQQ varchar(15) ,
	Stnowcredit float,
	Stmincredit float,
	Stmaxcredit float
	constraint StNo_Prim primary key(StNo)
)
select * from student_base
insert into student_base values('14108201','2','��ѩ��','�������','�����ѧԺ','Ů','20','19950801','ɽ��',,'13700000001','1041117417@qq.com','1041117417')
insert into student_base values('14108202','����Զ','Ů','20','19950802','����','�������','13700000002','845285329@qq.com','845285329')
insert into student_base values('14108203','������','Ů','20','19950803','����','�������','13700000003','965235247@qq.com','965235247')
insert into student_base values('14108204','������','Ů','20','19950804','�㽭','�������','13700000004','790523576@qq.com','790523576')
insert into student_base values('14108205','�쾴��','Ů','20','19950805','�ӱ�','�������','13700000005','1107137577@qq.com','1107137577')
insert into student_base values('14108206','�Կ�','Ů','20','19950806','����','�������','13700000006','294742944@qq.com','294742944')
insert into student_base values('14108207','��Ӯ��','��','20','19950807','�Ϻ�','�������','13700000007','1070674083@qq.com','1070674083')
	/*
	Stgrade int not null,   //�󼸵�
	Cyear int not null,		//���
	Cterm int not null,		//ѧ��
	Ctype int  default '0' ,   //0δ����1���ޣ�2ѡ�ޣ�3��ѡ
	*/
create table course
(	Stgrade int not null, 
	Cyear int not null,		
	Cterm int not null,		
	Cno varchar(12) not null,
	Cname varchar(16) not null,
	Tno int not null constraint Ctno_Prim foreign key references teacher(Tno),
	Tname varchar(8) not null,
	Cplace varchar(20) ,
	Ctime varchar(10) ,
	Ccollege varchar(20) not null,
	Ctype int  default '0' , 
	Ccredit float not null
	constraint Cno_Prim primary key(Cno)
)
insert into course values(5,5,5,'5','5',6,'5','5','5','5',5,5)
select * from course;
insert into course values('3','S0500490','����ʵ��1','��','����120','����5-6','1')
insert into course values('3','S0500510','����ʵ��3','��','����122','����5-6','1')
insert into course values('3','S0500520','����ʵ��4','��','����120','�ܶ�5-6','2')

create table teacher
(
	Tno int not null,
	Tname varchar(8) not null,
	Tsex char default '��',
	Tage int ,
	Tcollege varchar(16)
	constraint Tno_Prim primary key(Tno)
)
select * from teacher
insert into teacher values(7,'2','3',4,'5')
create table major_course
(
	MCcourseNo varchar(12) not null constraint MCtno_Prim foreign key references course(Cno),
	MCcourseName varchar(16) not null ,
	MCmajor varchar(16) not null,
	MCcollege varchar(20) not null
)
select * from major_course
select * from major_course,course where major_course.MCcourseNo = course.Cno and major_course.MCmajor = '1';
create table student_course
(
	StNo int not null ,  
	Cno varchar(12) not null, 
	SCscore varchar(6),
	SCstatus varchar(5) default '1'   
)
select * from student_course

insert into student_course values(2,'2','0','98')
select * from student_course,student_base,course  where student_course.StNo=student_base.StNo and course.Cno=student_course.Cno 



teacher->course->major_course/student_course
                   student ->