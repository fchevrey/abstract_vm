
#include "AvmException.hpp"
#include <iostream>

AvmException::AvmException(std::string const & msg) : _msg(msg)
{
}
AvmException::AvmException(void)
{
}
const char* AvmException::what() const throw()
{
    return this->_msg.c_str();
}

AvmException::AvmException(AvmException const & src) 
{
    *this = src;
    return;
}

AvmException::~AvmException(void)
{
    return;
}

AvmException &	AvmException::operator=(AvmException const & rhs)
{
    this->_msg = rhs._msg;
    return *this;
}