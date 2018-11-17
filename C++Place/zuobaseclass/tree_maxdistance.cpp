#include "allh.h"
using namespace std;

/*
* �������������
* �ݹ鷽ʽ---ReturnDataΪ��ǰ�ڵ�Ϊͷ�����������ȣ��ֱ�õ�left��right��
* ReturnData����ǰ�ڵ�����Ϊ�ϴ����+1�������Ϊleft���������right�� 
* �������(left_deep+right_deep+1)�����ֵ��Ϊ��ǰ�ڵ�Ϊͷ��������� 
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
* �ݹ���Ծ�����Ϊ�õ����뵽�õ���ֵ 
*/
static ReturnData* process(Node* x){
	if(x == NULL){
		return new ReturnData(0, 0);
	}
	
	ReturnData* left = process(x->left);	//�ݹ��ȡ���ӵ�ReturnData 
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


