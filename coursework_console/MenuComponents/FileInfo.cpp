#include <fstream>
#include <nlohmann/json.hpp>
#include "FileInfo.h"
#include "OrdersData.h"

using json = nlohmann::json;

std::string FileInfo::getPath() {
	if (path == "") {
		std::ifstream properties("..\\properties.json");
		json propertiesJson = json::parse(properties);
		properties.close();
		setPath(propertiesJson["lastFile"]);
	}
	return path;
}

void FileInfo::setPath(const std::string& newPath) {
	path = newPath;
	OrdersData::loadOrders(path);
}

bool FileInfo::isPathSet() {
	return getPath() != "";
}