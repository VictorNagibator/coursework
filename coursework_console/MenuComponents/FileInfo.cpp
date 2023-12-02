#include "FileInfo.h"

std::string FileInfo::getPath() {
	return path;
}

void FileInfo::setPath(const std::string& newPath) {
	path = newPath;
}

bool FileInfo::isPathSet() {
	return path != "";
}