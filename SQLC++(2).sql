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
insert into student_base values('14108201','2','郭雪纯','软件工程','计算机学院','女','20','19950801','山西','13700000001','1041117417@qq.com','1041117417','0','','')
insert into student_base values('14108202','2','胡曦远','软件工程','计算机学院','女','20','19950802','安徽','13700000002','845285329@qq.com','845285329','0','','')
insert into student_base values('14108203','2','黄文妃','软件工程','计算机学院','女','20','19950803','广西','13700000003','965235247@qq.com','965235247','0','','')
insert into student_base values('14108204','2','金蕴竹','软件工程','计算机学院','女','21','19960804','浙江','13700000004','790523576@qq.com','790523576','0','','')
insert into student_base values('14108205','2','徐敬艳','软件工程','计算机学院','女','19','19940805','河北','13700000005','1107137577@qq.com','1107137577','0','','')
insert into student_base values('14108206','2','赵康',  '软件工程','计算机学院','女','20','19950806','辽宁','13700000006','294742944@qq.com','294742944','0','','')
insert into student_base values('14108207','2','陈赢正','软件工程','计算机学院','男','20','19950807','上海','13700000007','1070674083@qq.com','1070674083','0','','')
insert into major_course values('S0500490','创新实践1','软件工程','计算机学院')
insert into major_course values('A0501010','C语言程序设计','软件工程','计算机学院')
insert into course values('2','2014','1','S0500490','创新实践1','001','仇建','六教120','周五5-6','计算机学院','0','1')
insert into course values('2','2014','1','S0507900','数据库课程设计','002','张红娟','1教205','周五1-2','计算机学院','0','1')
insert into course values('2','2014','1','A0501010','C语言程序设计','003','韩建平','3教120','周一5-6','计算机学院','0','4')
insert into course values('2','2014','1','A0507070','C++面向对象程序设计（甲）','004','李卫明','7教301','周三1-2','计算机学院','0','3')
insert into course values('2','2014','1','B0504610','DSP原理与应用','005','任彧','7教305','周一5-6','计算机学院','0','1')
insert into course values('2','2014','1','A101326D','Android移动开发','006','徐海涛','12教205','周五1-2','计算机学院','0','5')
insert into course values('2','2014','1','B0507160','TCP/IP协议分析（甲）','007','徐明','3教301','周一3-4','计算机学院','0','3')
insert into course values('2','2014','1','A101218D','计算机网络','007','徐明','3教201','周四7-8','计算机学院','0','3')
insert into course values('2','2014','1','B101304D','Oracle数据库应用','008','张红娟','7教310','周三3-4','计算机学院','0','3')
insert into course values('2','2014','1','B0504850','多媒体计算','009','张建海','六教320','周五3-4','计算机学院','0','3')
insert into course values('2','2014','1','S101338D','计算机体系结构课程设计','010','赵辽英','3教311','周四1-2','计算机学院','0','1')
insert into course values('2','2014','1','A0507030','计算机组成原理（甲）','010','赵辽英','7教311','周二1-2','计算机学院','0','1')

insert into teacher values('001','仇建','男','32','计算机学院')
insert into teacher values('002','张红娟','女','30','计算机学院')
insert into teacher values('003','韩建平','男','38','计算机学院')
insert into teacher values('004','李卫明','男','40','计算机学院')
insert into teacher values('005','任彧','男','28','计算机学院')
insert into teacher values('006','徐海涛','男','32','计算机学院')
insert into teacher values('007','徐明','女','30','计算机学院')
insert into teacher values('008','张红娟','女','35','计算机学院')
insert into teacher values('009','张建海','男','40','计算机学院')
insert into teacher values('010','赵辽英','女','28','计算机学院')

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
/*************************数据库密码加密**************************/

create table test (staffid int,password varbinary(100))
insert into test(staffid,password ) values(1,convert(varbinary,'abcde'));
insert into test(staffid,password ) values(2,convert(varbinary,'fgh'));
select convert(char,password) from test where test.staffid='2'

create table test1 (a int,b varbinary(100))
/*Numeric(10,2) 指字段是数字型,长度为10 小数为两位的*/
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
	Stsex char(5) default '男' not null,
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
	Tsex char(5) default '男',
	Tage int ,
	Tcollege varchar(16)
)


create table course
(	Stgrade int not null, /*大几的 */
	Cyear int not null,		/*年份*/
	Cterm int not null,		/*学期*/
	Cno varchar(12) not null constraint Cno_Prim primary key,
	Cname varchar(16) not null,
	Tno int not null constraint CoTno_Prim foreign key references teacher(Tno),
	Tname varchar(8) not null,
	Cplace varchar(20) ,
	Ctime varchar(10) ,
	Ccollege varchar(20) not null,/*开课的学院*/
	Ctype int  default '0' , /*0未定，1必修，2选修，3公选*/
	Ccredit float not null
)

create table major_course
(
	MCcno varchar(12) not null constraint MCcno_Prim primary key,
	MCcname varchar(16) not null ,
	MCmajor varchar(16) not null,		/*可以选课的专业*/
	MCcollege varchar(20) not null		/*可以选课的学院*/
)
insert into major_course(MCcourseNo,MCcourseName,MCmajor,MCcollege) 
values()
select * from student_course
create table student_course
(
	StNo int not null constraint SCStNo_Prim foreign key references student_base(StNo), 
	Cno varchar(12) not null constraint SCCno_Prim foreign key references course(Cno), 
	SCstatus varchar(5) default '1',	/*0已读，1正在读*/
	SCscore varchar(6),
)
insert into major_course values('','','','') 

select * from student_base,course,student_course 
where student_base.StNo=student_course.StNo and course.Cno=student_course.Cno

StNo Stgrade StName Stmajor Cno Cname Tname Ctype Ccredit SCstatus SCscore

select * from major_course,course where major_course.MCcno = course.Cno and major_course.MCmajor ='软件工程'