#include "allh.h"
using namespace std;

/*
* ���ƴ������ָ�������
* ����һ��ͨ��haspmap��ԭ����ÿ���ڵ�key-value����haspmap�У�Ȼ����ͨ��ԭ�����
* ���ӹ�ϵȥŪ�ÿ����ڵ�Ĺ�ϵ--unOrderedMap 
* ��������������ÿ���ڵ㶼���뵽ԭ�ڵ���a->a'->b...������Ȼ��ÿ��������a,a'��
* ͨ��a�ҵ�a��randָ��ڵ�i��Ȼ��a'��rand��ָ��i����һ����i'���������ԭ����
* �Ϳ���������---�ռ临�Ӷ�O(1) 
*/

struct Node{
	int value;
	Node* next;
	Node* rand;
	Node(int a=0):value(a), next(NULL), rand(NULL){};
};

static void print_list(struct Node* head);

/*
* ������ÿ���ڵ㶼���뵽ԭ�ڵ���a->a'->b...������Ȼ��ÿ��������a,a'��
* ͨ��a�ҵ�a��randָ��ڵ�i��Ȼ��a'��rand��ָ��i����һ����i'���������ԭ����
* �Ϳ���������
*/
static struct Node* copyListWithRand(Node* head){
	if(head == NULL){
		return NULL;
	}
	Node* cur = head;
	Node* next = NULL;
	Node* copy = NULL;
	Node* res = NULL;
	while(cur != NULL){		//�γ�a->a'->b...�������� 
		Node* tmp = (struct Node*)malloc(sizeof(Node));
		tmp->value = cur->value;
		tmp->next = cur->next;
		cur->next = tmp;
		cur = cur->next->next;
	}
	cur = head;
	while(cur != NULL){		//ͨ��a�ҵ�a��randָ��ڵ�i��Ȼ��a'��rand��ָ��i����һ����i'
		next = cur->next->next;
		copy = cur->next;
		copy->rand = cur->rand!=NULL ? cur->rand->next : NULL;
		cur = next;
	}
	res = head->next;
	cur = head;
	while(cur != NULL){		//ԭ����͸������������� 
		next = cur->next->next;
		copy = cur->next;
		cur->next = next;
		copy->next = next!=NULL ? next->next : NULL;
		cur = next;
	}
	
	return res;
} 

/*
*
*/
static struct Node* copyListWithRand_useMap(Node* head){
	Node *cur = head;
	
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
	Node* cur = head;
	cout<<"order: ";
	while(cur != NULL){
		cout<<cur->value<<"->";
		cur = cur->next;
	}
	cout<<endl;
	
	cur = head;
	cout<<"rand: ";
	while(cur != NULL){
		if(cur->rand==NULL){
			cout<<" - ";
		}else{
			cout<<cur->rand->value<<" ";
		}
		cur = cur->next;
	}
	cout<<endl;
}

void copyListWithRand_main(){
	int arr[6] = {1, 2, 3, 4, 5, 6};
	Node *head = createList(arr, 6);
	head->rand = head->next->next->next->next->next; // 1 -> 6
	head->next->rand = head->next->next->next->next->next; // 2 -> 6
	head->next->next->rand = head->next->next->next->next; // 3 -> 5
	head->next->next->next->rand = head->next->next; // 4 -> 3
	head->next->next->next->next->rand = NULL; // 5 -> null
	head->next->next->next->next->next->rand = head->next->next->next; // 6 -> 4
	Node *copyRes1 = copyListWithRand(head);
	cout<<"**********ԭ����*************"<<endl;
	print_list(head);
	cout<<"**********��������***********"<<endl;
	print_list(copyRes1);
} 

