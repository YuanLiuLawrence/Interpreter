#include "Memory.h"

Memory::Memory() {}

Memory::Memory(string f) {
	readfile(f);
	memory = (unsigned char *)buffer;
}

Memory::~Memory() {}