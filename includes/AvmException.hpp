#ifndef AVMEXCEPTION_HPP
# define AVMEXCEPTION_HPP

# include <iostream>

class AvmException : std::exception
{
public: 
    AvmException(std::string const & msg); 
    AvmException(AvmException const & src); 
    virtual ~AvmException(void); 
    virtual const char* what() const throw();
	AvmException &		operator=(AvmException const & rhs);
private:
    std::string _msg;
    AvmException(void); 
};

std::ostream &	operator<< (std::ostream & o, AvmException const & rhs);

#endif