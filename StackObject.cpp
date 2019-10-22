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


StackObject::StackObject(short t, int p, int sp) {
		short(value);
		strcpy(type,"short");
		value = t;
		position = p;
		s_position = sp;
	}
StackObject::StackObject(char t, int p, int sp) {
		char(value);
		strcpy(type,"char");
		value = t;
		position = p;
		s_position = sp;
	}

StackObject::StackObject(int t, int p, int sp) {
		strcpy(type,"int");
		value = t;
		
		position = p;
		s_position = sp;
	}

	
StackObject::StackObject(float t, int p, int sp) {
		float(value);
		strcpy(type,"float");
		value = t;
		position = p;
		s_position = sp;
	}

StackObject::~StackObject() {}
StackObject::StackObject() {}



