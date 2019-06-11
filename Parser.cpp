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

void Parser::assert(eOperandType type, std::string const value)
{
	// std::string tmp = (*_array.end())->toString();

	if ((*(_array.end() - 1))->getType() != type
		|| ((*(_array.end() - 1))->toString()).compare(value) != 0)
	{
		throw std::runtime_error("not the good value"); // SHOULD BE CUSTOM EXCEPTION
		exit();
	}
}

void Parser::add()
{
	if (_array.size() >= 2)
	{
		IOperand const *a = *(_array.end() - 1);
		pop();
		IOperand const *b = *(_array.end() - 1);
		pop();
		_array.push_back(*a + *b);
	}
	else
		throw std::runtime_error("not enough elements to perform add()"); // SHOULD BE CUSTOM EXCEPTION
}

void Parser::sub()
{
	if (_array.size() >= 2)
	{
		IOperand const *a = *(_array.end() - 1);
		pop();
		IOperand const *b = *(_array.end() - 1);
		pop();
		_array.push_back(*a - *b);
	}
	else
		throw std::runtime_error("not enough elements to perform sub()"); // SHOULD BE CUSTOM EXCEPTION
}

void Parser::mul()
{
	if (_array.size() >= 2)
	{
		IOperand const *a = *(_array.end() - 1);
		pop();
		IOperand const *b = *(_array.end() - 1);
		pop();
		_array.push_back(*a * *b);
	}
	else
		throw std::runtime_error("not enough elements to perform mul()"); // SHOULD BE CUSTOM EXCEPTION
}

void Parser::div()
{
	if (_array.size() >= 2)
	{
		IOperand const *a = *(_array.end() - 1);
		pop();
		IOperand const *b = *(_array.end() - 1);
		pop();
		_array.push_back(*a / *b);
	}
	else
		throw std::runtime_error("not enough elements to perform div()"); // SHOULD BE CUSTOM EXCEPTION
}

void Parser::mod()
{
	if (_array.size() >= 2)
	{
		IOperand const *a = *(_array.end() - 1);
		pop();
		IOperand const *b = *(_array.end() - 1);
		pop();
		_array.push_back(*a % *b);
	}
	else
		throw std::runtime_error("not enough elements to perform mod()"); // SHOULD BE CUSTOM EXCEPTION
}

void Parser::print()
{
	if ((*(_array.end() - 1))->getType() == eOperandType::Int8)
	{
		int tmp = stoi((*(_array.end() - 1))->toString());
		std::cout << static_cast<char>(tmp);
	}
	else
	{
		throw std::runtime_error("no int8, no print"); // SHOULD BE CUSTOM EXCEPTION
		exit();
	}
}

void Parser::exit()
{
	std::cout << "Bye !" << std::endl;
	std::exit(EXIT_SUCCESS);
}

std::ostream &	operator<< (std::ostream & o, Parser const & rhs)
{
	o << rhs.toString();
	return o;
}