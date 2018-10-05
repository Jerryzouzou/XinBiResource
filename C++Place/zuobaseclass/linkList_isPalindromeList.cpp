#include "allh.h"
using namespace std;

/*
* 链表是回文结构 
* 一、把链表的值全部或者右半部分压入栈中，然后链表从头开始和弹出的栈顶比较是否相等 
* 二、找到中间位置，把右半部分链表反转，然后两边往中间依次比较 
*/

struct Node{
	int value;
	Node* next;
	Node(int a=0):value(a), next(NULL){};
};

//把链表每个节点压入栈中，然后链表从头开始和弹出的栈顶比较值是否相等--额外空间O(N) 
bool isPalindromeList_useStack(Node* head){
	struct Node *p = head;
	stack<Node> helpStack;
	while(p != NULL){
		helpStack.push(*p);
		p = p->next;
	}
	while(head != NULL){
		if(head->value != helpStack.top().value){
			//helpStack.pop();
			return false;
		}
		helpStack.pop();
		head = head->next;
	}
	
	return true;
}

//把链表右半部分每个节点压入栈中，然后链表从头开始和弹出的栈顶（相当于左边和右边比较）比较值是否相等--额外空间O(N/2)
bool isPalindromeList_useHalfStack(Node* head){
	if(head == NULL || head->next==NULL){
		return true;
	}
	Node* right = head->next;	//从第二个节点开始 
	Node* cur = head;
	while(cur->next!=NULL && cur->next->next!=NULL){
		right = right->next;
		cur = cur->next->next;		//cur一下走两步，right一下走一步。这样走完的时候right就在右半部分的第一个 
	}
	stack<Node> rightStack;
	while(right != NULL){	//把右半部分压入栈 
		rightStack.push(*right);
		right = right->next;
	}
	while(!rightStack.empty()){		//用栈弹出右边的和左边比较，奇数个的话中间那个不用管 
		if(head->value != rightStack.top().value){
			//helpStack.pop();
			return false;
		}
		rightStack.pop();
		head = head->next;
	}
	return true;
}

bool  isPalindromeList_to2list(Node* head){
	
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

void linkList_isPalindromeList_main(){
	int arr1[2] = {1, 2};
	int arr2[2] = {1, 1};
	int arr3[3] = {1, 2, 3};
	int arr4[3] = {1, 2, 1};
	int arr5[4] = {1, 2, 3, 1};
	int arr6[5] = {1, 2, 2, 1};
	int arr7[5] = {1, 2, 3, 2, 1};
//	Node *head1 = (struct Node*)malloc(sizeof(Node));
//	Node *head2 = (struct Node*)malloc(sizeof(Node));
//	head1 = createList(arr1, 4);
//	head2 = createList(arr2, 5);
//	cout<<"链表1===";
//	print_list(head1);
//	cout<<"链表2===";
//	print_list(head2);
//	printListCommonPart(*head1, *head2);
	Node *head1 = NULL;
	cout<<"链表为";
	print_list(head1);
	cout<<"栈方式--链表是否是回文结构："<<isPalindromeList_useStack(head1)<<endl;
	cout<<"半栈方式--链表是否是回文结构："<<isPalindromeList_useHalfStack(head1)<<endl;
	
	cout<<"======================="<<endl;
	
	Node *head2=new Node(1); //(struct Node*)malloc(sizeof(Node));
	cout<<"链表为";
	print_list(head2);
	cout<<"栈方式--链表是否是回文结构："<<isPalindromeList_useStack(head2)<<endl;
	cout<<"半栈方式--链表是否是回文结构："<<isPalindromeList_useHalfStack(head2)<<endl;
	
	cout<<"======================="<<endl;
	
	Node *head3 = createList(arr1, 2);
	cout<<"链表为";
	print_list(head3);
	cout<<"栈方式--链表是否是回文结构："<<isPalindromeList_useStack(head3)<<endl;
	cout<<"半栈方式--链表是否是回文结构："<<isPalindromeList_useHalfStack(head3)<<endl;
	
	cout<<"======================="<<endl;
	
	Node *head4 = createList(arr2, 2);
	cout<<"链表为";
	print_list(head4);
	cout<<"栈方式--链表是否是回文结构："<<isPalindromeList_useStack(head4)<<endl;
	cout<<"半栈方式--链表是否是回文结构："<<isPalindromeList_useHalfStack(head4)<<endl;
	
	cout<<"======================="<<endl;
	
	Node *head5 = createList(arr3, 3);
	cout<<"链表为";
	print_list(head5);
	cout<<"栈方式--链表是否是回文结构："<<isPalindromeList_useStack(head5)<<endl;
	cout<<"半栈方式--链表是否是回文结构："<<isPalindromeList_useHalfStack(head5)<<endl;
	
	cout<<"======================="<<endl;
	
	Node *head6 = createList(arr4, 3);
	cout<<"链表为";
	print_list(head6);
	cout<<"栈方式--链表是否是回文结构："<<isPalindromeList_useStack(head6)<<endl;
	cout<<"半栈方式--链表是否是回文结构："<<isPalindromeList_useHalfStack(head6)<<endl;
	
	cout<<"======================="<<endl;
	
	Node *head7 = createList(arr5, 4);
	cout<<"链表为";
	print_list(head7);
	cout<<"栈方式--链表是否是回文结构："<<isPalindromeList_useStack(head7)<<endl;
	cout<<"半栈方式--链表是否是回文结构："<<isPalindromeList_useHalfStack(head7)<<endl;
	
	cout<<"======================="<<endl;
	
	Node *head8 = createList(arr6, 4);
	cout<<"链表为";
	print_list(head8);
	cout<<"栈方式--链表是否是回文结构："<<isPalindromeList_useStack(head8)<<endl;
	cout<<"半栈方式--链表是否是回文结构："<<isPalindromeList_useHalfStack(head8)<<endl;
	
	cout<<"======================="<<endl;
	
	Node *head9 = createList(arr7, 5);
	cout<<"链表为";
	print_list(head9);
	cout<<"栈方式--链表是否是回文结构："<<isPalindromeList_useStack(head9)<<endl;
	cout<<"半栈方式--链表是否是回文结构："<<isPalindromeList_useHalfStack(head9)<<endl;
	
	cout<<"======================="<<endl;
}


