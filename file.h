#pragma once
#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <list> 
#include <iterator> 
#include "Byte.h"
using namespace std;
class file {
public:
	int length;
	char *buffer;
	//list of the instructions in the file, it contains the byte classes(8 bits)
	list <Byte> file_info;
	//constructor
	file() {}
	virtual ~file() {}


	/*file api*/
	void readfile(string File);
	void output(string out_File);


};



#endif // FILE_H

