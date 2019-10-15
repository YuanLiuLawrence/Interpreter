#include "file.h"

void file :: readfile(string f) {
	ifstream file (f, ifstream::binary);
	file.seekg(0, file.end);
	file_len = file.tellg();
	file.seekg(0, file.beg);

	/*test*/
	char* buffer = new char[8];
	file.read(buffer, 8);
	
}