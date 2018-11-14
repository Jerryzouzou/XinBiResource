#include "allh.h"
using namespace std;

/*
* 环形链表的约瑟夫问题：环形链表和一个报数m，链表每走m-1步就将下一个节点删除直到只剩下一个节点
* 思路一：循环不停删除直到只剩下一下，时间复杂度O(n*m)
* 思路二：先算出来最后只剩哪个节点；另长度为i的链表剩下的节点为Num(i), Num(i)=(Num(i-1)+m-1)%i+1,先递归求出Num(i);
* 假设报A的是编号B的节点则B=(A-1)%i+1,报到m被删除则A=m时B=(m-1)%i+1，s为删除节点，则删除后新节点编号满足old=(new+s-1)%i+1；
* s=B，Num(i)=old，Num(i-1)=new，所以Num(i)=(Num(i-1)+m-1)%i+1 ;时间复杂度O(n)
*/

struct Node{
	int value;
	Node* next;
	Node(int a=0):value(a), next(NULL){};
};

/*
* 循环不停删除直到只剩下一下，时间复杂度O(n*m)
*/
static struct Node* josephusKill1(Node* head, int m){
	if(head==NULL || head->next==head || m<1){
		return head;
	}
	Node* last = head;
	while(last->next != head){	//last走到head前一个 
		last = last->next;
	}
	int count = 0;
	while(last != head){	//head的前一个是本身说明只剩下一个节点 
		if(++count == m){
			last->next = head->next;	//到m删除一个 
			count = 0;
		}else{
			last = last->next;
		}
		head = last->next;
	}
	return head;
}

/*
* 根据Num(i)=(Num(i-1)+m-1)%i+1递归先求出Num(i)，然后找到那个节点弄成只有自己的点的环 
*/
int getLive(int i, int m){
	if(i == 1){
		return 1;
	}
	return (getLive(i-1, m) + m -1) % i + 1;
} 

static struct Node* josephusKill2(Node* head, int m){
	if(head==NULL || head->next==head || m<1){
		return head;
	}
	Node* cur = head->next;
	int tmp = 1;	//list size
	while(cur != head){
		tmp++;
		cur = cur->next;
	}
	tmp = getLive(tmp, m); 	//剩下节点
	while(--tmp != 0){
		head = head->next;	//找到节点 
	} 
	head->next = head;		//将改节点弄只有该节点的环 
	
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
* 打印环形链表 
*/
static void print_list(struct Node* head){
	//Node *p1 = &head;
	if(head == NULL){
		return;
	}
	Node* cur = head->next;
	cout<<"Circular List: "<<head->value<<"->";
	int cnt = 0;
	while(head != cur &&cnt<10){
		cnt++;
		cout<<cur->value<<"->";
		cur = cur->next;
	}
	cout<<"->"<<head->value<<endl;
}

void linkList_josephusProblem_main(){
	int arr[5] = {1, 2, 3, 4, 5};
	Node* head1 = createList(arr, 5);
	head1->next->next->next->next->next = head1;
	print_list(head1);
	head1 = josephusKill1(head1, 3);
	print_list(head1);
	
	Node* head2 = createList(arr, 5);
	head2->next->next->next->next->next = head2;
	print_list(head2);
	head2 = josephusKill2(head2, 3);
	print_list(head2);
}

