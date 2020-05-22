#include <iostream>
#include <string>
#include "interpreter.h"

int main(void) {
	//write
	Interpreter my_interpreter = Interpreter("interpreter_input.smp");
	my_interpreter.execute();

}