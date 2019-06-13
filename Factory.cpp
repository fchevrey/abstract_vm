#include "Factory.hpp"
#include "Operand.hpp"

Factory 		*Factory::instance = new Factory();
Factory::Factory(void)
{
	initFunctArray();
	return;
}

Factory::Factory(Factory const &src)
{
	*this = src;
	return;
}

Factory::~Factory(void)
{
	return;
}

Factory &Factory::operator=(Factory const &rhs)
{
	for (int i = 0; i < eOperandType::SizeMax; i++)
		_functArray[i] = rhs._functArray[i];
	return *this;
}

std::string const Factory::toString(void) const
{
	// Return whatever needs to be returned
	return std::string();
}

void Factory::initFunctArray()
{
	if (Factory::instance == nullptr)
		Factory::instance = this;
	int i = 0;

	this->_functArray[i++] = &Factory::createInt8;
	this->_functArray[i++] = &Factory::createInt16;
	this->_functArray[i++] = &Factory::createInt32;
	this->_functArray[i++] = &Factory::createFloat;
	this->_functArray[i++] = &Factory::createDouble;
}

void Factory::flowCompare(std::string const &value, std::string const &ref) const
{
	if (value.length() > ref.length())
	{
		if (ref[0] == '-')
			throw AvmException("underflow A!");
		throw AvmException("overflow A!");
	}
	if (value.length() == ref.length() && value.compare(ref) > 0)
	{
		if (ref[0] == '-')
			throw AvmException("underflow B!");
		throw AvmException("overflow B!");
	}
}

IOperand const *Factory::createOperand(eOperandType type, std::string const &value) const
{
	return (this->*(_functArray[type]))(value);
}

IOperand const *Factory::createInt8(std::string const &value) const
{
	if (value[0] == '-')
		flowCompare(value, std::to_string(INT8_MIN));
	else
		flowCompare(value, std::to_string(INT8_MAX));
	return new Operand<__int8_t>(value);
}

IOperand const *Factory::createInt16(std::string const &value) const
{
	if (value[0] == '-')
		flowCompare(value, std::to_string(INT16_MIN));
	else
		flowCompare(value, std::to_string(INT16_MAX));
	return new Operand<__int16_t>(value);
}

IOperand const *Factory::createInt32(std::string const &value) const
{
	if (value[0] == '-')
		flowCompare(value, std::to_string(INT32_MIN));
	else
		flowCompare(value, std::to_string(INT32_MAX));
	return new Operand<__int32_t>(value);
}

IOperand const *Factory::createFloat(std::string const &value) const
{	
	if (value[0] == '-')
		flowCompare(value, std::to_string(-3.402823466e+38F));
	else
		flowCompare(value, std::to_string(3.402823466e+38F));
	return new Operand<float>(value);
}

IOperand const *Factory::createDouble(std::string const &value) const
{
	if (value[0] == '-')
		flowCompare(value, std::to_string(-1.7976931348623158e+308));
	else
		flowCompare(value, std::to_string(1.7976931348623158e+308));
	return new Operand<double>(value);
}

std::ostream &operator<<(std::ostream &o, Factory const &rhs)
{
	o << rhs.toString();
	return o;
}