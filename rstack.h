#include <vector>
#include "StackObject.h"
using namespace std;
class rstack {
public:
	int sp = -1;
	vector<StackObject> stack;
	rstack() {}
	virtual ~rstack() {}
	void putOnStack(StackObject obj);
};