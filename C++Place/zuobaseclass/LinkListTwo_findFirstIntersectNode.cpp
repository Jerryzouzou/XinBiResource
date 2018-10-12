#include "allh.h"
using namespace std;

/*
* 两条单链表相交的各种问题 
* 情况一：两条都是无环链表：不相交或者Y型相交--方法一：哈希表，先遍历head1，再
* 遍历head2；方法二：分别遍历head1和head2找到各自最后一个节点和链表长度，如果最后 
* 节点不是同一个则不相交，否则长的一个链表先走相差值步，再一起走，相遇的点为第一个相交点 
* 情况二：一个有环一个无环---不相交 
* 情况三：两个都有环：各自环不相交或相交再共同环或先入环在环上相交---方法：两 
* 个入环点相同则是相交再共同环，那么可以将入环点最后最后一个节点则为情况一的Y型相交；
* 入环点不同，一个入环点不走，另一个入环点走不会遇到另一个入环点则不相交，会遇到的
* 话则是先入环在环上相交，两个入环点都可以是第一个相交点 
*/

struct Node{
	int value;
	Node* next;
	Node(int a=0):value(a), next(NULL){};
};

static struct Node* getLoopNode(Node* head);
static struct Node* bothLoop_intersectNode(Node* head1, Node* loop1, Node* head2, Node* loop2);
static struct Node* noLoop_intersectNode(Node* head1, Node* head2);

struct Node* getIntersectNode(Node* head1, Node* head2){
	if(head1==NULL || head2==NULL){
		return NULL;
	}
	Node* loop1 = getLoopNode(head1);
	Node* loop2 = getLoopNode(head2);
	//cout<<loop1->value<<"----****---"<<loop2->value<<endl;
	if(loop1==NULL && loop2==NULL){		//俩无环 
		return noLoop_intersectNode(head1, head2);
	}else if(loop1!=NULL && loop2!=NULL){	//俩都有环 
		return bothLoop_intersectNode(head1, loop1, head2, loop2);
	}
	return NULL;
}

/*
* 两个都有环：各自环不相交或相交再共同环或先入环在环上相交---方法：两 
* 个入环点相同则是相交再共同环，那么可以将入环点最后最后一个节点则为情况一的Y型相交；
* 入环点不同，一个入环点不走，另一个入环点走不会遇到另一个入环点则不相交，会遇到的
* 话则是先入环在环上相交，两个入环点都可以是第一个相交点
*/
static struct Node* bothLoop_intersectNode(Node* head1, Node* loop1, Node* head2, Node* loop2){
	Node* cur1 = NULL;
	Node* cur2 = NULL;
	if(loop1 == loop2){		//入环点相同，看成到入环点前的无环链表相交问题 
		cur1 = head1;
		cur2 = head2;
		int n=0;
		while(cur1 != loop1){	//到入环点结束 
			n++;
			cur1 = cur1->next;
		}
		while(cur2 != loop2){
			n--;		//这样就得到相差大小 
			cur2 = cur2->next;
		}
		cur1 = n>0 ? head1 : head2;		//cur1指向长的
		cur2 = n>0 ? head2 : head1;		//cur2指向短的 
		n = abs(n);		//取正 
		while(n>0){
			n--;
			cur1 = cur1->next;
		}
		while(cur1 != cur2){
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}else{
		cur1 = loop1->next;
		while(cur1 != loop1){
			if(cur1 == loop2){	//1的环会遇到loop2说明环会相交 
				return loop1;
			}
			cur1 = cur1->next;
		}
		return NULL;
	}
}

/*
* 两条都是无环链表,不相交或者Y型相交. 分别遍历head1和head2找到各自最后一个节点和链表长度，如果最后 
* 节点不是同一个则不相交，否则长的一个链表先走相差值步，再一起走，相遇的点为第一个相交点
*/
static struct Node* noLoop_intersectNode(Node* head1, Node* head2){
	if(head1==NULL || head2==NULL){
		return NULL;
	}
	Node* cur1 = head1;
	Node* cur2 = head2;
	int n=0;
	while(cur1 != NULL){
		n++;
		cur1 = cur1->next;
	}
	while(cur2 != NULL){
		n--;		//这样就得到相差大小 
		cur2 = cur2->next;
	}
	if(cur1 != cur2){	//最后节点不是同一个则不相交
		return NULL;
	}
	cur1 = n>0 ? head1 : head2;		//cur1指向长的
	cur2 = n>0 ? head2 : head1;		//cur2指向短的 
	n = abs(n);		//取正 
	while(n>0){
		n--;
		cur1 = cur1->next;
	}
	while(cur1 != cur2){
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}

/*
* 找到一个链表的入环点，没有环返回NULL 
*/
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

void linkListTwo_findFirstIntersectNode_main(){
	int arr[7] = {1, 2, 3, 4, 5, 6, 7};
	Node* head1 = createList(arr, 7);
	
	// 0->9->8->6->7->null
	Node* head2 = new Node(0);
	head2->next = new Node(9);
	head2->next->next = new Node(8);
	head2->next->next->next = head1->next->next->next->next->next; // 8->6
	cout<<"---相交点a->value："<<getIntersectNode(head1, head2)->value<<" "<<endl;
	
	head1->next->next->next->next->next->next = head1->next->next->next; // 7->4 4为入环点 
	// 0->9->8->2...
	head2 = new Node(0);
	head2->next = new Node(9);
	head2->next->next = new Node(8);
	head2->next->next->next = head1->next; // 8->2
	cout<<"---相交点b->value："<<getIntersectNode(head1, head2)->value<<" "<<endl;
	
	//  0->9->8->6->4->5->6..
	head2 = new Node(0);
	head2->next = new Node(9);
	head2->next->next = new Node(8);
	head2->next->next->next = head1->next->next->next->next->next; // 8->6  6为链表2的入环点 
	cout<<"---相交点c->value："<<getIntersectNode(head1, head2)->value<<" "<<endl;
}


