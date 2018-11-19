#include "allh.h"
using namespace std;

/*
* ��ȫ�������ڵ�������������߶�N�����ͷ�ڵ�������������󵽴������˵��������
* �������������������Ľڵ������2^(N-1)-1; ���ͷ�ڵ����������������һ��˵����������
* �����������������Ľڵ������2^(N-1-1)-1;�����������һ������ݹ� 
*/ 
 
struct Node{
	int value;
	Node* left;
	Node* right;
	Node(int a=0):value(a), left(NULL), right(NULL){};
};

static int mostLeftLevel(Node* node, int level);
static int bs(Node* node, int l, int h);

static int nodeNum(Node* head){
	if(head == NULL){
		return 0;
	}
	return bs(head, 1, mostLeftLevel(head, 1)); 
}

/*
* �ݹ������nodeΪͷ�ڵ�Ķ������Ľڵ����
* l:��ǰ��l��;
* h:������������� 
*/
static int bs(Node* node, int l, int h){
	if(l == h){
		return 1;
	}
	if(mostLeftLevel(node->right, l+1) == h){	//�����������󵽴����� 
		//��ʱ�������ڵ������ȷ����Ϊ2^(h-l)-1�����ϵ�ǰͷ��㣬���� 
		//Ϊ(1<<(h-l))��Ȼ���ټ����������ļ����ݹ���� 
		return ((1<<(h-l)) + bs(node->right, l+1, h));
	}else{
		//��ʱ����������һ��������������ڵ������ȷ����Ϊ2^(h-l-1)-1,���ϵ�ǰͷ��㣬���� 
		//Ϊ(1<<(h-l-1))��Ȼ���ټ����������ļ����ݹ����  
		return ((1<<(h-l-1)) + bs(node->left, l+1, h));
	}
}

/*
* ����һֱ���ӵĸ߶� 
*/ 
static int mostLeftLevel(Node* node, int level){
	while(node != NULL){
		level++;
		node = node->left;
	}
	return level - 1;
}

void tree_completeTreeNodeNumber_main(){
	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->left = new Node(4);
	head->left->right = new Node(5);
	head->right->left = new Node(6);
	cout<<"node number is == "<<nodeNum(head)<<endl;
}

