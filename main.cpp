#include "Factory.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"

void PrintStack(std::vector<std::vector<std::string>> stack)
{
	std::vector<std::vector<std::string>>::iterator it;
	std::vector<std::string>::iterator 				it2;
	int i = 0;

	for (it = stack.begin(); it < stack.end(); it++)
	{
    	std::cout << "line : " << i << std::endl;
		for (it2 = (*it).begin(); it2 < (*it).end(); it2++)
		{
    		std::cout << *it2 << std::endl;
		}
		i++;
	}
}

int main(int argc, char const *argv[])
{
	std::vector<std::vector<std::string>> stack;
	std::string		content;
	std::string		filename;
	Factory			factory;
	Parser			*parser;

	if (argc < -1)
		argv = nullptr;
	if (argc == 1)
	{
		stack = Lexer::ReadStdInput();
	}
	else if (argc > 1)
	{
		filename = argv[1];
		stack = Lexer::ReadFile(filename);
	}
	/*if (content.empty())
	{
		std::cout << "Error : empty file or input" << std::endl;
		return 0;
	}*/
	PrintStack(stack);

	std::cout << "\n---PARSER---\n" << std::endl;

	parser = new Parser(stack);
	parser->run();

//	std::cout << "content =  " << std::endl;
//	std::cout << content << std::endl;
	return 0;
}
