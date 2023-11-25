#pragma once
#include <iostream>

#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF", "EndOfFile")

class DatabaseConnector
{
public:
	DatabaseConnector(std::string path);
	~DatabaseConnector();

	void setPath(const std::string& path);

	void connect();
	void disconnect();
private:
	std::string path;

	_ConnectionPtr pConnection;
};