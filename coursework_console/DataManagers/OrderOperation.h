#pragma once

enum class OrderOperation
{
	Adding,
	Editing,
	Removing
};

inline std::ostream& operator <<(std::ostream& out, OrderOperation operation) {
	switch (operation) {
	case OrderOperation::Adding:
		out << "Adding";
		break;
	case OrderOperation::Editing:
		out << "Editing";
		break;
	case OrderOperation::Removing:
		out << "Removing";
		break;
	}
	return out;
}