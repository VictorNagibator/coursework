#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Logger.h"
#include "OrdersData.h"
#include "FileInfo.h"

void Logger::log(int IDOfOrder, OrderOperation operation) {
	std::ofstream file("..\\log.txt", std::ios::app);
	if (!file.is_open()) {
		throw std::invalid_argument("���� �� ������!");
	}
	std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	file << "���� " << FileInfo::getPath() << "; ����� " << IDOfOrder << " ��� " << operation << "; " << std::ctime(&time);
	file.close();
}