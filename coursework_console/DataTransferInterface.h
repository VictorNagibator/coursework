#pragma once

enum DataTransferInterface { PATA, SATA, SAS, NVME };

static std::istream& operator >> (std::istream& in, DataTransferInterface& interface) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		interface = PATA;
		break;
	case 1:
		interface = SATA;
		break;
	case 2:
		interface = SAS;
		break;
	case 3:
		interface = NVME;
		break;
	default:
		break;
	}
	return in;
}
static std::ostream& operator << (std::ostream& out, DataTransferInterface& interface) {
	switch (interface)
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