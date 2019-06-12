#include "Parser.hpp"

// Parser::Parser(void)
// {
// 	return;
// }

Parser::Parser(std::vector<std::vector<std::string>> & input) : _instructs(input)
{
	initFunctSimpleArray();
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
	if ((*(_array.end() - 1))->getType() != type
		|| ((*(_array.end() - 1))->toString()).compare(value) != 0)
	{
		throw std::runtime_error("not the good type or value"); // SHOULD BE CUSTOM EXCEPTION
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


void Parser::initFunctSimpleArray()
{
	int i = 0;

	this->_functSimpleArray[i++] = &Parser::pop;
	this->_functSimpleArray[i++] = &Parser::dump;
	this->_functSimpleArray[i++] = &Parser::add;
	this->_functSimpleArray[i++] = &Parser::sub;
	this->_functSimpleArray[i++] = &Parser::mul;
	this->_functSimpleArray[i++] = &Parser::div;
	this->_functSimpleArray[i++] = &Parser::mod;
	this->_functSimpleArray[i++] = &Parser::print;
	this->_functSimpleArray[i++] = &Parser::exit;
}

eOperandType Parser::strToType(const std::string str)
{
	if (str.compare("int8") == 0)
		return eOperandType::Int8;
	else if (str.compare("int16") == 0)
		return eOperandType::Int16;
	else if (str.compare("int32") == 0)
		return eOperandType::Int32;
	else if (str.compare("float") == 0)
		return eOperandType::Float;
	else if (str.compare("double") == 0)
		return eOperandType::Double;
	return eOperandType::SizeMax; // Due to lexer, should never be used !!!
}

void Parser::run()
{
	std::string str[] = {"pop", "dump", "add", "sub", "mul", "div", "mod", "print", "exit"};
	
	for (size_t i = 0; i < _instructs.size(); i++)
	{
		try
		{
			if (_instructs[i][0].compare("push") == 0)
				push(strToType(_instructs[i][1]), _instructs[i][2]);
			else if (_instructs[i][0].compare("assert") == 0)
				assert(strToType(_instructs[i][1]), _instructs[i][2]);
			else
			{
				for (int j = 0; j < 9; j++)
				{
					if (str[j].compare(_instructs[i][0]) == 0)
						(this->*(_functSimpleArray[j]))();
				}
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
}



std::ostream &	operator<< (std::ostream & o, Parser const & rhs)
{
	o << rhs.toString();
	return o;
}