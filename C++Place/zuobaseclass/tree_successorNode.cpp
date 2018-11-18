#include "allh.h"
using namespace std;

/*
* 二叉树中序遍历的顺序某个节点前面的叫做前驱节点，后一个的叫后继节点
* 问题：带parent指针的二叉树中找到任意一个节点的后继节点；
* 方法：如果该节点有右孩子，则该节点的后继节点为右孩子的最左节点；如果没有右孩子
* 以该节点为某个节点的左孩子的最右节点则这个节点为后继节点； 
*/

struct Node{
	int value;
	Node* left;
	Node* right;
	Node* parent;
	Node(int a=0):value(a), left(NULL), right(NULL), parent(NULL){};
};

static Node* getLeftMost(Node* node);

static Node* getSuccessorNode(Node* node){
	if(node == NULL){
		return node;
	}
	//1.该节点有右孩子，则返回右孩子的最左节点 
	if(node->right != NULL){
		return getLeftMost(node->right);
	}
	//2.该节点无右孩子，
	Node* cur = node;
	Node* parent = cur->parent;
	/*
	* 如果为右孩子则不断往上走知道找到作为左孩子
	* 整棵树的最右节点会有parent为NULL的时候 
	*/
	while(parent!=NULL && parent->left!=cur){
		cur = parent;
		parent = cur->parent;
	}
	return parent;
}

static Node* getLeftMost(Node* node){
	if(node == NULL){
		return node;
	}
	while(node->left != NULL){
		node = node->left;
	}
	return node;
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

void tree_successorNode_main(){
	Node* head = new Node(6);
	head->parent = NULL;
	head->left = new Node(3);
	head->left->parent = head;
	head->left->left = new Node(1);
	head->left->left->parent = head->left;
	head->left->left->right = new Node(2);
	head->left->left->right->parent = head->left->left;
	head->left->right = new Node(4);
	head->left->right->parent = head->left;
	head->left->right->right = new Node(5);
	head->left->right->right->parent = head->left->right;
	head->right = new Node(9);
	head->right->parent = head;
	head->right->left = new Node(8);
	head->right->left->parent = head->right;
	head->right->left->left = new Node(7);
	head->right->left->left->parent = head->right->left;
	head->right->right = new Node(10);
	head->right->right->parent = head->right;
	
	cout<<"后继节点----二叉树中序遍历为---";
	inOrderRecur(head);
	cout<<endl;
	
	Node* test = head->left->left;
	cout<<test->value<<" next: "<<getSuccessorNode(test)->value<<endl;
	test = head->left->left->right;
	cout<<test->value<<" next: "<<getSuccessorNode(test)->value<<endl;
	test = head->left;
	cout<<test->value<<" next: "<<getSuccessorNode(test)->value<<endl;
	test = head->left->right;
	cout<<test->value<<" next: "<<getSuccessorNode(test)->value<<endl;
	test = head->left->right->right;
	cout<<test->value<<" next: "<<getSuccessorNode(test)->value<<endl;
	test = head;
	cout<<test->value<<" next: "<<getSuccessorNode(test)->value<<endl;
	test = head->right->left->left;
	cout<<test->value<<" next: "<<getSuccessorNode(test)->value<<endl;
	test = head->right->left;
	cout<<test->value<<" next: "<<getSuccessorNode(test)->value<<endl;
	test = head->right;
	cout<<test->value<<" next: "<<getSuccessorNode(test)->value<<endl;
	test = head->right->right; // 10's next is null
	cout<<test->value<<" next: "<<getSuccessorNode(test)<<endl;
}
