#include "allh.h"
using namespace std;

/*
* ���������Լɪ�����⣺���������һ������m������ÿ��m-1���ͽ���һ���ڵ�ɾ��ֱ��ֻʣ��һ���ڵ�
* ˼·һ��ѭ����ͣɾ��ֱ��ֻʣ��һ�£�ʱ�临�Ӷ�O(n*m)
* ˼·��������������ֻʣ�ĸ��ڵ㣻����Ϊi������ʣ�µĽڵ�ΪNum(i), Num(i)=(Num(i-1)+m-1)%i+1,�ȵݹ����Num(i);
* ���豨A���Ǳ��B�Ľڵ���B=(A-1)%i+1,����m��ɾ����A=mʱB=(m-1)%i+1��sΪɾ���ڵ㣬��ɾ�����½ڵ�������old=(new+s-1)%i+1��
* s=B��Num(i)=old��Num(i-1)=new������Num(i)=(Num(i-1)+m-1)%i+1 ;ʱ�临�Ӷ�O(n)
*/

struct Node{
	int value;
	Node* next;
	Node(int a=0):value(a), next(NULL){};
};

/*
* ѭ����ͣɾ��ֱ��ֻʣ��һ�£�ʱ�临�Ӷ�O(n*m)
*/
static struct Node* josephusKill1(Node* head, int m){
	if(head==NULL || head->next==head || m<1){
		return head;
	}
	Node* last = head;
	while(last->next != head){	//last�ߵ�headǰһ�� 
		last = last->next;
	}
	int count = 0;
	while(last != head){	//head��ǰһ���Ǳ���˵��ֻʣ��һ���ڵ� 
		if(++count == m){
			last->next = head->next;	//��mɾ��һ�� 
			count = 0;
		}else{
			last = last->next;
		}
		head = last->next;
	}
	return head;
}

/*
* ����Num(i)=(Num(i-1)+m-1)%i+1�ݹ������Num(i)��Ȼ���ҵ��Ǹ��ڵ�Ū��ֻ���Լ��ĵ�Ļ� 
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
	tmp = getLive(tmp, m); 	//ʣ�½ڵ�
	while(--tmp != 0){
		head = head->next;	//�ҵ��ڵ� 
	} 
	head->next = head;		//���Ľڵ�Ūֻ�иýڵ�Ļ� 
	
	return head;
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
* ��ӡ�������� 
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

