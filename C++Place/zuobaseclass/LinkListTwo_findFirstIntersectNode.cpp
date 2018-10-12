#include "allh.h"
using namespace std;

/*
* �����������ཻ�ĸ������� 
* ���һ�����������޻��������ཻ����Y���ཻ--����һ����ϣ���ȱ���head1����
* ����head2�����������ֱ����head1��head2�ҵ��������һ���ڵ�������ȣ������� 
* �ڵ㲻��ͬһ�����ཻ�����򳤵�һ�������������ֵ������һ���ߣ������ĵ�Ϊ��һ���ཻ�� 
* �������һ���л�һ���޻�---���ཻ 
* ��������������л������Ի����ཻ���ཻ�ٹ�ͬ�������뻷�ڻ����ཻ---�������� 
* ���뻷����ͬ�����ཻ�ٹ�ͬ������ô���Խ��뻷��������һ���ڵ���Ϊ���һ��Y���ཻ��
* �뻷�㲻ͬ��һ���뻷�㲻�ߣ���һ���뻷���߲���������һ���뻷�����ཻ����������
* ���������뻷�ڻ����ཻ�������뻷�㶼�����ǵ�һ���ཻ�� 
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
	if(loop1==NULL && loop2==NULL){		//���޻� 
		return noLoop_intersectNode(head1, head2);
	}else if(loop1!=NULL && loop2!=NULL){	//�����л� 
		return bothLoop_intersectNode(head1, loop1, head2, loop2);
	}
	return NULL;
}

/*
* �������л������Ի����ཻ���ཻ�ٹ�ͬ�������뻷�ڻ����ཻ---�������� 
* ���뻷����ͬ�����ཻ�ٹ�ͬ������ô���Խ��뻷��������һ���ڵ���Ϊ���һ��Y���ཻ��
* �뻷�㲻ͬ��һ���뻷�㲻�ߣ���һ���뻷���߲���������һ���뻷�����ཻ����������
* ���������뻷�ڻ����ཻ�������뻷�㶼�����ǵ�һ���ཻ��
*/
static struct Node* bothLoop_intersectNode(Node* head1, Node* loop1, Node* head2, Node* loop2){
	Node* cur1 = NULL;
	Node* cur2 = NULL;
	if(loop1 == loop2){		//�뻷����ͬ�����ɵ��뻷��ǰ���޻������ཻ���� 
		cur1 = head1;
		cur2 = head2;
		int n=0;
		while(cur1 != loop1){	//���뻷����� 
			n++;
			cur1 = cur1->next;
		}
		while(cur2 != loop2){
			n--;		//�����͵õ�����С 
			cur2 = cur2->next;
		}
		cur1 = n>0 ? head1 : head2;		//cur1ָ�򳤵�
		cur2 = n>0 ? head2 : head1;		//cur2ָ��̵� 
		n = abs(n);		//ȡ�� 
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
			if(cur1 == loop2){	//1�Ļ�������loop2˵�������ཻ 
				return loop1;
			}
			cur1 = cur1->next;
		}
		return NULL;
	}
}

/*
* ���������޻�����,���ཻ����Y���ཻ. �ֱ����head1��head2�ҵ��������һ���ڵ�������ȣ������� 
* �ڵ㲻��ͬһ�����ཻ�����򳤵�һ�������������ֵ������һ���ߣ������ĵ�Ϊ��һ���ཻ��
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
		n--;		//�����͵õ�����С 
		cur2 = cur2->next;
	}
	if(cur1 != cur2){	//���ڵ㲻��ͬһ�����ཻ
		return NULL;
	}
	cur1 = n>0 ? head1 : head2;		//cur1ָ�򳤵�
	cur2 = n>0 ? head2 : head1;		//cur2ָ��̵� 
	n = abs(n);		//ȡ�� 
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
* �ҵ�һ��������뻷�㣬û�л�����NULL 
*/
static struct Node* getLoopNode(Node* head){
	if(head==NULL || head->next==NULL || head->next->next==NULL){
		return NULL;
	}
	Node* n1 = head->next;	//��ָ�� 
	Node* n2 = head->next->next; 	//��ָ�� 
	while(n1 != n2){
		if(n2->next==NULL || n2->next->next==NULL){		//��ָ�����ߵ�NULL,˵���޻� 
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

void linkListTwo_findFirstIntersectNode_main(){
	int arr[7] = {1, 2, 3, 4, 5, 6, 7};
	Node* head1 = createList(arr, 7);
	
	// 0->9->8->6->7->null
	Node* head2 = new Node(0);
	head2->next = new Node(9);
	head2->next->next = new Node(8);
	head2->next->next->next = head1->next->next->next->next->next; // 8->6
	cout<<"---�ཻ��a->value��"<<getIntersectNode(head1, head2)->value<<" "<<endl;
	
	head1->next->next->next->next->next->next = head1->next->next->next; // 7->4 4Ϊ�뻷�� 
	// 0->9->8->2...
	head2 = new Node(0);
	head2->next = new Node(9);
	head2->next->next = new Node(8);
	head2->next->next->next = head1->next; // 8->2
	cout<<"---�ཻ��b->value��"<<getIntersectNode(head1, head2)->value<<" "<<endl;
	
	//  0->9->8->6->4->5->6..
	head2 = new Node(0);
	head2->next = new Node(9);
	head2->next->next = new Node(8);
	head2->next->next->next = head1->next->next->next->next->next; // 8->6  6Ϊ����2���뻷�� 
	cout<<"---�ཻ��c->value��"<<getIntersectNode(head1, head2)->value<<" "<<endl;
}


