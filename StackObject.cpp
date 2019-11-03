#include "StackObject.h"

/*Comparator*/
StackObject StackObject::operator==(const StackObject& x){
	StackObject new_obj;

		if(x.value == value){
			new_obj = StackObject("int",1);
		}
		else{
			new_obj = StackObject("int",0);
		}
	return new_obj;
}


StackObject StackObject::operator>(const StackObject& x){
	StackObject new_obj;
	if (value > x.value) {
		new_obj = StackObject("int", 1);
	}
	else {
		new_obj = StackObject("int", 0);
	}
	return new_obj;
}


StackObject StackObject::operator<(const StackObject& x){
	StackObject new_obj;
	if (value < x.value) {
		new_obj = StackObject("int", 1);
	}
	else {
		new_obj = StackObject("int", 0);
	}
	return new_obj;
}


/*operator*/
StackObject StackObject::operator+(const StackObject& x){
	float sum;
	StackObject new_obj;
	sum = x.value + value;
	new_obj = StackObject(type, sum);
	return new_obj;
}


StackObject StackObject::operator-(const StackObject& x){
	float sum;
	StackObject new_obj;
		sum = value - x.value;
		new_obj = StackObject(type, sum);
	return new_obj;
}
StackObject StackObject::operator*(const StackObject& x){
	float sum;
	StackObject new_obj;
	sum = x.value * value;
	new_obj = StackObject(type, sum);
	return new_obj;
}
StackObject StackObject::operator/(const StackObject& x){
	float sum;
	StackObject new_obj;
	sum = value / x.value;
	new_obj = StackObject(type, sum);
	return new_obj;
}
StackObject::StackObject(string t, float v) {
	value = v;
	type = t;
}

StackObject::StackObject(short t, int p, int sp) {
		short(this->value);
		type = "short";
		value = t;
		position = p;
		s_position = sp;
	}
StackObject::StackObject(char t, int p, int sp) {
		char(this->value);
		type = "char";
		value = t;
		position = p;
		s_position = sp;
	}

StackObject::StackObject(int t, int p, int sp) {
	type = "int";
		value = t;
		
		position = p;
		s_position = sp;
	}

	
StackObject::StackObject(float t, int p, int sp) {
		float(this->value);
		type = "float";
		this->value = static_cast<float>(this->value);
		value = t;
		position = p;
		s_position = sp;
	}
StackObject::StackObject() {}

StackObject::~StackObject() {}




