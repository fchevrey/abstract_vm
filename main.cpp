#include "Factory.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"

int main(int argc, char const *argv[])
{
	std::vector<std::vector<std::string>> stack;
	std::string		content;
	std::string		filename;
	Parser			*parser;
	bool			error = false;

	if (argc < -1)
		argv = nullptr;
	if (argc == 1)
		stack = Lexer::ReadStdInput(error);
	else if (argc > 1)
	{
		filename = argv[1];
		stack = Lexer::ReadFile(filename, error);
	}
	if (error)
		return 0;
	parser = new Parser(stack);
	parser->run();
	return 0;
}
