#include "allh.h"
using namespace std;

/*
* �ҵ�����������л����ҵ����� 
* ����ָ�룬һ��һ����һ����һ��һ���������������������л�
* �������ָ�뵽��head���һ����ָ�룬�ٴ�������Ϊ�뻷�� 
*/

struct Node{
	int value;
	Node* next;
	Node(int a=0):value(a), next(NULL){};
};

static struct Node* getLoopNode(Node* head){
	if(head==NULL || head->next==NULL || head->next->next==NULL){
		return NULL;
	}
	Node* n1 = head->next;	//��ָ�� 
	Node* n2 = head->next->next; 	//��ָ�� 
	while(n1 != n2){
		if(n2->next==NULL || n2->next->next==NULL){		//��ָ�����ߵ�NULL,˵���޻� 
			return NULL;
		}
		n1 = n1->next;
		n2 = n2->next->next;
	}
	n2 = head;
	while(n1 != n2){
		n1 = n1->next;
		n2 = n2->next;
	}
	return n1;
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

void linkList_isLoop_main(){
	int arr[5] = {1, 2, 3, 4, 5};
	Node* head = createList(arr, 5);
	head->next->next->next->next->next = head->next->next; 	//5->3, 3���뻷��
	Node* loop =  getLoopNode(head);
	if(loop == NULL){
		cout<<"******�����޻�*******"<<endl;
	}else{
		cout<<"******�����뻷�㣺"<<loop->value<<endl;
	}
} 


