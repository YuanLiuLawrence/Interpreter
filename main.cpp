#include <iostream>
#include <string>
#include "interpreter.h"

int main(void) {
	//write
	Interpreter my_interpreter = Interpreter("Basics.bin");
	my_interpreter.execute();

}