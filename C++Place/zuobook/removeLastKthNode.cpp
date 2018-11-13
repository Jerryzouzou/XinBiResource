#include "allh.h"
using namespace std;

/*
* ��������˫������ɾ��������K���ڵ�
* ������һ����k--���������K���K-LEN�������ڶ��������K==0ʱֹͣ����ʱ�����ߵ���N-Kλ��
* �Ѵ�ʱ�ڵ�ɾ���ͺ� 
*/

struct Node{
	int value;
	Node* next;
	Node(int a=0):value(a), next(NULL){};
};

struct DoubleNode{
	int value;
	DoubleNode* last;
	DoubleNode* next;
	DoubleNode(int a=0):value(a), next(NULL), last(NULL){};
};

Node* removeLastKthNode(Node* head, int k){
	if(head==NULL || k<1){
		return head;
	}
	Node* cur = head;
	while(cur!=NULL){
		k--;
		cur = cur->next;
	}
	if(k == 0){		//˵��ԭK����������ͬ��Ҫɾ������ͷ��� 
		head = head->next;
	}
	if(k < 0){
		cur = head;
		while(++k != 0){
			cur = cur->next;
		}
		cur->next = cur->next->next;
	} 
	return head;
} 

DoubleNode* removeLastKthDoubleNode(DoubleNode* head, int k){
	if(head==NULL || k<1){
		return head;
	}
	DoubleNode* cur = head;
	while(cur!=NULL){
		k--;
		cur = cur->next;
	}
	if(k == 0){		//˵��ԭK����������ͬ��Ҫɾ������ͷ��� 
		head = head->next;
		if(head != NULL){
			head->last = NULL;
		}
	}
	if(k < 0){
		cur = head;
		while(++k != 0){
			cur = cur->next;
		}
		DoubleNode* tmp = cur->next->next;
		cur->next = tmp;
		if(tmp != NULL){
			tmp->last = cur;	
		}
	} 
	return head;
} 

/*
*��������������� 
*/
static struct Node* createList(int* arr, int len){
	Node *head, *p1;
	head = (struct Node*)malloc(sizeof(Node));
	if((p1=(struct Node*)malloc(sizeof(Node))) == 0){
		cout<<"�����ڴ�ʧ��";
		exit(0);
	}
	if(len < 1) return NULL;
	head = p1;
	for(int i=0; i<len; i++){
		Node *tmp = (struct Node*)malloc(sizeof(Node));
		p1->value = arr[i];
		p1->next = tmp;
		if(i != len-1){
			p1 = p1->next;
		}
	}
	p1->next = NULL;
	return head;
}

/*
* ��ӡ���� 
*/
static void print_list(struct Node* head){
	//Node *p1 = &head;
	while(head != NULL){
		cout<<head->value<<"->";
		head = head->next;
	}
	cout<<endl;
}

/*
*�����������˫������ 
*/
static struct DoubleNode* createDoubleList(int* arr, int len){
	DoubleNode *head, *p1;
	head = (struct DoubleNode*)malloc(sizeof(DoubleNode));
	if((p1=(struct DoubleNode*)malloc(sizeof(DoubleNode))) == 0){
		cout<<"�����ڴ�ʧ��";
		exit(0);
	}
	if(len < 1) return NULL;
	head = p1;
	DoubleNode* p2 = NULL;
	for(int i=0; i<len; i++){
		DoubleNode *tmp = (struct DoubleNode*)malloc(sizeof(DoubleNode));
		p1->value = arr[i];
		p1->next = tmp;
		p1->last = p2;
		if(i != len-1){
			p2 = p1;
			p1 = p1->next;
		}
	}
	p1->last = p2;
	p1->next = NULL;
	return head;
}

/*
* ��ӡ˫������ 
*/
static void print_doublelist(struct DoubleNode* head){
	DoubleNode* end = NULL;
	while(head != NULL){
		cout<<head->value<<"->";
		end = head;		//ѭ����endָ�����һ���ڵ� 
		head = head->next;
	}
	cout<<" | ";
	while(end != NULL){
		cout<<end->value<<"->";
		end = end->last;
	}
	cout<<endl;
}

void removeLastKthNode_main(){
	int arr[6] = {1, 2, 3, 4, 5, 6};
	Node *head1 = createList(arr, 6);
	cout<<"******ԭʼ��������*******";
	print_list(head1);
	head1 = removeLastKthNode(head1, 2);
	cout<<"******ɾ�������ڶ����ڵ�����*******";
	print_list(head1);
	
	DoubleNode *head2 = createDoubleList(arr, 6);
	cout<<"******ԭʼ˫������*******";
	print_doublelist(head2);
	head2 = removeLastKthDoubleNode(head2, 6);
	cout<<"******ɾ�������������ڵ�����*******";
	print_doublelist(head2);
}

