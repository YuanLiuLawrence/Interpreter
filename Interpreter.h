#pragma once
#include "file.h"
#include "rstack.h"
#include "fpstack.h"
#include "Memory.h"

class Interpreter {
public:
	string f;
	Interpreter(string file);
	virtual ~Interpreter();
	
	/*main data structures*/
	//running stack
	rstack runtimeS;
	//stack of rame pointers
	fpstack frame;
	//program memory
	Memory mem;
	
	int instructions(int val);
	//execute the commands 
	void execute(void);

};