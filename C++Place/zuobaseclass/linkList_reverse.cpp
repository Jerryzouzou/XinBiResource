#include "allh.h"
using namespace std;

/*
* 单向链表和双向链表反转 
* 单向：三个指针指向一二三节点，二指针的next指向一；一移到二，二三分别指向下一个，即向右移，再循环上面的 
* 双向链表： 
*  
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

/*
* 三个指针指向一二三节点，二指针的next指向一；一移到二，二三分别指向下一个，即向右移，再循环上面的
*/
static struct Node* reverseList(Node* head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* pre = NULL;
	Node* next = NULL;
	while(head != NULL){
		next = head->next;
		head->next = pre;	//head往前指，反转 
		pre = head;		//pre往右移到当前 
		head = next;
	}
	
	return pre;
}

/*
* 还是三个指针，但是要处理好last指针的关系 
*/
static struct DoubleNode* reverseDoubleList(DoubleNode* head){
	DoubleNode* pre = NULL;
	DoubleNode* next = NULL;
	while(head != NULL){
		next = head->next;
		head->next = pre;	//head往前指，反转 
		head->last = next;	//处理好last的关系 
		pre = head;		//pre往右移到当前 
		head = next;
	}
	
	return pre;
}

/*
*根据数组产生链表 
*/
static struct Node* createList(int* arr, int len){
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
		if(i != len-1){
			p1 = p1->next;
		}
	}
	p1->next = NULL;
	return head;
}

/*
* 打印链表 
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
*根据数组产生双向链表 
*/
static struct DoubleNode* createDoubleList(int* arr, int len){
	DoubleNode *head, *p1;
	head = (struct DoubleNode*)malloc(sizeof(DoubleNode));
	if((p1=(struct DoubleNode*)malloc(sizeof(DoubleNode))) == 0){
		cout<<"分配内存失败";
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
* 打印双向链表 
*/
static void print_doublelist(struct DoubleNode* head){
	DoubleNode* end = NULL;
	while(head != NULL){
		cout<<head->value<<"->";
		end = head;		//循环完end指向最后一个节点 
		head = head->next;
	}
	cout<<" | ";
	while(end != NULL){
		cout<<end->value<<"->";
		end = end->last;
	}
	cout<<endl;
}

void linkList_reverse_main(){
	int arr[6] = {1, 2, 3, 4, 5, 6};
	Node *head1 = createList(arr, 6);
	cout<<"******原始单向链表*******";
	print_list(head1);
	head1 = reverseList(head1);
	cout<<"******反转单向链表*******";
	print_list(head1);
	
	DoubleNode *head2 = createDoubleList(arr, 6);
	cout<<"******原始双向链表*******";
	print_doublelist(head2);
	head2 = reverseDoubleList(head2);
	cout<<"******反转双向链表*******";
	print_doublelist(head2);
}


