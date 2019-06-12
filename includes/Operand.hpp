
#ifndef OPERAND_HPP
# define OPERAND_HPP

#include "IOperand.hpp"
#include "Factory.hpp"
#include "AvmException.hpp"
#include <cstdint>

template< typename T >
class Operand : public IOperand
{
public: 
	Operand<T>(std::string const value)
	{
		_type = compareType();
		_value = value;
	}

	Operand<T>(Operand const & src)
	{
		*this = src;
		return;
	}

	virtual ~Operand(void) {} 

	Operand &		operator=(Operand const & rhs)
	{
		_value = rhs._value;
		_type = rhs._type;
	}
	virtual int getPrecision(void) const
	{
		return static_cast<int>(_type);
	}

	virtual eOperandType getType(void) const
	{
		return _type;
	}

	virtual IOperand const *operator+(IOperand const &rhs) const
	{
		eOperandType 	computeType;
		int 			intResult;
		double		 	dbResult;

		if (rhs.getType() < _type)
		{
			computeType = _type;
		}
		else 
		{
			computeType = rhs.getType();
		}
		if (computeType >= eOperandType::Float)
		{
			dbResult = std::stod(_value) + std::stod(rhs.toString());
			return (Factory::instance->createOperand(computeType, std::to_string(dbResult)));
		}
		else
		{
			intResult = std::stoi(_value) + std::stoi(rhs.toString());
			return (Factory::instance->createOperand(computeType, std::to_string(intResult)));
		}
		return (nullptr);
	}

	virtual IOperand const *operator-(IOperand const &rhs) const 
	{
		eOperandType 	computeType = this->GetComputeType(*this, rhs);
		int 			intResult;
		double		 	dbResult;

		if (computeType >= eOperandType::Float)
		{
			dbResult = std::stod(_value) - std::stod(rhs.toString());
			return (Factory::instance->createOperand(computeType, std::to_string(dbResult)));
		}
		else
		{
			intResult = std::stoi(_value) - std::stoi(rhs.toString());
			return (Factory::instance->createOperand(computeType, std::to_string(intResult)));
		}
		return (nullptr);
	}

	virtual IOperand const *operator*(IOperand const &rhs) const
	{
		eOperandType 	computeType = this->GetComputeType(*this, rhs);
		int 			intResult;
		double		 	dbResult;

		if (computeType >= eOperandType::Float)
		{
			dbResult = std::stod(_value) * std::stod(rhs.toString());
			return (Factory::instance->createOperand(computeType, std::to_string(dbResult)));
		}
		else
		{
			intResult = std::stoi(_value) * std::stoi(rhs.toString());
			return (Factory::instance->createOperand(computeType, std::to_string(intResult)));
		}
		return (nullptr);
	}

	virtual IOperand const *operator/(IOperand const &rhs) const
	{
		eOperandType 	computeType = this->GetComputeType(*this, rhs);
		int 			intResult;
		double		 	dbResult;

		if (rhs.toString().compare("0") == 0)
			throw AvmException("Can't perform a division per 0 !");

		if (computeType >= eOperandType::Float)
		{
			dbResult = std::stod(_value) / std::stod(rhs.toString());
			return (Factory::instance->createOperand(computeType, std::to_string(dbResult)));
		}
		else
		{
			intResult = std::stoi(_value) / std::stoi(rhs.toString());
			return (Factory::instance->createOperand(computeType, std::to_string(intResult)));
		}
		return (nullptr);
	}

	virtual IOperand const *operator%(IOperand const &rhs) const
	{
		eOperandType 	computeType = this->GetComputeType(*this, rhs);
		int 			intResult;
		// double		 	dbResult;

		if (rhs.toString().compare("0") == 0)
			throw AvmException("Can't perform a modulo per 0 !");

		if (computeType >= eOperandType::Float)
		{
			throw AvmException("Can't perform a modulo with a float/double value");
		}
		else
		{
			intResult = std::stoi(_value) % std::stoi(rhs.toString());
			return (Factory::instance->createOperand(computeType, std::to_string(intResult)));
		}
		return (nullptr);
	}

	virtual std::string const	&toString(void) const
	{
		return _value;
	}

private:
	Operand<T>(void) {}

	eOperandType GetComputeType(const IOperand &a, const IOperand &b) const
	{
		if (a.getType() > b.getType())
		{
			return a.getType();
		}
		else 
		{
			return b.getType();
		}
	}

	eOperandType compareType()
	{
		if (std::is_same<T, __int8_t>::value )
			return eOperandType::Int8;
		else if (std::is_same<T, __int16_t>::value )
			return eOperandType::Int16;
		else if (std::is_same<T, __int32_t>::value )
			return eOperandType::Int32;
		else if (std::is_same<T, float>::value )
			return eOperandType::Float;
		else if (std::is_same<T, double>::value )
			return eOperandType::Double;
	}

	std::string 	_value;
	eOperandType 	_type;

};

template< typename T >
std::ostream &	operator<< (std::ostream & o, Operand<T> const & rhs)
{
	o << rhs.toString();
	return o;
}
#endif