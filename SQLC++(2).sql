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
select * from login_student
insert into student_base values('14108201','2','��ѩ��','�������','�����ѧԺ','Ů','20','19950801','ɽ��','13700000001','1041117417@qq.com','1041117417','0','','')
insert into student_base values('14108202','2','����Զ','�������','�����ѧԺ','Ů','20','19950802','����','13700000002','845285329@qq.com','845285329','0','','')
insert into student_base values('14108203','2','������','�������','�����ѧԺ','Ů','20','19950803','����','13700000003','965235247@qq.com','965235247','0','','')
insert into student_base values('14108204','2','������','�������','�����ѧԺ','Ů','21','19960804','�㽭','13700000004','790523576@qq.com','790523576','0','','')
insert into student_base values('14108205','2','�쾴��','�������','�����ѧԺ','Ů','19','19940805','�ӱ�','13700000005','1107137577@qq.com','1107137577','0','','')
insert into student_base values('14108206','2','�Կ�',  '�������','�����ѧԺ','Ů','20','19950806','����','13700000006','294742944@qq.com','294742944','0','','')
insert into student_base values('14108207','2','��Ӯ��','�������','�����ѧԺ','��','20','19950807','�Ϻ�','13700000007','1070674083@qq.com','1070674083','0','','')
insert into major_course values('S0500490','����ʵ��1','�������','�����ѧԺ')
insert into major_course values('A0501010','C���Գ������','�������','�����ѧԺ')
insert into course values('2','2014','1','S0500490','����ʵ��1','001','��','����120','����5-6','�����ѧԺ','0','1')
insert into course values('2','2014','1','S0507900','���ݿ�γ����','002','�ź��','1��205','����1-2','�����ѧԺ','0','1')
insert into course values('2','2014','1','A0501010','C���Գ������','003','����ƽ','3��120','��һ5-6','�����ѧԺ','0','4')
insert into course values('2','2014','1','A0507070','C++������������ƣ��ף�','004','������','7��301','����1-2','�����ѧԺ','0','3')
insert into course values('2','2014','1','B0504610','DSPԭ����Ӧ��','005','�Ώ�','7��305','��һ5-6','�����ѧԺ','0','1')
insert into course values('2','2014','1','A101326D','Android�ƶ�����','006','�캣��','12��205','����1-2','�����ѧԺ','0','5')
insert into course values('2','2014','1','B0507160','TCP/IPЭ��������ף�','007','����','3��301','��һ3-4','�����ѧԺ','0','3')
insert into course values('2','2014','1','A101218D','���������','007','����','3��201','����7-8','�����ѧԺ','0','3')
insert into course values('2','2014','1','B101304D','Oracle���ݿ�Ӧ��','008','�ź��','7��310','����3-4','�����ѧԺ','0','3')
insert into course values('2','2014','1','B0504850','��ý�����','009','�Ž���','����320','����3-4','�����ѧԺ','0','3')
insert into course values('2','2014','1','S101338D','�������ϵ�ṹ�γ����','010','����Ӣ','3��311','����1-2','�����ѧԺ','0','1')
insert into course values('2','2014','1','A0507030','��������ԭ���ף�','010','����Ӣ','7��311','�ܶ�1-2','�����ѧԺ','0','1')

insert into teacher values('001','��','��','32','�����ѧԺ')
insert into teacher values('002','�ź��','Ů','30','�����ѧԺ')
insert into teacher values('003','����ƽ','��','38','�����ѧԺ')
insert into teacher values('004','������','��','40','�����ѧԺ')
insert into teacher values('005','�Ώ�','��','28','�����ѧԺ')
insert into teacher values('006','�캣��','��','32','�����ѧԺ')
insert into teacher values('007','����','Ů','30','�����ѧԺ')
insert into teacher values('008','�ź��','Ů','35','�����ѧԺ')
insert into teacher values('009','�Ž���','��','40','�����ѧԺ')
insert into teacher values('010','����Ӣ','Ů','28','�����ѧԺ')

select * from course

select * from teacher
create table login
(
	users varchar(12) default'manager' not null,
	passwords varchar(20) not null
)
create table login_student
(
	StNo int not null 
	passwords varchar(20) not null
)
insert into login_student values('111','111')
/*************************���ݿ��������**************************/

create table test (staffid int,password varbinary(100))
insert into test(staffid,password ) values(1,convert(varbinary,'abcde'));
insert into test(staffid,password ) values(2,convert(varbinary,'fgh'));
select convert(char,password) from test where test.staffid='2'

create table test1 (a int,b varbinary(100))
/*Numeric(10,2) ָ�ֶ���������,����Ϊ10 С��Ϊ��λ��*/
insert into test1(a,b) values(1,convert(varbinary,12.50));
insert into test1(a,b) values(3,convert(varbinary,1250.32));
insert into test1(a,b) values('5',convert(varbinary,12.0))
insert into test1(a,b) values('6',convert(varbinary,12345.0))
select a,convert(dec(20,2),b) from test1 where a='6'
select a,convert(dec(14,2),b) from test1
/*****************************************************************/



create table student_base
(	
	StNo int not null constraint StNo_Prim primary key ,
	Stgrade int not null,
	StName varchar(16) not null,
	Stmajor varchar(16) not null,
	StCollege varchar(20) not null,
	Stsex char(5) default '��' not null,
	StAge int,
	Stbirthday int,
	StCity varchar(30) not null,
	StPhone varchar(20),
	StId varchar(20),
	StQQ varchar(15) ,
	Stnowcredit float,
	Stmincredit float,
	Stmaxcredit float
	
)

create table teacher
(
	Tno int not null constraint Tno_Prim primary key,
	Tname varchar(8) not null,
	Tsex char(5) default '��',
	Tage int ,
	Tcollege varchar(16)
)


create table course
(	Stgrade int not null, /*�󼸵� */
	Cyear int not null,		/*���*/
	Cterm int not null,		/*ѧ��*/
	Cno varchar(12) not null constraint Cno_Prim primary key,
	Cname varchar(16) not null,
	Tno int not null constraint CoTno_Prim foreign key references teacher(Tno),
	Tname varchar(8) not null,
	Cplace varchar(20) ,
	Ctime varchar(10) ,
	Ccollege varchar(20) not null,/*���ε�ѧԺ*/
	Ctype int  default '0' , /*0δ����1���ޣ�2ѡ�ޣ�3��ѡ*/
	Ccredit float not null
)

create table major_course
(
	MCcno varchar(12) not null constraint MCcno_Prim primary key,
	MCcname varchar(16) not null ,
	MCmajor varchar(16) not null,		/*����ѡ�ε�רҵ*/
	MCcollege varchar(20) not null		/*����ѡ�ε�ѧԺ*/
)
insert into major_course(MCcourseNo,MCcourseName,MCmajor,MCcollege) 
values()
select * from student_course
create table student_course
(
	StNo int not null constraint SCStNo_Prim foreign key references student_base(StNo), 
	Cno varchar(12) not null constraint SCCno_Prim foreign key references course(Cno), 
	SCstatus varchar(5) default '1',	/*0�Ѷ���1���ڶ�*/
	SCscore varchar(6),
)
insert into major_course values('','','','') 

select * from student_base,course,student_course 
where student_base.StNo=student_course.StNo and course.Cno=student_course.Cno

StNo Stgrade StName Stmajor Cno Cname Tname Ctype Ccredit SCstatus SCscore

select * from major_course,course where major_course.MCcno = course.Cno and major_course.MCmajor ='�������'