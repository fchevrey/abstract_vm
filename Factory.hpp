#ifndef FACTORY_HPP
# define FACTORY_HPP

#include "abstract_vm.hpp"

class Factory {

public: 

    Factory(void); 
    Factory(Factory const & src); 
    ~Factory(void); 

	Factory &		operator=(Factory const & rhs);
    IOperand const * createOperand( eOperandType type, std::string const & value ) const;
	std::string	const toString() const;

private:
	typedef	IOperand const * (Factory::*funct)(std::string const &) const;

	funct 		_functArray[eOperandType.SizeMax];
	// funct 		_functArray[5];

	void	initFunctArray();

    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;
};

std::ostream &	operator<< (std::ostream & o, Factory const & rhs);

#endif
