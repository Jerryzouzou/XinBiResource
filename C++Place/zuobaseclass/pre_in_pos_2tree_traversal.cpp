#include "allh.h"
using namespace std;

/*
* ��������ǰ���������������ʹ�õݹ鷽ʽ�ͷǵݹ鷽ʽ 
*/

class Node{
	public:
		int value;
		struct Node *left,*right;
		Node(int v=0){value = v; left = NULL; right = NULL;}
};

/*
*ǰ��������ݹ鷽ʽ���ȴ�ӡ�ڵݹ����ұ� 
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
*����������ݹ鷽ʽ���ݹ����--��ӡ--�ݹ��ұ� 
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
*����������ݹ鷽ʽ���ݹ����ұ��ٴ�ӡ 
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
* ǰ��������ǵݹ鷽ʽ�� 
* �Ȱ�ͷѹ��ջ��Ȼ����ջ��Ϊ�յ������£�����ջ������ӡ��Ȼ���Һ��Ӳ�Ϊ��ѹ���Һ��ӣ����Ӳ�Ϊ��ѹ������
* �����ͱ�֤�ȴ�ӡ������Ϊͷ��㣬��ߴ�ӡ����ٴ�ӡ�ұ� 
*/
void preOrderUnRecur(struct Node* head){
	if(head == NULL){
		return;
	}
	stack<struct Node*> t_stack;
	t_stack.push(head);
	while(!t_stack.empty()){
		head = t_stack.top();		//����ջ��Ԫ�أ������� 
		t_stack.pop();		//ɾ��ջ��Ԫ�أ�û�з���ֵ 
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
* ����������ǵݹ鷽ʽ�� 
* ��ͷ��㿪ʼ������ȫ��ѹ��ջ��ֱ�� NULL��Ȼ�󵯳���ӡ�ܵ���һ����㣬���û���Һ��ӣ������������ӡ�ܵ���һ�� 
* ������Һ��ӣ�����Һ��Ӻ����� ���ȫ��ѹ��ջ��ֱ��NULL��
* �����ͱ�֤�ȴ�ӡ����߽���ڵ����ڵ㣬Ȼ���ӡ�Һ��ӵ�����߽�㡣 
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
			head = t_stack.top();		//����ջ��Ԫ�أ������� 
			t_stack.pop();		//ɾ��ջ��Ԫ�أ�û�з���ֵ 
			cout<<head->value<<" ";
			head = head->right;
		}
	}
}

/**
* ����������ǵݹ鷽ʽ 
* ����һ������ջ������ǰ������ķ�ʽ��ֻ������ǰ��Ĵ�ӡ��Ϊѹ�븨��ջ�������ȴ�ӡ�ͱ�ɺ��ӡ��
* ��������ѹ�����ѹ�ұߣ���������������ջ��ʱ��͸���ջ����ѹ�ұ���ѹ��� 
*/
void posOrderUnRecur(struct Node* head){
	if(head == NULL){
		return;
	}
	stack<struct Node*> t_stack, s_stack;
	t_stack.push(head);
	while(!t_stack.empty()){
		head = t_stack.top();		//����ջ��Ԫ�أ������� 
		t_stack.pop();		//ɾ��ջ��Ԫ�أ�û�з���ֵ 
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
* �����������ǵݹ���������ø���ջ�ķ�ʽ 
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
	
	cout<<"********ʹ�õݹ鷽ʽ************"<<endl;
	cout<<"       ---ǰ�����---         "<<endl;
	preOrderRecur(head);
	cout<<endl;
	cout<<"       ---�������---         "<<endl;
	inOrderRecur(head);
	cout<<endl;
	cout<<"       ---�������---         "<<endl;
	posOrderRecur(head);
	cout<<endl;
	
	cout<<"********ʹ�÷ǵݹ鷽ʽ************"<<endl;
	cout<<"       ---ǰ�����---         "<<endl;
	preOrderUnRecur(head);
	cout<<endl;
	cout<<"       ---�������---         "<<endl;
	inOrderUnRecur(head);
	cout<<endl;
	cout<<"       ---�������---         "<<endl;
	posOrderUnRecur(head);
	cout<<endl;
	cout<<"       ---�������2---         "<<endl;
//	posOrderUnRecur2(head);
	cout<<endl;
}
