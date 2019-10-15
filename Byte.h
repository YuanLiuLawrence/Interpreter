#pragma once
#ifndef BYTE_H
#define BYTE_H
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;
/*Byte class which contains 8 bits of the input file(The instructions)*/
class Byte {
public:	
	Byte() {}
	virtual ~Byte() {};
	bitset<8> byte_info;


};
//use ~byte to free the list




#endif