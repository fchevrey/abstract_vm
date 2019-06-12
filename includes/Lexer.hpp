#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
# include <vector>
# include <fstream>

class Lexer 
{
public :
    static std::vector<std::vector<std::string>> 	ReadFile(std::string filename, bool &error);
    static std::vector<std::vector<std::string>>    ReadStdInput(bool &error);
    static void 		                            PrintStack(std::vector<std::vector<std::string>> stack);
private :
    Lexer(void);
    Lexer(const Lexer &rhs);
    Lexer &		operator=(Lexer const & rhs);
    virtual ~Lexer(void);
    static std::vector<std::string>                 LineToVec(const std::string &line, int index, bool &error);
    static std::vector<std::string>                 TypeToVec(const std::string &type);
    static bool 							        CheckLine(const std::string &line);
    static void                                     NoExit(void);
    static bool     _isExit;
};
#endif