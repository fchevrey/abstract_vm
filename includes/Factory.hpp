#ifndef FACTORY_HPP
# define FACTORY_HPP

//#include "Operand.hpp"
#include "IOperand.hpp"
#include <vector>

template< typename T >
class Operand;

class Factory
{
public: 

    // Custom exception

    Factory(void); 
    Factory(Factory const & src); 
    ~Factory(void); 

	Factory &		operator=(Factory const & rhs);
    static Factory *instance;
    IOperand const * createOperand( eOperandType type, std::string const & value ) const;
	std::string	const toString() const;

    void    push(eOperandType type, std::string const value);
    void    pop();
    void    dump();
    void    assert(std::string const v);
    void    add();
    void    sub();
    void    mul();
    void    div();
    void    mod();
    void    print();
    void    exit();

private:
    std::vector<const IOperand *> _array;
    

	typedef	IOperand const * (Factory::*funct)(std::string const &) const;

	funct 		_functArray[eOperandType::SizeMax];

	void	initFunctArray();

    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;
};

std::ostream &	operator<< (std::ostream & o, Factory const & rhs);

#endif
