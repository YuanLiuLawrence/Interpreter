#pragma once
#include "file.h"
#include "rstack.h"
#include "fpstack.h"
#include "Memory.h"

class Interpreter {
public:
	
	Interpreter() {}
	virtual ~Interpreter() {}
	
	/*main data structures*/
	//running stack
	rstack runtimeS;
	//stack of rame pointers
	fpstack frame;
	//program memory
	Memory mem;
	
	void instructions(int val);
	//execute the commands 
	void execute(void);

};