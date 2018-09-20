#include "allh.h"
using namespace std;

/*
* 二叉树的前序中序后续遍历，使用递归方式和非递归方式 
*/

class Node{
	public:
		int value;
		struct Node *left,*right;
		Node(int v=0){value = v; left = NULL; right = NULL;}
};

/*
*前序遍历，递归方式，先打印在递归左右边 
*/
void preOrderRecur(struct Node* head){
	if(head == NULL){
		return;
	}
	cout<<head->value<<" ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}

/*
*中序遍历，递归方式，递归左边--打印--递归右边 
*/
void inOrderRecur(struct Node* head){
	if(head == NULL){
		return;
	}
	inOrderRecur(head->left);
	cout<<head->value<<" ";
	inOrderRecur(head->right);
}

/*
*后序遍历，递归方式，递归左右边再打印 
*/
void posOrderRecur(struct Node* head){
	if(head == NULL){
		return;
	}
	posOrderRecur(head->left);
	posOrderRecur(head->right);
	cout<<head->value<<" ";
}

/*
* 前序遍历，非递归方式； 
* 先把头压入栈，然后在栈不为空的条件下，弹出栈顶并打印，然后右孩子不为空压入右孩子，左孩子不为空压入左孩子
* 这样就保证先打印左孩子作为头结点，左边打印完后再打印右边 
*/
void preOrderUnRecur(struct Node* head){
	if(head == NULL){
		return;
	}
	stack<struct Node*> t_stack;
	t_stack.push(head);
	while(!t_stack.empty()){
		head = t_stack.top();		//返回栈顶元素，不弹出 
		t_stack.pop();		//删除栈顶元素，没有返回值 
		cout<<head->value<<" ";
		if(head->right != NULL){
			t_stack.push(head->right);
		}
		if(head->left != NULL){
			t_stack.push(head->left);
		}
	}
}

/*
* 中序遍历，非递归方式； 
* 从头结点开始把左孩子全部压入栈中直到 NULL，然后弹出打印跑到上一级结点，如果没有右孩子，则继续弹出打印跑到上一级 
* 如果有右孩子，则把右孩子和他的 左边全部压入栈中直到NULL，
* 这样就保证先打印最左边结点在到父节点，然后打印右孩子的最左边结点。 
*/
void inOrderUnRecur(struct Node* head){
	if(head == NULL){
		return;
	}
	stack<struct Node*> t_stack;
	while(!t_stack.empty() || head!=NULL){
		if(head != NULL){
			t_stack.push(head);
			head = head->left;
		}else{
			head = t_stack.top();		//返回栈顶元素，不弹出 
			t_stack.pop();		//删除栈顶元素，没有返回值 
			cout<<head->value<<" ";
			head = head->right;
		}
	}
}

/**
* 后序遍历：非递归方式 
* 利用一个辅助栈，类似前序遍历的方式，只不过将前序的打印改为压入辅助栈，这样先打印就变成后打印，
* 而且是先压左边再压右边，这样弹出给辅助栈的时候就辅助栈就先压右边再压左边 
*/
void posOrderUnRecur(struct Node* head){
	if(head == NULL){
		return;
	}
	stack<struct Node*> t_stack, s_stack;
	t_stack.push(head);
	while(!t_stack.empty()){
		head = t_stack.top();		//返回栈顶元素，不弹出 
		t_stack.pop();		//删除栈顶元素，没有返回值 
		s_stack.push(head);
		if(head->left != NULL){
			t_stack.push(head->left);
		}
		if(head->right != NULL){
			t_stack.push(head->right);
		}
	}
	while(!s_stack.empty()){
		struct Node* tmp = s_stack.top();
		s_stack.pop();
		cout<<tmp->value<<" ";
	}	
}

/*
* 后续遍历：非递归遍历，不用辅助栈的方式 
*
*/
void posOrderUnRecur2(struct Node* head){
	if(head == NULL){
		return;
	}
	stack<struct Node*> t_stack;
	t_stack.push(head);
	struct Node* c = NULL;
	while(!t_stack.empty()){
		c = t_stack.top();
		if(c->left!=NULL && head!= c->left && c->right){
			t_stack.push(c->left);
		}else if(c->right!=NULL && head!=c->right){
			t_stack.push(c->right);
		}else{
			struct Node* tmp = t_stack.top();
			t_stack.pop();
			cout<<tmp->value<<" ";
			head = c;
		}
	}	
}

void pre_in_pos_2tree_traversal_main(){
	struct Node *head = new Node(5);
	head->left = new Node(3);
	head->right = new Node(8);
	head->left->left = new Node(2);
	head->left->right = new Node(4);
	head->left->left->left = new Node(1);
	head->right->left = new Node(7);
	head->right->left->left = new Node(6);
	head->right->right = new Node(10);
	head->right->right->left = new Node(9);
	head->right->right->right = new Node(11);
	
	cout<<"********使用递归方式************"<<endl;
	cout<<"       ---前序遍历---         "<<endl;
	preOrderRecur(head);
	cout<<endl;
	cout<<"       ---中序遍历---         "<<endl;
	inOrderRecur(head);
	cout<<endl;
	cout<<"       ---后序遍历---         "<<endl;
	posOrderRecur(head);
	cout<<endl;
	
	cout<<"********使用非递归方式************"<<endl;
	cout<<"       ---前序遍历---         "<<endl;
	preOrderUnRecur(head);
	cout<<endl;
	cout<<"       ---中序遍历---         "<<endl;
	inOrderUnRecur(head);
	cout<<endl;
	cout<<"       ---后序遍历---         "<<endl;
	posOrderUnRecur(head);
	cout<<endl;
	cout<<"       ---后序遍历2---         "<<endl;
//	posOrderUnRecur2(head);
	cout<<endl;
}
