#include "allh.h"
using namespace std;

/*
* ���������������˳��ĳ���ڵ�ǰ��Ľ���ǰ���ڵ㣬��һ���Ľк�̽ڵ�
* ���⣺��parentָ��Ķ��������ҵ�����һ���ڵ�ĺ�̽ڵ㣻
* ����������ýڵ����Һ��ӣ���ýڵ�ĺ�̽ڵ�Ϊ�Һ��ӵ�����ڵ㣻���û���Һ���
* �Ըýڵ�Ϊĳ���ڵ�����ӵ����ҽڵ�������ڵ�Ϊ��̽ڵ㣻 
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
	//1.�ýڵ����Һ��ӣ��򷵻��Һ��ӵ�����ڵ� 
	if(node->right != NULL){
		return getLeftMost(node->right);
	}
	//2.�ýڵ����Һ��ӣ�
	Node* cur = node;
	Node* parent = cur->parent;
	/*
	* ���Ϊ�Һ����򲻶�������֪���ҵ���Ϊ����
	* �����������ҽڵ����parentΪNULL��ʱ�� 
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
*����������ݹ鷽ʽ���ݹ����--��ӡ--�ݹ��ұ� 
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
	
	cout<<"��̽ڵ�----�������������Ϊ---";
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
