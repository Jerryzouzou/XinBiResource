#include "allh.h"
using namespace std;

/*
* �������Ƿ�������������--���н�㣺��<��<�� 
* �ݹ鷽ʽ��ÿ���ݹ鷵�ص�ǰ�ڵ����Сֵ���ֵ���Ƿ�������������--ReturnData
* ���������ʽ����������ǵ�����˵�������������� 

* �������Ƿ�����ȫ������--��ȫ�������Ӹ���㵽�����ڶ����������������������һ����Բ���ȫ��䣬��Ҷ�ӽ�㶼������� 
* �ݹ鷽ʽ��ÿ���ݹ鷵�ص�ǰ�ڵ� 
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
* �ݹ���Ծ�����Ϊ�õ����뵽�õ���ֵ 
*/
static ReturnData* process(Node* x){
	if(x == NULL){
		return new ReturnData(true, 0x7FFFFFFF, 0xFFFFFFFF);
	}
	
	ReturnData* left = process(x->left);	//�ݹ��ȡ���ӵ�ReturnData 
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

struct ReturnData1{
	bool isCBT;
	ReturnData1(bool b=false):isCBT(b){};
};

static ReturnData1* process1(Node* x){
	if(x == NULL){
		return new ReturnData1(true);
	}
	
	ReturnData1* left = process1(x->left);	//�ݹ��ȡ���ӵ�ReturnData 
	ReturnData1* right = process1(x->right); 
	
	bool isCBT = true;
	if(!left->isCBT || !right->isCBT || (x->left==NULL && x->right!=NULL)){		//���Һ���ʱ������������ȫ������ 
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