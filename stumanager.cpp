#include "stdafx.h"
#include "iostream"
#include <string>
using namespace std;
class stumanager{
	private:
		int StNo;
		string password;
	public:
		stumanager(){
			StNo=0;
			password="";
		};
		stumanager(int StNo,string password){
			this->StNo=StNo;
			this->password=password;
		};
	~stumanager(){};
	int stumanager::getStNo(){
		return this->StNo;
	};
	string stumanager::getpassword(){
		return this->password;
	};
};