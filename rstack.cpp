#include "rstack.h"


void rstack::putOnStack(StackObject obj){
	stack.push_back(obj);
	sp ++;
}