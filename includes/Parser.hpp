#ifndef PARSER_HPP
# define PARSER_HPP

#include "IOperand.hpp"
#include "Factory.hpp"
#include <vector>

template< typename T >
class Operand;

class Parser {

public: 

	Parser(std::vector<std::vector<std::string>> & input); 
	~Parser(void); 

	Parser &		operator=(Parser const & rhs);

	std::string const	toString(void) const;

	void	run();

private:
	std::vector<std::vector<std::string>> & _instructs;
    std::vector<const IOperand *> _array;

	Parser(void); 
	Parser(Parser const & src);

	void    push(eOperandType type, std::string const value);
    void    pop();
    void    dump();
    void    assert(eOperandType type, std::string const value);
    void    add();
    void    sub();
    void    mul();
    void    div();
    void    mod();
    void    print();
    void    exit();

	typedef	void (Parser::*functSimple)(void);
	functSimple	_functSimpleArray[9];
	void initFunctSimpleArray();

	eOperandType strToType(const std::string);
};

std::ostream &	operator<< (std::ostream & o, Parser const & rhs);

#endif

