#pragma once

enum StatusType { ONHOLD, INPROCCESS, FINISHED };

static std::istream& operator >> (std::istream& in, StatusType& status) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		status = ONHOLD;
		break;
	case 1:
		status = INPROCCESS;
		break;
	case 2:
		status = FINISHED;
		break;
	default:
		break;
	}
	return in;
};
static std::ostream& operator << (std::ostream& out, StatusType& status) {
	switch (status)
	{
	case ONHOLD:
		out << "В ожидании";
		break;
	case INPROCCESS:
		out << "В ремонте";
		break;
	case FINISHED:
		out << "Готов";
		break;
	default:
		break;
	}
	return out;
};