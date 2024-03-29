﻿#pragma once
#include <iostream>

enum class DataTransferInterface { PATA, SATA, SAS, NVME };

static std::string dataTransferInterfaceToString(DataTransferInterface transferInterface) {
	std::string result;
	switch (transferInterface)
	{
	case DataTransferInterface::PATA:
		result = "PATA";
		break;
	case DataTransferInterface::SATA:
		result = "SATA";
		break;
	case DataTransferInterface::SAS:
		result = "SAS";
		break;
	case DataTransferInterface::NVME:
		result = "NVME";
		break;
	default:
		break;
	}
	return result;
}

static DataTransferInterface stringToDataTransferInterface(std::string transferInterface) {
	DataTransferInterface result;
	if (transferInterface == "PATA") {
		result = DataTransferInterface::PATA;
	}
	else if (transferInterface == "SATA") {
		result = DataTransferInterface::SATA;
	}
	else if (transferInterface == "SAS") {
		result = DataTransferInterface::SAS;
	}
	else if (transferInterface == "NVME") {
		result = DataTransferInterface::NVME;
	}
	else {
		throw std::invalid_argument("Некорректный тип интерфейса!");
	}
	return result;
}

static std::istream& operator >> (std::istream& in, DataTransferInterface& transferInterface) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		transferInterface = DataTransferInterface::PATA;
		break;
	case 1:
		transferInterface = DataTransferInterface::SATA;
		break;
	case 2:
		transferInterface = DataTransferInterface::SAS;
		break;
	case 3:
		transferInterface = DataTransferInterface::NVME;
		break;
	default:
		break;
	}
	return in;
}

static std::ostream& operator << (std::ostream& out, DataTransferInterface& transferInterface) {
	out << dataTransferInterfaceToString(transferInterface);
	return out;
}