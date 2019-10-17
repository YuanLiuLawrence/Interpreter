#pragma once
#ifndef BYTE_H
#define BYTE_H

using namespace std;
/*Byte class which contains 8 bits of the input file(The instructions)*/
class Byte {
public:	
	Byte() {}
	virtual ~Byte() {};
	int value;
	char type;
};
//use ~byte to free the list




#endif