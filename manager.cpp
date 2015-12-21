
#include "stdafx.h"  
#include "iostream"    
#include <string>
using namespace std;
class manager{
private:
	string  users;
	string passwords;
	bool logined;
public:
	manager(string users,string password){
	this->users = users;
	this->passwords = password;
	this->logined = true;
	};
	manager(){
	this->users = " ";
	this->passwords = " ";
	this->logined = false;
	}
	~manager(){cout<<" ";};
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