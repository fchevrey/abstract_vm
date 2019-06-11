#include "Factory.hpp"
#include <vector>
#include <iostream>
#include <fstream>

std::string ReadStdInput(void)
{
	std::string content;
	
	//content << 
	return content;
}
std::string		ReadFile(std::string filename)
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

int main(int argc, char const *argv[])
{
	std::vector<std::vector<std::string>> stack;
	std::string		content;
	std::string		filename;
	Factory roger;

	if (argc < -1)
		argv = nullptr;
	if (argc == 1)
	{
		content = ReadStdInput();
	}
	else if (argc > 1)
	{
		filename = argv[1];
		content = ReadFile(filename);
	}
	if (content.empty())
	{
		std::cout << "Error : empty file or input" << std::endl;
		return 0;
	}
	
	return 0;
}
