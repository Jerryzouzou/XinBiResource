#include "allh.h"
using namespace std;

/*
* 二叉树的最大间隔
* 递归方式---ReturnData为当前节点为头的最大间隔和深度；分别得到left和right的
* ReturnData，当前节点的深度为较大深度+1，最大间隔为left的最大间隔、right的 
* 最大间隔、(left_deep+right_deep+1)的最大值即为当前节点为头结点的最大间隔 
*/

struct Node{
	int value;
	Node* left;
	Node* right;
	Node(int a=0):value(a), left(NULL), right(NULL){};
};

struct ReturnData{
	int maxDistance;
	int height;
	ReturnData(int a=0, int b=0):maxDistance(a),height(b){};
};

/*
* 递归可以就是认为得到了想到得到的值 
*/
static ReturnData* process(Node* x){
	if(x == NULL){
		return new ReturnData(0, 0);
	}
	
	ReturnData* left = process(x->left);	//递归获取左孩子的ReturnData 
	ReturnData* right = process(x->right); 
	int height = max(left->height, right->height) + 1;
	int p1 = left->maxDistance;
	int p2 = right->maxDistance;
	int p3 = left->height + right->height + 1;
	int maxDistance = max(p1, max(p2, p3));
	
	return new ReturnData(maxDistance, height);
}

int getMaxDistance(Node* head){
	return process(head)->maxDistance;
}

void tree_maxdistance_main(){
	int res;
	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->left = new Node(4);
	head->left->left->left = new Node(5);
	head->right->left = new Node(6);
	head->right->right = new Node(7);
	
	res = getMaxDistance(head);
	cout<<"tree_maxdistance is == "<<res<<endl;
}


