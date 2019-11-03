#include <iostream>
#include <string>
#include "interpreter.h"

int main(void) {
	//write
	Interpreter my_interpreter = Interpreter("Interpreter_Input.smp");
	my_interpreter.execute();

}