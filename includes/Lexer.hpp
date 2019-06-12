#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
# include <vector>
# include <fstream>

namespace Lexer 
{
    std::vector<std::vector<std::string>> 	ReadFile(std::string filename, bool &error);
    std::vector<std::vector<std::string>>   ReadStdInput(bool &error);
    std::vector<std::string>                LineToVec(const std::string &line, int index, bool &error);
    std::vector<std::string>                TypeToVec(const std::string &type);
    bool 							        CheckLine(const std::string &line);
};
#endif