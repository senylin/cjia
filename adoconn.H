#if !defined(AFX_ADOCONN_H__56A56674_91DC_43BB_BD09_9A0C8995161E__INCLUDED_)
#define AFX_ADOCONN_H__56A56674_91DC_43BB_BD09_9A0C8995161E__INCLUDED_
 
#import "C:\Program Files\Common Files\System\ado\msado15.dll"no_namespace \
rename("EOF","adoEOF")rename("BOF","adoBOF")
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class ADOConn
{
public:
ADOConn(void);
~ADOConn(void);
 
 
	 _ConnectionPtr pConn(__uuidof(Connection));
	 _RecordsetPtr pRec(__uuidof(Recordset));
	  _CommandPtr pCmd(__uuidof(Command));
/* //封闭ADO类，方便以后使用 */
void OnInitADOConn(void);
void ExitConnect(void);
// 打开记录集
_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
};
#endif // !defined(AFX_ADOCONN_H__56A56674_91DC_43BB_BD09_9A0C8995161E__INCLUDED_)