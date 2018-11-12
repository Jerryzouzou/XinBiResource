#include "allh.h"
using namespace std;

/*
* 反转部分from-to链表：找到反转部分的前一个和后一个节点pre和pos，将反转部分按反转 
* 单链表一样三指针反转，最后再将三个部分串起来 
*/

struct Node{
	int value;
	Node* next;
	Node(int a=0):value(a), next(NULL){};
};

static struct Node* reversePart(Node* head, int from, int to){
	int len = 0;
	Node* cur = head;
	Node* fpre = NULL;
	Node* tpos = NULL;
	while(cur != NULL){
		len++;
		fpre = len==from-1 ? cur : fpre;	//确定fpre节点 
		tpos = len==to+1 ? cur : tpos;	//确定tpos节点
		cur = cur->next;
	} 
	if(from>to || from<1 || to>len){	//base case
		return head;
	}
	cur = fpre==NULL ? head : fpre->next;	//确定反转部分是否包含头 
	Node* next = NULL;
	Node* p = cur->next;
	cur->next = tpos;
	while(p != tpos){	//反转部分，到tpos结束 
		next = p->next;
		p->next = cur;
		cur = p;
		p = next;
	}
	if(fpre != NULL){	//反转部分不包含头，则头不用变 
		fpre->next = cur;
		return head;
	}else{	//反转部分包含头，则头变为反转后的头 
		return cur;
	}
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

void linkList_reversePart_main(){
	int arr1[1] = {1};
	int arr2[2] = {1, 2};
	int arr3[3] = {1, 2, 3};
	Node* head = NULL;
	cout<<"原链表为---";
	print_list(head);
	head = reversePart(head, 1, 1);
	cout<<"链表反转1~1后为---";
	print_list(head);
	
	head = createList(arr1, 1);
	cout<<"原链表为---";
	print_list(head);
	head = reversePart(head, 1, 1);
	cout<<"链表反转1~1后为---";
	print_list(head);
	
	head = createList(arr2, 2);
	cout<<"原链表为---";
	print_list(head);
	head = reversePart(head, 1, 2);
	cout<<"链表反转1~2后为---";
	print_list(head);
	
	head = createList(arr3, 3);
	cout<<"原链表为---";
	print_list(head);
	head = reversePart(head, 2, 3);
	cout<<"链表反转2~3后为---";
	print_list(head);
	
	head = createList(arr3, 3);
	cout<<"原链表为---";
	print_list(head);
	head = reversePart(head, 1, 3);
	cout<<"链表反转1~3后为---";
	print_list(head);
}

