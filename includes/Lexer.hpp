#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
#include <vector>
#include <fstream>

namespace Lexer 
{
    std::string		        ReadFile(std::string filename);
    std::string             ReadStdInput(void);
    std::vector<std::string> LineToVec(const std::string &line);
};
#endif