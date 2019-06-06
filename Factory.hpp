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

private:
    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;
};

std::ostream &	operator<< (std::ostream & o, Factory const & rhs);

#endif


#include "Factory.hpp"
#include <iostream>

Factory::Factory(void)
{
    return;
}

Factory::Factory(Factory const & src) 
{
    //Do whatever needs to be done
    *this = src;
    return;
}

Factory::~Factory(void)
{
    return;
}

Factory &	Factory::operator=(Factory const & rhs)
{
    //Do whatever needs to be done
    return *this;
}

std::string const Factory::toString(void) const
{
    // Return whatever needs to be returned
}

std::ostream &	operator<< (std::ostream & o, Factory const & rhs)
{
    o << rhs.toString();
    return o;
}