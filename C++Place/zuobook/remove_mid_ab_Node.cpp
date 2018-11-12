#include "allh.h"
using namespace std;

/*
* ɾ�������м�ڵ㣺һ����ָ��һ����ָ�룬��ָ��������ָ����ߵ��м�ڵ� 
* ɾ������a/bλ�ýڵ㣺����double r=(a*len)/b; ����ȡ�������ɾ���ڼ����ڵ� 
*/

struct Node{
	int value;
	Node* next;
	Node(int a=0):value(a), next(NULL){};
};

static struct Node* removeMidNode(Node* head){
	if(head==NULL || head->next==NULL){		//base case
		return head;
	}
	if(head->next->next == NULL){
		return head->next;
	}
	Node* pre = head;	//����һ������ôcur����pre->nextָ���м�ڵ� 
	Node* cur = head->next->next;
	while(cur->next!=NULL && cur->next->next!=NULL){
		pre = pre->next;
		cur = cur->next->next;
	}
	pre->next = pre->next->next;
	return head;
}

static struct Node* removeByRatio(Node* head, int a, int b){
	if(a<1 || a>b){
		return head;
	}
	int len = 0;
	Node* cur = head;
	while(cur != NULL){
		len++;
		cur=cur->next;
	}
	int r = (int)ceil(((double)a*len)/(double)b);
	if(r == 1){
		return head->next;
	}
	if(r > 1){
		cur = head;
		while(--r > 1){
			cur = cur->next;
		}
		cur->next = cur->next->next;
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

void remove_mid_ab_Node_main(){
	int arr[6] = {1, 2, 3, 4, 5, 6};
	Node* head = createList(arr, 6);
	cout<<"ԭʼ����Ϊ---";
	print_list(head);
	head = removeMidNode(head);
	cout<<"ɾ���м�ڵ������Ϊ---";
	print_list(head);
	head = removeByRatio(head, 2, 5);
	cout<<"ɾ��2/5���ڵ������Ϊ---";
	print_list(head);
	head = removeByRatio(head, 1, 3);
	cout<<"ɾ��1/3���ڵ������Ϊ---";
	print_list(head);
}


