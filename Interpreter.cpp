#include "Interpreter.h"
#inlcude "StackObject.h"
void Interpreter::instructions(int val){
	//
	switch(val) {
    case 132: 
        //cmpe:
		/*meaning: compare the top two elements on the runtime stack and make the new top of the runtime
stack 1 if the elements are equal, and 0 otherwise.
rstack[sp-1] = rstack[sp-1] == rstack[sp]
sp--;*/
		runtimeS.stack[runtimeS.sp - 1] = (runtimeS.stack[runtimeS.sp - 1] == runtimeS.stack[runtimeS.sp]);
		runtimeS.sp--;
		runtimeS.stack.pop_back();
		
        break; 
    case 136: 
        //cmplt:  compare the top two elements on the runtime stack and make the new top of the runtime
		//stack 1 if the next to the top element is less than the top element, and 0 otherwise.
		//		rstack[sp-1] = rstack[sp-1] < rstack[sp]
			//sp--;
		runtimeS.stack[runtimeS.sp - 1] = (runtimeS.stack[runtimeS.sp - 1] < runtimeS.stack[runtimeS.sp]);
		runtimeS.sp--;
		runtimeS.stack.pop_back();
		
        break; 
		
	case 140: 
        //statements
		/* cmpgt
		meaning: compare the top two elements on the runtime stack and make the new top of the runtime
stack 1 if the next to the top element is greater than the top element, and 0 otherwise.
rstack[sp-1] = rstack[sp-1] > rstack[sp]
sp--;*/
		runtimeS.stack[runtimeS.sp - 1] = (runtimeS.stack[runtimeS.sp - 1] > runtimeS.stack[runtimeS.sp]);
		runtimeS.sp--;		
		runtimeS.stack.pop_back();
		
        break; 
		
	/*control flow*/
	case 36: 
        //meaning: jump to the location at the top of the runtime stack.jmp
		mem.pc = runtimeS.stack[runtimeS.sp].position;
		runtimeS.sp = runtimeS.sp-1;
        break; 
		
	case 40: 
        //meaning: jump to the location at the top of the runtime stack is the next to the top of the runtime stack//jmpc
		//contains the integer value 1 (true)
	if (runtimeS.stack[runtimeS.sp-1].value){ mem.pc = runtimeS.stack[sp].position;runtimeS.sp = runtimeS.sp-2;}

        break; 
		
	case 44: 
        //statements
		/*call
		meaning: save the frame stack pointer for the current frame in the fpstack (frame pointer stack). Jump
to the location of the function being called, whose address is on the top of the runtime stack.*/
		frame.fstack[++fpsp] = runtimeS.sp - rstack[sp].s_position; // subtract off argument stack
 // entries
		runtimeS.sp--;
		pc = runtimeS.stack[sp—].position //set the PC to the address of the label to be
 // jumped to

		
        break; 
	case 48: 
        //ret:
		/*meaning: restore the runtime stack pointer of the function being returned to. Set the PC to the value at
the top of the runtime stack, which is the address of the instruction following the call or callr statement.
sp = fpstack[fpsp--]
pc = rstack[sp]*/
        break; 
	
	/*Stack manipulation byte codes*/
	case 68: 
		StackObject new_obj;
		new_obj(mem.memory[mem.pc+1],"char",mem.pc+1,runtimeS.sp+1);
        //pushc: meaning: push a character literal onto the top of the runtime stack.
		runtimeS.stack[++sp] = new_obj;
		mem.pc += 2;
        break; 
	case 69: 
        //pushs: 69 or 01000101
		/*
meaning: push a short literal onto the top of the runtime stack.
convert to a short s = mem[pc+1, mem[pc+2] (see
https://stackoverflow.com/questions/13469681/how-to-convert-4-bytes-array-to-float-in-java)
rstack[++sp] = s
pc += 3;
*/
		StackObject new_obj;
		short val = (((short)mem.memory[mem.pc+1]) << 8) | (0x00ff & mem.memory[mem.pc+2]);
		new_obj(val,"short",mem.pc+2,runtimeS.sp+1);
        //pushc: meaning: push a character literal onto the top of the runtime stack.
		runtimeS.stack[++sp] = new_obj;
		mem.pc += 3;
        break; 
	case 70: 
        //pushi:
		/*meaning: push an integer literal onto the top of the runtime stack.
convert to an int i = mem[pc+1, mem[pc+2], mem[pc+3], mem[pc+4] (see
https://stackoverflow.com/questions/13469681/how-to-convert-4-bytes-array-to-float-in-java)
rstack[++sp] = f
pc += 5;*/
		int output;

		*((uchar*)(&output) + 3) = mem.memory[pc+1];
		*((uchar*)(&output) + 2) = mem.memory[pc+2];
		*((uchar*)(&output) + 1) = mem.memory[pc+3];
		*((uchar*)(&output) + 0) = mem.memory[pc+4];
		
		StackObject new_obj;
		new_obj(val,"int",mem.pc+4,runtimeS.sp+1);
		runtimeS.stack[++sp] = new_obj;
        break; 
	case 71: 
        //pushf: meaning: push a float literal onto the top of the runtime stack.
		/*
convert to a float f = mem[pc+1, mem[pc+2], mem[pc+3], mem[pc+4] (see
https://stackoverflow.com/questions/13469681/how-to-convert-4-bytes-array-to-float-in-java)
rstack[++sp] = f
pc += 5;*/
		float output;

		*((uchar*)(&output) + 3) = mem.memory[pc+1];
		*((uchar*)(&output) + 2) = mem.memory[pc+2];
		*((uchar*)(&output) + 1) = mem.memory[pc+3];
		*((uchar*)(&output) + 0) = mem.memory[pc+4];
		
		StackObject new_obj;
		new_obj(val,"float",mem.pc+4,runtimeS.sp+1);
		runtimeS.stack[++sp] = new_obj;

        break; 
	case 72: 
        //pushvc
		/*
		meaning: push a character variable’s value (where the variable location is at the top of the runtime
stack) onto the runtime stack.*/
		runtimeS.stack[runtimeS.sp++] = runtimeS.stack[runtimeS.sp];

        break; 
	case 73: 
        //pushvs
		/*
		meaning: push a short variable’s value (where the variable location is at the top of the runtime stack)
onto the runtime stack.
rstack[sp] = rstack[rstack[sp]]	
		*/
		runtimeS.stack[runtimeS.sp++] = runtimeS.stack[runtimeS.sp];
        break; 
	case 74: 
        //pushvi
		/*
		meaning: push an integer variable’s value (where the variable location is at the top of the runtime
stack) onto the runtime stack.
rstack[sp] = rstack[rstack[sp]]	
		*/
		runtimeS.stack[runtimeS.sp++] = runtimeS.stack[runtimeS.sp];
        break; 
	case 75: 
        //pushvf
		/*
		meaning: push an floating point variable’s value (where the variable location is at the top of the runtime
stack) onto the runtime stack.
rstack[sp] = rstack[rstack[sp]]
		*/
		runtimeS.stack[runtimeS.sp++] = runtimeS.stack[runtimeS.sp];
        break; 
	case 76: 
        //popm
		/*
		meaning: pop multiple entries off of the runtime stack, discarding their values. The number of entries
to pop is at the top of the runtime stack.*/
		int num = rstack[sp].value;
		for(int x =0; x < num; x ++){
			runtimeS.stack.pop_back();
		}
		
        break; 
	case 77: 
        //popa
		/*
		meaning: pop all of the top entries to frame stack point from the runtime stack but keep val top entries.
The number of entries to keep is at the top of the runtime stack.
rstack[fpstack[fpsp] + 1] = rstack[sp – rstack[sp]]
rstack[fpstack[fpsp] + 2] = rstack[sp – rstack[sp]+1]
. . .
rstack[fpstack[fpsp] + rstack[sp]] = rstack[sp-1]
sp = fpstack[fpsp]+rstack[sp]
		*/
		
		
        break; 
	case 80: 
        //popv
		/*
		meaning: pop a value off of the runtime stack into a variable. The variable’s location is given by the
top of the stack, the value popped is the next element into the stack.
rstack[rstack[sp]] = rstack[sp-1]
sp -= 2
		*/
		runtimeS.stack[sp] = runtimeS.stack[sp-1];
		runtimeS.sp -= 2;
		runtimeS.stack.pop_back();
        break; 
	case 84: 
        //peekc
		/*
		meaning: take the character value at the offset (given by the value of the top of the stack element) from
the start of the current runtime stack frame and put it into the variable whose address is given by the
next to the top element of the runtime stack.
rstack[fpstack[fpsp] + rstack[sp-1]+1] = rstack[fpstack[fpsp]
+rstack[sp]+1]
		
		*/
        break; 
	case 85: 
        //peeks
		/*
		meaning: take the short value at the offset (given by the value of the top of the stack element) from the
start of the current runtime stack frame and put it into the variable whose address is given by the next to
the top element of the runtime stack.
rstack[fpstack[fpsp] + rstack[sp-1]+1] = rstack[fpstack[fpsp]
+rstack[sp]+1]
		*/
        break; 
	case 86: 
        //peeki
		/*
		meaning: take the integer value at the offset (given by the value of the top of the stack element) from
the start of the current runtime stack frame and put it into the variable whose address is given by the
next to the top element of the runtime stack.
rstack[fpstack[fpsp] + rstack[sp-1]+1] = rstack[fpstack[fpsp]
+rstack[sp]+1]

		
		*/
        break; 
	case 87: 
        //peekf
		/*
		meaning: take the float value at the offset (given by the value of the top of the stack element) from the
start of the current runtime stack frame and put it into the variable whose address is given by the next to
the top element of the runtime stack.
rstack[fpstack[fpsp] + rstack[sp-1]+1] = rstack[fpstack[fpsp]
+rstack[sp]+1]
		*/
        break; 
	case 88: 
		//pokec
		/*
		meaning: change the character value at the offset (given by the value of the top of the stack element)
from the start of the current runtime stack frame and to the variable whose address is given by the next
to the top element of the runtime stack.
rstack[fpstack[fpsp] +rstack[sp]+1] = rstack[fpstack[fpsp] +
rstack[sp-1]+1]
		*/

		
        break; 
	
	case 89: 
	//pokes
	/*
	meaning: change the short value at the offset (given by the value of the top of the stack element) from
the start of the current runtime stack frame and to the variable whose address is given by the next to the
top element of the runtime stack.
rstack[fpstack[fpsp] +rstack[sp]+1] = rstack[fpstack[fpsp] +
rstack[sp-1]+1]

	*/

		
        break; 
	case 90:
	//pokei
	/*
	meaning: change the integer value at the offset (given by the value of the top of the stack element)
from the start of the current runtime stack frame and to the variable whose address is given by the next
to the top element of the runtime stack.
rstack[fpstack[fpsp] +rstack[sp]+1] = rstack[fpstack[fpsp] +
rstack[sp-1]+1]
	
	*/

		
        break; 
		
	case 91: 
	//pokef
	/*
	meaning: change the float value at the offset (given by the value of the top of the stack element) from
the start of the current runtime stack frame and to the variable whose address is given by the next to the
top element of the runtime stack.
rstack[fpstack[fpsp] +rstack[sp]+1] = rstack[fpstack[fpsp] +
rstack[sp-1]+1]
	*/
		
        break; 
	case 94: 
	//swp
	/*
	meaning: swap the top of the stack with the next to the top of the stack element.
tmp = rstack[sp-1]
rstack[sp-1] = rstack[sp]
rstack[sp] = tmp
	*/
	StackObject tmp = runtimeS.stack[sp-1];
	runtimeS.stack[sp-1] = runtimeS.stack[sp];
	runtimeS.stack[sp] = tmp;
	
	/*arithmetic byte code*/
        break; 
	case 100:
	//add
	/*
	rstack[sp-1] = rstack[sp-1] + rstack[sp]
sp--;

	*/	
		runtimeS.stack[runtimeS.sp-1] = runtimeS.stack[runtimeS.sp-1] + runtimeS.stack[runtimeS.sp];
		runtimeS.sp--;
		runtimeS.stack.pop_back();
		
        break; 
	case 104: 
	//sub
	//rstack[sp-1] = rstack[sp-1] - rstack[sp];sp--;
		runtimeS.stack[runtimeS.sp-1] = runtimeS.stack[runtimeS.sp-1] - runtimeS.stack[runtimeS.sp];
		runtimeS.sp--;
		runtimeS.stack.pop_back();	
        break; 
	case 108: 
	//mul
	//rstack[sp-1] = rstack[sp-1] * rstack[sp];sp--;
		runtimeS.stack[runtimeS.sp-1] = runtimeS.stack[runtimeS.sp-1] * runtimeS.stack[runtimeS.sp];
		runtimeS.sp--;
		runtimeS.stack.pop_back();
        break; 
	case 112: 
	//div
	//rstack[sp-1] = rstack[sp-1] / rstack[sp];sp--;
		runtimeS.stack[runtimeS.sp-1] = runtimeS.stack[runtimeS.sp-1] / runtimeS.stack[runtimeS.sp];
		runtimeS.sp--;
		runtimeS.stack.pop_back();
        break; 
		
	case 148: 
	//printc
	//System.out.println(rstack[sp--]);
		cout<<runtimeS.stack[sp--].value<<endl;
		runtimeS.stack.pop_back();

        break; 
	case 149: 
//System.out.println(rstack[sp--]);prints
		cout<<runtimeS.stack[sp--].value<<endl;
		runtimeS.stack.pop_back();
        break; 
	case 150: 
//System.out.println(rstack[sp--]);printi
		cout<<runtimeS.stack[sp--].value<<endl;
		runtimeS.stack.pop_back();
        break; 
	case 151: 
//System.out.println(rstack[sp--]);printf
		cout<<runtimeS.stack[sp--].value<<endl;
		runtimeS.stack.pop_back();
        break; 
	case 0: 
	//halt
	//Terminate the program. Print pc, sp, rstack, fpsp, fpstack. Print empty if a stack is empty. 
		int i = 0;
		int j = 0;
		cout<<"Compile values"<<"\n";
		cout<<"PC: "<<mem.pc<<"\n";
		cout<<"sp: "<<runtimeS.sp<<"\n";
		cout<<"rstack: ";
		if!(runtimeS.stack){
			cout<<"empty"<<"\n";
		}
		else{	
			while(i<runtimeS.stack.size()){
				count<<runtimeS.stack[i].value<<" ";
				i++;
			}
			count<<"\n";
		}
		cout<<"fpsp: "<<frame.fpsp<<"\n";
		
		cout<<"fpstack: ";
		if!(frame.fstack){
			cout<<"empty"<<"\n";
		}
		else{	
			while(j<frame.fstack.size()){
				count<<frame.fstack[j].value<<" ";
				j++;
			}
			count<<"\n";
		}
		
        break; 
	
    default: //optional
    //statements
}



}

void Interpreter::execute(void){
	/*Read the memory address one by one*/
	while(mem.pc < mem.length){
		//call the instruction function
		instructions(mem.memory[mem.pc]);
		mem.pc ++;
	}
}






Interpreter::Interpreter() {}
Interpreter::~Interpreter() {}
