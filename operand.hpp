
#ifndef OPERAND_HPP
# define OPERAND_HPP

#include "abstract_vm.hpp"
#include "Factory.hpp"

template< typename T >
class Operand : public IOperand
{
public: 

	Operand<T>(Operand const & src)
	{
		*this = src;
		return;
	}
	~Operand(void) {} 

	Operand &		operator=(Operand const & rhs)
	{
		_value = rhs._value;
		_type = rhs._type;
	}
	virtual int getPrecision(void) const
	{
		return 1;// not impletented yet
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
			computeType = rhs.GetType();
		}
		if (computeType >= eOperandType.float)
		{
			dbResult = std::atof(_value) + std::atof(rhs.toSTring());
			return (createOperand(computeType, std::to_string(dbResult)));
		}
		else
		{
			intResult = std::atoi(_value) + std::atoi(rhs.toSTring());
			return (createOperand(computeType, std::to_string(intResult)));
		}
		return (nullptr);
	} 
	virtual IOperand const *operator-(IOperand const &rhs) const 
	{
		eOperandType 	computeType GetComputeType(*this, rhs);
		int 			intResult;
		double		 	dbResult;

		if (computeType >= eOperandType.float)
		{
			dbResult = std::atof(_value) - std::atof(rhs.toSTring());
			return (createOperand(computeType, std::to_string(dbResult)));
		}
		else
		{
			intResult = std::atoi(_value) - std::atoi(rhs.toSTring());
			return (createOperand(computeType, std::to_string(intResult)));
		}
		return (nullptr);
	} 
	virtual IOperand const *operator*(IOperand const &rhs) const
	{
		eOperandType 	computeType GetComputeType(*this, rhs);
		int 			intResult;
		double		 	dbResult;

		if (computeType >= eOperandType.float)
		{
			dbResult = std::atof(_value) * std::atof(rhs.toSTring());
			return (createOperand(computeType, std::to_string(dbResult)));
		}
		else
		{
			intResult = std::atoi(_value) * std::atoi(rhs.toSTring());
			return (createOperand(computeType, std::to_string(intResult)));
		}
		return (nullptr);
	}
	virtual IOperand const *operator/(IOperand const &rhs) const
	{
		eOperandType 	computeType GetComputeType(*this, rhs);
		int 			intResult;
		double		 	dbResult;

		if (computeType >= eOperandType.float)
		{
			dbResult = std::atof(_value) / std::atof(rhs.toSTring());
			return (createOperand(computeType, std::to_string(dbResult)));
		}
		else
		{
			intResult = std::atoi(_value) / std::atoi(rhs.toSTring());
			return (createOperand(computeType, std::to_string(intResult)));
		}
		return (nullptr);
	}
	virtual IOperand const *operator%(IOperand const &rhs) const
	{
		eOperandType 	computeType GetComputeType(*this, rhs);
		int 			intResult;
		double		 	dbResult;

		if (computeType >= eOperandType.float)
		{
			dbResult = std::atof(_value) % std::atof(rhs.toSTring());
			return (createOperand(computeType, std::to_string(dbResult)));
		}
		else
		{
			intResult = std::atoi(_value) % std::atoi(rhs.toSTring());
			return (createOperand(computeType, std::to_string(intResult)));
		}
		return (nullptr);
	}
	std::string const	toString(void) const
	{
		return _value;
	}


private:
	Operand<T>(void) {}
	eOperandType GetComputeType(IOperand &a, IOperand &b)
	{
		if (rhs.getType() < _type)
		{
			return a.GetType();
		}
		else 
		{
			return b.GetType();
		}
	}

	std::string 	_value;
	int				_intValue;
	double			_dbValue;
	eOperandType 	_type;

};
template< typename T >
std::ostream &	operator<< (std::ostream & o, Operand<T> const & rhs)
{
	o << rhs.toString();
	return o;
}
#endif