#include "Factory.hpp"
#include "Lexer.hpp"

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
		content = Lexer::ReadStdInput();
	}
	else if (argc > 1)
	{
		filename = argv[1];
		content = Lexer::ReadFile(filename);
	}
	if (content.empty())
	{
		std::cout << "Error : empty file or input" << std::endl;
		return 0;
	}
	std::cout << "content =  " << std::endl;
	std::cout << content << std::endl;
	return 0;
}
