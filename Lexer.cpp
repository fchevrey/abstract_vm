#include "Lexer.hpp"
#include <sstream>
#include <regex>

std::vector<std::string>        Lexer::TypeToVec(const std::string &type)
{
	std::vector<std::string> 	vec;
	std::size_t    				begin;
	std::size_t   				end;

	begin = type.find("(");
	end = type.find(")");
	if (begin == std::string::npos || end == std::string::npos)
		return vec;
	vec.insert(vec.begin(), type.substr(begin +1, end - (begin + 1)));
    vec.insert(vec.begin(), type.substr(0, begin));
	return vec;
}
bool 							Lexer::CheckLine(const std::string &line)
{
	const std::regex		instr("^ *(pop|print|dump|exit|add|sub|mul|div|mod) *");
	const std::regex		instr_int("^ *(push|assert) *(int8|int16|int32)\\([0-9]*\\) *" );
	const std::regex		instr_float("^ *(push|assert) *(float|double)\\([0-9]*\\.{0,1}[0-9]*\\) *");

	if (std::regex_match(line, instr))
		return true;
	else if (std::regex_match(line, instr_int))
		return true;
	else if (std::regex_match(line, instr_float))
		return true;
	return false;
}
std::vector<std::string> 		Lexer::LineToVec(const std::string &line, int index, bool &error)
{
    std::stringstream			ss(line);
    std::vector<std::string> 	vec;
    std::vector<std::string> 	tmp_vec;
	std::string 				tmp_str;

	if (!Lexer::CheckLine(line))
	{
		std::cout << "error(s) in line " << index << " : " << line << std::endl;
		error = true;
	}
	while (!ss.eof())
	{
    	ss >> tmp_str;
		if (tmp_str.find("(") != std::string::npos) //if there is the chaacter '(' in the line
		{
			tmp_vec = Lexer::TypeToVec(tmp_str);
			vec.insert(vec.end(), tmp_vec.begin(), tmp_vec.end());
		}
		else
		{
    		vec.insert(vec.end(), tmp_str);
		}
	}
	return vec;
}
std::vector<std::vector<std::string>>     Lexer::ReadStdInput(bool &error)
{
	std::string    content;
    bool           quit = false;
    std::string    endstr = ";;";
    std::size_t    found;
	std::vector<std::vector<std::string>> stack;
	int				lineNb = 1;

    while(!quit)
    {
	    quit = !std::getline(std::cin, content);

        found = content.find(endstr);
        if (found != std::string::npos)
            quit = true;
        found = content.find(";");
        if (found != std::string::npos)
            content = content.substr(0, found);
		if (!content.empty())
			stack.insert(stack.end(), Lexer::LineToVec(content, lineNb, error));
		lineNb++;
    }
	return stack;
}
std::vector<std::vector<std::string>> 		Lexer::ReadFile(std::string filename, bool &error)
{
	std::ifstream	ifs(filename);
	//std::string		content;
	std::string		buff;
	std::size_t		found;
	std::vector<std::vector<std::string>> stack;
	int 			lineNb = 1;	

	if (!ifs || !ifs.is_open())
	{
		std::cout << "open error" << std::endl;
		error = true;
		return stack;
	}
	while (!ifs.eof())
	{
		std::getline(ifs, buff);
		found = buff.find(";");
        if (found != std::string::npos)
            buff = buff.substr(0, found);
		if (!buff.empty())
			stack.insert(stack.end(), Lexer::LineToVec(buff, lineNb, error));
		lineNb++;
	}
	ifs.close();
	//if (buff.empty())
	//	std::cout << "empty file" << std::endl;
	return stack;
}