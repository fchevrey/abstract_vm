# abstract_vm
Project 42: abstract-vm (C++)

AbstractVM is a machine that uses a stack to compute simple arithmetic expressions.
These arithmetic expressions are provided to the machine as basic assembly programs.42 

This is the first project of 42 school's c++ branch.

Some of the architecture was impose to us, like the IOperand interface, use our own Exception class, use a factory class.

To made this projetc I use : 

- a Lexer/Parser method,
- all the Lexer function and variables are statics
- a factory class
- a singleton patterne to use the Facoty class method without instanciation (the prototypes of the function where givent in the subjects and are not static)
- a Template class that inherit from IOperand
