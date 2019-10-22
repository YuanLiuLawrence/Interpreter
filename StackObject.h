#pragma once
#ifndef STACKOBJECT_H
#define STACKOBJECT_H
#include<string>
using namespace std;
/*running stack contains a vector of the address of the object*/
class StackObject {
public:	
	int value;
	char *type;
	int position;
	//stack position
	int s_position;
	StackObject(char *t, int v);
	StackObject(short t, int p, int sp);
	StackObject(char t, int p, int sp);
	StackObject(int t, int p, int sp);
	StackObject(float t, int p, int sp);
	
	StackObject();
	virtual ~StackObject();
	//compare
	StackObject operator==(const StackObject&);
	StackObject operator<(const StackObject&);
	StackObject operator>(const StackObject&);
	
	//arithmetic
	StackObject operator+(const StackObject&);
	StackObject operator-(const StackObject&);
	StackObject operator*(const StackObject&);
	StackObject operator/(const StackObject&);
};

#endif