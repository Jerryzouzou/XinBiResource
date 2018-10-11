#include "allh.h"
using namespace std;

/*
* 复制带有随机指针的链表
* 方法一、通过haspmap将原链表每个节点key-value放入haspmap中，然后再通过原链表的
* 连接关系去弄好拷贝节点的关系--unOrderedMap 
* 方法二、拷贝的每个节点都插入到原节点上a->a'->b...这样，然后每次拿两个a,a'，
* 通过a找到a的rand指向节点i，然后a'的rand就指向i的下一个即i'，最后分离回原链表
* 和拷贝的链表---空间复杂度O(1) 
*/

struct Node{
	int value;
	Node* next;
	Node* rand;
	Node(int a=0):value(a), next(NULL), rand(NULL){};
};

static void print_list(struct Node* head);

/*
* 拷贝的每个节点都插入到原节点上a->a'->b...这样，然后每次拿两个a,a'，
* 通过a找到a的rand指向节点i，然后a'的rand就指向i的下一个即i'，最后分离回原链表
* 和拷贝的链表
*/
static struct Node* copyListWithRand(Node* head){
	if(head == NULL){
		return NULL;
	}
	Node* cur = head;
	Node* next = NULL;
	Node* copy = NULL;
	Node* res = NULL;
	while(cur != NULL){		//形成a->a'->b...这样链表 
		Node* tmp = (struct Node*)malloc(sizeof(Node));
		tmp->value = cur->value;
		tmp->next = cur->next;
		cur->next = tmp;
		cur = cur->next->next;
	}
	cur = head;
	while(cur != NULL){		//通过a找到a的rand指向节点i，然后a'的rand就指向i的下一个即i'
		next = cur->next->next;
		copy = cur->next;
		copy->rand = cur->rand!=NULL ? cur->rand->next : NULL;
		cur = next;
	}
	res = head->next;
	cur = head;
	while(cur != NULL){		//原链表和复制链表分离出来 
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
	cout<<"**********原链表*************"<<endl;
	print_list(head);
	cout<<"**********拷贝链表***********"<<endl;
	print_list(copyRes1);
} 

