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
	bool isBalance;
	int height;
	ReturnData(int a=0, bool b=false):height(a),isBalance(b){};
}; 

/*
* 递归可以就是认为得到了想到得到的值 
*/
static ReturnData* process(Node* x){
	if(x == NULL){
		return new ReturnData(0, true);
	}
	
	ReturnData* left = process(x->left);	//递归获取左孩子的ReturnData 
	ReturnData* right = process(x->right); 
	int height = max(left->height, right->height) + 1;
	int isBalance = true;
	if(!left->isBalance || !right->isBalance){	//有一个是不平衡的则整体都是不平衡的 
		isBalance = false;
	}
	if(abs(left->height - right->height) > 1){
		isBalance = false;
	}
	
	return new ReturnData(height, isBalance);
}

bool isBalance(Node* head){
	return process(head)->isBalance;
}

void tree_isBalanced_main(){
	bool res;
	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->left = new Node(4);
	head->left->right = new Node(5);
	head->right->left = new Node(6);
	head->right->right = new Node(7);
	
	res = isBalance(head);
	cout<<"tree_isBalanced is == "<<res<<endl;
}
