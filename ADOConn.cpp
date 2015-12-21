#include "stdafx.h"  
#include "iostream"    
#include "string"  
#include "adoconn.H"

ADOConn::ADOConn(void){}
ADOConn::~ADOConn(void){}

void ADOConn::OnInitADOConn(void)
{
  CoInitialize(NULL);
	 try{
	 pConn->ConnectionString="Provider = SQLOLEDB.1;Persist Security Info = False;User ID=sa;Password=123456789;Initial Catalog =zuoye1";
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
void ADOConn::ExitConnect(void)
{
//关闭记录集和连接
if (pRec!=NULL)
{
pRec->Close();
 
}
pConn->Close();
::CoUninitialize();
}
 _RecordsetPtr& ADOConn::GetRecordSet(_bstr_t bstrSQL)
{
//TODO: insert return statement here
try
{
if (pConn==NULL)
{
OnInitADOConn();
}
//创建记录对象
pRec.CreateInstance(__uuidof(Recordset));
//取得表中记录
pRec->Open(bstrSQL,pConn.GetInterfacePtr(),adOpenDynamic,
adLockOptimistic,adCmdText);
}
catch (_com_error e)
{
e.Description();
}
return m_pRecordset;
}



}