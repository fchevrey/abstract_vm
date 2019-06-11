#include "Lexer.hpp"
#include <sstream>


std::vector<std::string> Lexer::LineToVec(const std::string &line)
{
    std::stringstream	ss(line);
    std::vector<std::string> vec;
    vec.
}
std::string     Lexer::ReadStdInput(void)
{
	std::string    content;
    bool           quit = false;
    std::string    endstr = ";;";
    std::size_t    found;


    while(!quit)
    {

	    quit = !std::getline(std::cin, content);

        found = content.find(endstr);
        if (found != std::string::npos)
            quit = true;
        found = content.find(";");
        if (found != std::string::npos)
            content = content.substr(0, found);
            
    }
	//content << 
	return content;
}
std::string		Lexer::ReadFile(std::string filename)
{
	std::ifstream	ifs(filename);
	std::string		content;
	std::string		buff;
	bool			first = true;

	if (!ifs || !ifs.is_open())
	{
		std::cout << "open error" << std::endl;
		return content;
	}
	while (!ifs.eof())
	{
		std::getline(ifs, buff);
		if (!first && !ifs.eof())
		{
			content.append("\n");
		}
		if (!buff.empty())
			content.append(buff);
		first = false;
	}
	ifs.close();
	if (content.empty())
		std::cout << "empty file" << std::endl;
	return content;
}