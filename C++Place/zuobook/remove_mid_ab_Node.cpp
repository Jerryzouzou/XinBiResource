#include "allh.h"
using namespace std;

/*
* 删除链表中间节点：一个慢指针一个快指针，快指针走完慢指针就走到中间节点 
* 删除链表a/b位置节点：计算double r=(a*len)/b; 向上取整后就是删除第几个节点 
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
	Node* pre = head;	//少走一步，那么cur走完pre->next指向中间节点 
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

void remove_mid_ab_Node_main(){
	int arr[6] = {1, 2, 3, 4, 5, 6};
	Node* head = createList(arr, 6);
	cout<<"原始链表为---";
	print_list(head);
	head = removeMidNode(head);
	cout<<"删除中间节点后链表为---";
	print_list(head);
	head = removeByRatio(head, 2, 5);
	cout<<"删除2/5处节点后链表为---";
	print_list(head);
	head = removeByRatio(head, 1, 3);
	cout<<"删除1/3处节点后链表为---";
	print_list(head);
}


