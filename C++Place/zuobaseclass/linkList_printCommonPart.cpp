#include "allh.h"
using namespace std;

/*
* 打印两个有序链表的公共部分--注意是有序 
* 两个链表从头开始，表1数值小表1往下移，表2数值小表2往下移，
* 相等时打印，都往下移 
*/

struct Node{
	int value;
	Node* next;
	Node(int a=0):value(a), next(NULL){};
};

/*
*两个链表从头开始，表1数值小表1往下移，表2数值小表2往下移，相等时打印，都往下移
*/
void printListCommonPart(Node head1, Node head2){
	Node *p1 = &head1;
	Node *p2 = &head2;
	cout<<"两链表公共部分: ";
	while(p1->next!=NULL && p2->next!=NULL){
		if(p1->value < p2->value){
			p1 = p1->next;
		}else if(p2->value < p1->value){
			p2 = p2->next;
		}else{
			cout<<p1->value<<" ";
			p1 = p1->next;
			p2 = p2->next;
		}
	} 
	cout<<endl;
}

void print_list(struct Node* head){
	//Node *p1 = &head;
	while(head->next != NULL){
		cout<<head->value<<"->";
		head = head->next;
	}
	cout<<endl;
}

struct Node* createList(int* arr, int len){
	Node *head, *p1;
	head = (struct Node*)malloc(sizeof(Node));
	if((p1=(struct Node*)malloc(sizeof(Node))) == 0){
		cout<<"分配内存失败";
		exit(0);
	}
	if(len < 1) return NULL;
	head = p1;
	for(int i=0; i<len; i++){
		Node *tmp = (struct Node*)malloc(sizeof(Node));
		p1->value = arr[i];
		p1->next = tmp;
		p1 = p1->next;
	}
	p1->next = NULL;
	return head;
}

void linkList_printCommonPart_main(){
	int arr1[4] = {2, 3, 5, 6};
	int arr2[5] = {1, 2, 5, 7, 8};
	Node *head1 = (struct Node*)malloc(sizeof(Node));
	Node *head2 = (struct Node*)malloc(sizeof(Node));
	head1 = createList(arr1, 4);
	head2 = createList(arr2, 5);
	cout<<"链表1===";
	print_list(head1);
	cout<<"链表2===";
	print_list(head2);
	printListCommonPart(*head1, *head2);
}

