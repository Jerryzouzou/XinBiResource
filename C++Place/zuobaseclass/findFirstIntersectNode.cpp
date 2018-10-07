#include "allh.h"
using namespace std;

/*
* 找到链表如果是有环的找到环点 
*/

struct Node{
	int value;
	Node* next;
	Node(int a=0):value(a), next(NULL){};
};
