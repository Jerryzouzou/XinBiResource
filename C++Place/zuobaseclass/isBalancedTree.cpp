#include "allh.h"
using namespace std;

/*
* �������Ƿ���ƽ�������--�������������߶�������1 
* �ݹ鷽ʽ��ÿ���ݹ鷵�ص�ǰ�ڵ�ĸ߶Ⱥ��Ƿ���ƽ�������--ReturnData 
*/

struct Node{
	int value;
	Node* left;
	Node* right;
	Node(int a=0):value(a), left(NULL), right(NULL){};
};


struct ReturnData{
	bool isBlance;
	int height;
}; 
