#include "file.h"

void file :: readfile(string f) {
	ifstream File;
	File.open(f, ios::in | ios::binary);
	File.seekg(0, File.end);
	length = File.tellg();
	File.seekg(0, File.beg);

	/*test*/
	buffer = (char*) malloc(sizeof(char) * length);
	File.read(buffer, length);
	int a = 1;
}
