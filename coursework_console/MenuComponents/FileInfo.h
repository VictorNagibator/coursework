#pragma once
#include <iostream>

class FileInfo
{
public:
	static std::string getPath();
	static void setPath(const std::string& path);

	static bool isPathSet();
private:
	static inline std::string path;
};