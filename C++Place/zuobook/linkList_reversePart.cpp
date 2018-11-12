#include "allh.h"
using namespace std;

/*
* ��ת����from-to�����ҵ���ת���ֵ�ǰһ���ͺ�һ���ڵ�pre��pos������ת���ְ���ת 
* ������һ����ָ�뷴ת������ٽ��������ִ����� 
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
		fpre = len==from-1 ? cur : fpre;	//ȷ��fpre�ڵ� 
		tpos = len==to+1 ? cur : tpos;	//ȷ��tpos�ڵ�
		cur = cur->next;
	} 
	if(from>to || from<1 || to>len){	//base case
		return head;
	}
	cur = fpre==NULL ? head : fpre->next;	//ȷ����ת�����Ƿ����ͷ 
	Node* next = NULL;
	Node* p = cur->next;
	cur->next = tpos;
	while(p != tpos){	//��ת���֣���tpos���� 
		next = p->next;
		p->next = cur;
		cur = p;
		p = next;
	}
	if(fpre != NULL){	//��ת���ֲ�����ͷ����ͷ���ñ� 
		fpre->next = cur;
		return head;
	}else{	//��ת���ְ���ͷ����ͷ��Ϊ��ת���ͷ 
		return cur;
	}
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
* ��ӡ���� 
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
	cout<<"ԭ����Ϊ---";
	print_list(head);
	head = reversePart(head, 1, 1);
	cout<<"����ת1~1��Ϊ---";
	print_list(head);
	
	head = createList(arr1, 1);
	cout<<"ԭ����Ϊ---";
	print_list(head);
	head = reversePart(head, 1, 1);
	cout<<"����ת1~1��Ϊ---";
	print_list(head);
	
	head = createList(arr2, 2);
	cout<<"ԭ����Ϊ---";
	print_list(head);
	head = reversePart(head, 1, 2);
	cout<<"����ת1~2��Ϊ---";
	print_list(head);
	
	head = createList(arr3, 3);
	cout<<"ԭ����Ϊ---";
	print_list(head);
	head = reversePart(head, 2, 3);
	cout<<"����ת2~3��Ϊ---";
	print_list(head);
	
	head = createList(arr3, 3);
	cout<<"ԭ����Ϊ---";
	print_list(head);
	head = reversePart(head, 1, 3);
	cout<<"����ת1~3��Ϊ---";
	print_list(head);
}

