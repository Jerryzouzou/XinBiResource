#include "allh.h"
using namespace std;

/*
* 找到链表如果是有环的找到环点 
* 两个指针，一个一次走一步，一个一次走两步，有相遇就是有环
* 相遇后快指针到回head变成一样慢指针，再次相遇点为入环点 
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
	Node* n1 = head->next;	//慢指针 
	Node* n2 = head->next->next; 	//快指针 
	while(n1 != n2){
		if(n2->next==NULL || n2->next->next==NULL){		//快指针能走到NULL,说明无环 
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

void linkList_isLoop_main(){
	int arr[5] = {1, 2, 3, 4, 5};
	Node* head = createList(arr, 5);
	head->next->next->next->next->next = head->next->next; 	//5->3, 3是入环点
	Node* loop =  getLoopNode(head);
	if(loop == NULL){
		cout<<"******链表无环*******"<<endl;
	}else{
		cout<<"******链表入环点："<<loop->value<<endl;
	}
} 


