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
//��ʾ������Ϣ
AfxMessageBox(e.Description());
}
}
void ADOConn::ExitConnect(void)
{
//�رռ�¼��������
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
//������¼����
pRec.CreateInstance(__uuidof(Recordset));
//ȡ�ñ��м�¼
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