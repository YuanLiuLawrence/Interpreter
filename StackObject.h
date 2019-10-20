#pragma once
#ifndef STACKOBJECT_H
#define STACKOBJECT_H

using namespace std;
/*running stack contains a vector of the address of the object*/
class StackObject {
public:	
	int value;
	char *type;
	int position;
	StackObject(char *t, int v);
	StackObject(char *t, int v, int p);
	StackObject();
	virtual ~StackObject();
	//compare
	StackObject operator==(const StackObject&);
	StackObject operator<(const StackObject&);
	StackObject operator>(const StackObject&);
	
	//arithmetic
	StackObject operator+(const StackObject&);
	StackObject operator-(const StackObject&);
};

#endif