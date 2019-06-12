#ifndef AVMEXCEPTION_HPP
# define AVMEXCEPTION_HPP

# include <iostream>

class AvmException : std::exception
{
public: 
    AvmException(std::string const & msg) throw(); 
    AvmException(AvmException const & src) throw(); 
    virtual ~AvmException(void) throw(); 
    virtual const char* what() const throw();
	AvmException &		operator=(AvmException const & rhs);
private:
    std::string _msg;
    AvmException(void); 
};
#endif