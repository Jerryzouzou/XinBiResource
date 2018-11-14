#include "allh.h"
using namespace std;

/*
* 二叉树是否是平衡二叉树--所有左右子树高度相差不大于1 
* 递归方式：每个递归返回当前节点的高度和是否是平衡二叉树--ReturnData 
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
