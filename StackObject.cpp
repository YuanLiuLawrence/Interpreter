#include "StackObject.h"

/*Comparator*/
StackObject StackObject::operator==(const StackObject& x){
	StackObject new_obj;
	if(x.type == type){
		if(x.value == value){
			new_obj = StackObject("bool",1);
		}
		else{
			new_obj = StackObject("bool",0);
		}
	}
	else{
		new_obj = StackObject("bool",0);
	}
	return new_obj;
}


StackObject StackObject::operator>(const StackObject& x){
	StackObject new_obj;
	if(x.type == type){
		if(x.value > value){
			new_obj = StackObject("bool",1);
		}
		else{
			new_obj = StackObject("bool",0);
		}
	}
	else{
		new_obj = StackObject("bool",0);
	}
	return new_obj;
}


StackObject StackObject::operator<(const StackObject& x){
	StackObject new_obj;
	if(x.type == type){
		if(x.value < value){
			new_obj = StackObject("bool",1);
		}
		else{
			new_obj = StackObject("bool",0);
		}
	}
	else{
		new_obj = StackObject("bool",0);
	}
	return new_obj;
}


/*operator*/
StackObject StackObject::operator+(const StackObject& x){
	int sum;
	StackObject new_obj;
	if(x.type == type){
		sum = x.value + value;
		new_obj = StackObject(type, sum);
	}
	return new_obj;
}


StackObject StackObject::operator-(const StackObject& x){
	int sum;
	StackObject new_obj;
	if(x.type == type){
		sum = x.value - value;
		new_obj = StackObject(type, sum);
	}
	return new_obj;
}
StackObject StackObject::operator*(const StackObject& x){
	int sum;
	StackObject new_obj;
	if(x.type == type){
		sum = x.value * value;
		new_obj = StackObject(type, sum);
	}
	return new_obj;
}
StackObject StackObject::operator/(const StackObject& x){
	int sum;
	StackObject new_obj;
	if(x.type == type){
		sum = x.value / value;
		new_obj = StackObject(type, sum);
	}
	return new_obj;
}




StackObject::StackObject(char *t, int v) {
		if(t=="short"){
			short value = short(v);			
		}
		if(t=="float"){
			float value = float(v);			
		}
		if(t=="char"){
			char value = char(v);			
		}
		if(t=="int"){
			int value = int(v);			
		}
		if(t=="bool"){
			bool value = bool(v);			
		}	
		type = t;
	}
	
StackObject::StackObject(char *t, int v, int p, int sp) {
		if(t=="short"){
			short value = short(v);			
		}
		if(t=="float"){
			float value = float(v);			
		}
		if(t=="char"){
			char value = char(v);			
		}
		if(t=="int"){
			int value = int(v);			
		}
		if(t=="bool"){
			bool value = bool(v);			
		}	
		type = t;
		position = p;
		s_postion = sp;
	}

StackObject::~StackObject() {}
StackObject::StackObject() {}



