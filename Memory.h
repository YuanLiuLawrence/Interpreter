#pragma once
#include "file.h"
class Memory : public file {
public:
	int pc = 0;
	unsigned char* memory;
	Memory();
	Memory(string f);
	virtual ~Memory();

};
