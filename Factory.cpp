#include "Factory.hpp"

Factory::Factory(void)
{
	initFunctArray();
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
	for (int i = 0; i < static_cast<int>(eOperandType.SizeMax); i++)
		_functArray[i] = rhs._functArray[i];
	return *this;
}

std::string const Factory::toString(void) const
{
	// Return whatever needs to be returned
}

void Factory::initFunctArray()
{
	int i = 0;

	_functArray[i++] = Factory::createInt8;
	_functArray[i++] = Factory::createInt16;
	_functArray[i++] = Factory::createInt32;
	_functArray[i++] = Factory::createFloat;
	_functArray[i++] = Factory::createDouble;
}

IOperand const *Factory::createOperand(eOperandType type, std::string const &value) const
{
	(this->*(_functArray[type]))(value);
}

IOperand const *Factory::createInt8(std::string const &value) const
{
	return new Operand<__int8_t>(value);
}

IOperand const *Factory::createInt16(std::string const &value) const
{
	return new Operand<__int16_t>(value);
}

IOperand const *Factory::createInt32(std::string const &value) const
{
	return new Operand<__int32_t>(value);
}

IOperand const *Factory::createFloat(std::string const &value) const
{
	return new Operand<float>(value);
}

IOperand const *Factory::createDouble(std::string const &value) const
{
	return new Operand<double>(value);
}

std::ostream &operator<<(std::ostream &o, Factory const &rhs)
{
	o << rhs.toString();
	return o;
}