#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
# include <vector>
# include <fstream>

namespace Lexer 
{
    std::vector<std::vector<std::string>> 	ReadFile(std::string filename);
    std::vector<std::vector<std::string>>   ReadStdInput(void);
    std::vector<std::string>                LineToVec(const std::string &line);
    std::vector<std::string>                TypeToVec(const std::string &type);
    bool 							        CheckLine(const std::string &line);
};
#endif