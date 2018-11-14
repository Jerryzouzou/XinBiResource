#include "allh.h"
using namespace std;

/*
* 二叉树是否是搜索二叉树--所有结点：左<中<右 
* 递归方式：每个递归返回当前节点的最小值最大值和是否是搜索二叉树--ReturnData 
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
