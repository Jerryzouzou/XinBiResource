#include "allh.h"
using namespace std;

/*
* �������Ƿ�������������--���н�㣺��<��<�� 
* �ݹ鷽ʽ��ÿ���ݹ鷵�ص�ǰ�ڵ����Сֵ���ֵ���Ƿ�������������--ReturnData 
*/

struct Node{
	int value;
	Node* left;
	Node* right;
	Node(int a=0):value(a), left(NULL), right(NULL){};
};


struct ReturnData{
	bool isBST;
	int min;
	int max;
}; 
