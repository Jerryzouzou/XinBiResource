#include "allh.h"
using namespace std;

/*
* 生成数组的MaxTree, 二叉树中，每个节点都比子节点大，生成方法原则可如下：
* 1.每一个数的父节点是它的左边第一个比它大的数和右边第一个比它大的数中比较小的那个
* 2.如果一个数左边和右边都没有比它大的数，说明它是头结点 
* 利用栈，一个存放左边比它大的数，一个存放右边比它大的数；左栈为--从左到右遍历时，栈顶比它小
* 时不断弹出知道栈顶比新数大或没有数，栈中保持递减序列,然后用map保存每个节点对应左边第一个大的数和
* 右边大的数 
*/

struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int n=0): val(n), left(NULL), right(NULL){};
	bool operator < (const Node &a)const
    {
        return val < a.val;
    }
};

void popStackSetMap(stack<Node*>& mStack, map<Node*, Node*>& mMap);

static Node* getMaxTree(vector<int> arr){
	vector<Node*> nArr;//(arr.size());
	for(int i=0; i<arr.size(); i++){
		//nArr[i] = new Node(arr[i]);
		nArr.push_back(new Node(arr[i]));
	}
	stack<Node*> mStack;
	map<Node*, Node*> lBigMap;		//存放左边大值 
	map<Node*, Node*> rBigMap;		//存放右边大值
	for(int i=0; i<arr.size(); i++){
		Node* curNode = nArr[i];
		//栈是递减保存的，栈顶小于当前节点时，进去栈中将栈顶对应的左边第一个大的节点关系 
		//然后将当前节点放入栈顶中，使得栈保持递减序列又一个一个将节点对应左边第一个大的节点找好放入map中 
		while((!mStack.empty()) && mStack.top()->val < curNode->val){
			popStackSetMap(mStack, lBigMap);
		}
		mStack.push(curNode);
	}
	//没有新的节点了，将栈中还未处理的节点各自找到对应关系左边第一个大的节点 
	while(!mStack.empty()){
		popStackSetMap(mStack, lBigMap);
	} 
	
	for(int i=arr.size()-1; i>=0; i--){
		Node* curNode = nArr[i];
		while((!mStack.empty()) && mStack.top()->val < curNode->val){
			popStackSetMap(mStack, rBigMap);
		}
		mStack.push(curNode);
	}
	while(!mStack.empty()){
		popStackSetMap(mStack, rBigMap);
	} 
	Node* head = NULL;
	for(int i=0; i<arr.size(); i++){
		Node* curNode = nArr[i];
		Node* left = lBigMap[curNode];
		Node* right = rBigMap[curNode];
		if(left==NULL && right==NULL){
			head = curNode;
		}else if(left == NULL){
			if(right->left == NULL){
				right->left = curNode;
			}else{
				right->right = curNode;
			}
		}else if(right == NULL){
			if(left->left == NULL){
				left->left = curNode;
			}else{
				left->right = curNode;
			}
		}else{
			Node* parent = left->val<right->val ? left : right;
			if(parent->left == NULL){
				parent->left = curNode;
			}else{
				parent->right = curNode;
			}
		}
	}
	return head;
}

void popStackSetMap(stack<Node*>& mStack, map<Node*, Node*>& mMap){
	Node* popNode = mStack.top();
	mStack.pop();
	if(mStack.empty()){
		mMap.insert(pair<Node*, Node*>(popNode, NULL));
	}else{
		mMap.insert(pair<Node*, Node*>(popNode, mStack.top()));
	}
} 

/*
*前序序遍历
*/
void preOrderRecur(struct Node* head){
	if(head == NULL){
		return;
	}
	cout<<head->val<<" ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}

void maxTree_main(){
	vector<int> arr;
	arr.push_back(3);arr.push_back(4);arr.push_back(5);arr.push_back(1);arr.push_back(2);
	
	cout<<"数组生成maxTree---原数组==3 4 5 1 2"<<endl;
	Node* head = getMaxTree(arr);
	preOrderRecur(head);
}


