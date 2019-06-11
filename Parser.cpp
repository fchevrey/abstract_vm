#include "Parser.hpp"

// Parser::Parser(void) : _instructs(new std::vector<std::vector<std::string>>)
// Parser::Parser(void) : Parser()
// {
// 	return;
// }

Parser::Parser(std::vector<std::vector<std::string>> & input) : _instructs(input)
{
	return;
}

// Parser::Parser(Parser const & src) 
// {
// 	//Do whatever needs to be done
// 	*this = src;
// 	return;
// }

Parser::~Parser(void)
{
	return;
}

Parser &	Parser::operator=(Parser const & rhs)
{
	//Do whatever needs to be done
	_instructs = rhs._instructs;
	_array = rhs._array;
	return *this;
}

std::string const Parser::toString(void) const
{
	// Return whatever needs to be returned
	return "";
}



void Parser::push(eOperandType type, std::string const value)
{
	_array.push_back(Factory::instance->createOperand(type, value));
}

void Parser::pop()
{
	if (_array.size() > 0)
		_array.pop_back();
	else
		throw std::runtime_error("can't pop an empty vector !"); // SHOULD BE CUSTOM EXCEPTION
}

void Parser::dump()
{
	for (std::vector<const IOperand *>::iterator it = _array.begin(); it != _array.end(); it++)
		std::cout << (*it)->toString() << std::endl;
}

void Parser::assert(std::string const v)
{
	// std::string tmp = (*_array.end())->toString();

	if (((*_array.end())->toString()).compare(v) != 0)
		throw std::runtime_error("not the good value"); // SHOULD BE CUSTOM EXCEPTION
}

void Parser::add()
{
	if (_array.size() >= 2)
	{
		// IOperand *a = new Operand(*_array.end());
		// pop();
		// IOperand *b = new Operand(*_array.end());
		// pop();
		;
	}
	else
		throw std::runtime_error("not enough elements to perform add()"); // SHOULD BE CUSTOM EXCEPTION
}



std::ostream &	operator<< (std::ostream & o, Parser const & rhs)
{
	o << rhs.toString();
	return o;
}