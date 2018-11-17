#include "allh.h"
using namespace std;

/*
* 二叉树是否是搜索二叉树--所有结点：左<中<右 
* 递归方式：每个递归返回当前节点的最小值最大值和是否是搜索二叉树--ReturnData
* 中序遍历方式：中序遍历是递增的说明是搜索二叉树 

* 二叉树是否是完全二叉树--完全二叉树从根结点到倒数第二层满足完美二叉树，最后一层可以不完全填充，其叶子结点都靠左对齐 
* 递归方式：每个递归返回当前节点 
*/

struct Node{
	int value;
	Node* left;
	Node* right;
	Node(int a=0):value(a), left(NULL), right(NULL){};
};

struct ReturnData{
	bool isBST;
	int imin;
	int imax;
	ReturnData(bool b=false, int a=0, int c=0):isBST(b), imin(a), imax(c){};
}; 

/*
* 递归可以就是认为得到了想到得到的值 
*/
static ReturnData* process(Node* x){
	if(x == NULL){
		return new ReturnData(true, 0x7FFFFFFF, 0xFFFFFFFF);
	}
	
	ReturnData* left = process(x->left);	//递归获取左孩子的ReturnData 
	ReturnData* right = process(x->right); 
	int imin = min(x->value, min(right->imin, left->imin));
	int imax = max(x->value, max(right->imax, left->imax));
	
	bool isBST = true;
	if(!left->isBST || !right->isBST || x->value<left->imax 
	|| x->value>right->imin){
		isBST = false;
	}
	
	return new ReturnData(isBST, imin, imax);
}

bool isBST(Node* head){
	return process(head)->isBST;
}

/*
*中序遍历，递归方式，递归左边--打印--递归右边 
*/
static void inOrderRecur(struct Node* head){
	if(head == NULL){
		return;
	}
	inOrderRecur(head->left);
	cout<<head->value<<" ";
	inOrderRecur(head->right);
}

struct ReturnData1{
	bool isCBT;
	ReturnData1(bool b=false):isCBT(b){};
};

static ReturnData1* process1(Node* x){
	if(x == NULL){
		return new ReturnData1(true);
	}
	
	ReturnData1* left = process1(x->left);	//递归获取左孩子的ReturnData 
	ReturnData1* right = process1(x->right); 
	
	bool isCBT = true;
	if(!left->isCBT || !right->isCBT || (x->left==NULL && x->right!=NULL)){		//有右孩子时无左孩子则不是完全二叉树 
		isCBT = false;
	}
	
	return new ReturnData1(isCBT);
}

bool isCBT(Node* head){
	return process1(head)->isCBT;
}

void tree_isBSTAndCBT_main(){
	bool res;
	Node* head = new Node(4);
	head->left = new Node(2);
	head->right = new Node(6);
	head->left->left = new Node(1);
	head->left->right = new Node(3);
	head->right->left = new Node(5);
	
	inOrderRecur(head);
	cout<<endl;
	res = isBST(head);
	cout<<"tree_isBST is == "<<res<<endl;
	
	res = isCBT(head);
	cout<<"tree_isCBT is == "<<res<<endl;
}
