#include "Factory.hpp"

Factory::Factory(void)
{
	return;
}

Factory::Factory(Factory const &src)
{
	//Do whatever needs to be done
	*this = src;
	return;
}

Factory::~Factory(void)
{
	return;
}

Factory &Factory::operator=(Factory const &rhs)
{
	//Do whatever needs to be done
	return *this;
}

std::string const Factory::toString(void) const
{
	// Return whatever needs to be returned
}

IOperand const *Factory::createOperand(eOperandType type, std::string const &value) const
{
	// In order to choose the right member function for the creation of the new IOperand,
	// you MUST create and use an array (here, a vector shows little interest) of pointers on
	// member functions with enum values as index.
	
	/*
	switch (type)
	{
	case Int8:
		return createInt8(value);
	case Int16:
		return createInt16(value);
	case Int32:
		return createInt32(value);
	case Float:
		return createFloat(value);
	case Double:
		return createDouble(value);

	default:
		return nullptr;
	}
	*/
}

std::ostream &operator<<(std::ostream &o, Factory const &rhs)
{
	o << rhs.toString();
	return o;
}