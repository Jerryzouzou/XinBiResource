#include "allh.h"
using namespace std;

/*
* �������Ƿ���ƽ�������--�������������߶�������1 
* �ݹ鷽ʽ��ÿ���ݹ鷵�ص�ǰ�ڵ�ĸ߶Ⱥ��Ƿ���ƽ�������--ReturnData 
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
* �ݹ���Ծ�����Ϊ�õ����뵽�õ���ֵ 
*/
static ReturnData* process(Node* x){
	if(x == NULL){
		return new ReturnData(0, true);
	}
	
	ReturnData* left = process(x->left);	//�ݹ��ȡ���ӵ�ReturnData 
	ReturnData* right = process(x->right); 
	int height = max(left->height, right->height) + 1;
	int isBalance = true;
	if(!left->isBalance || !right->isBalance){	//��һ���ǲ�ƽ��������嶼�ǲ�ƽ��� 
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
