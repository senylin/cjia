#include "stdafx.h"  
#include "iostream"    
#include "string"    
//步骤1：添加对ADO的支持  
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")    
using namespace std;  

/* class manager{
private:
	string users;
	string passwords;
	bool logined;
public:
	manager(string users,string password){
	this->users = users;
	this->passwords = password;
	this->logined = true;
	};
	~manager(){cout<<"clear"<<endl;};
	string manager::getUser(){
	return this->users;
	}
    string manager::getPassword(){
	return this->passwords;
	}
	bool manager::getLogined(){
	return this->logined;
	}

};
*/
/*
class ADOManager{
public:
_ConnectionPtr pConn(__uuidof(Connection));
_RecordsetPtr pRec(__uuidof(Recordset));
_CommandPtr pCmd(__uuidof(Command));
ADOManager(void);
~ADOManager(void);
void OnInitADOConn(void);
void ExitConnect(void);
// 打开记录集
//_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);

}
ADOManager::ADOManager(void){}
ADOManager::~ADOManager(void){}

void ADOManager::OnInitADOConn(void)
{
  CoInitialize(NULL);
	 try{
	 pConn->ConnectionString="Provider = SQLOLEDB.1;Persist Security Info = False;User ID=sa;Password=123456789;Initial Catalog =studentManager";
	  printf("hello0\n");
      pConn->Open("","","",adConnectUnspecified);
	 printf("hello1\n");
}
catch (_com_error e)
{
//显示错误信息
AfxMessageBox(e.Description());
}
}
void ADOManager::ExitConnect(void)
{
//关闭记录集和连接
if (pRec!=NULL)
{
pRec->Close();
 
}
pConn->Close();
::CoUninitialize();
}
manager ADOManager::SelectByUser(string user){
	manager m;
	try
	{
	while(!pRec->adoEOF)
	{
		if((_bstr_t)pRec->GetCollect("users")==user)
		{string user =(_bstr_t)pRec->GetCollect("users"); string password = (_bstr_t)pRec->GetCollect("passwords");
		 m = new manager(user,password);
		}
	    pRec->MoveNext();
	}
	return m;
	}catch(_com_error& e)
       {
        cout<<"as"<<endl;
	 }return m;
}
*/
int main(){
  CoInitialize(NULL);
  _ConnectionPtr pConn(__uuidof(Connection));
  _RecordsetPtr pRec(__uuidof(Recordset));
  _CommandPtr pCmd(__uuidof(Command));
	 try{
	 pConn->ConnectionString="Provider = SQLOLEDB.1;Persist Security Info = False;User ID=sa;Password=123456789;Initial Catalog =studentManager";
	  printf("hello0\n");
      pConn->Open("","","",adConnectUnspecified);
	 printf("hello1\n");
	    string strSQL="select * from login";
        pRec=pConn->Execute("select * from login",NULL,adCmdText);
			while(!pRec->adoEOF)
	{
	   printf((_bstr_t)pRec->GetCollect("users"));
	    pRec->MoveNext();
	}
}
catch (_com_error e)
{
}
return 0;
}