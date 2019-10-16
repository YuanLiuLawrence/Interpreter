#pragma once
#include "file.h"
class Memory : public file{
public:
	int pc = 0;
	char* memory;
	Memory() { strcpy(memory, buffer); }
	virtual ~Memory() { delete memory; }

};
