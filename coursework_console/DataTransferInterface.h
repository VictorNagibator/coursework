#pragma once

enum DataTransferInterface { PATA, SATA, SAS, NVME };

static std::istream& operator >> (std::istream& in, DataTransferInterface& transferInterface) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		transferInterface = PATA;
		break;
	case 1:
		transferInterface = SATA;
		break;
	case 2:
		transferInterface = SAS;
		break;
	case 3:
		transferInterface = NVME;
		break;
	default:
		break;
	}
	return in;
}
static std::ostream& operator << (std::ostream& out, DataTransferInterface& transferInterface) {
	switch (transferInterface)
	{
	case PATA:
		out << "PATA";
		break;
	case SATA:
		out << "SATA";
		break;
	case SAS:
		out << "SAS";
		break;
	case NVME:
		out << "NVMe";
		break;
	default:
		break;
	}
	return out;
}