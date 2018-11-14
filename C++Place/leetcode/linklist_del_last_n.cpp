#include "allh.h"

using namespace std;

struct Node{
	int value;
	Node* next;
	Node(int a=0):value(a), next(NULL){};
};

struct Node* removeNthFromEnd(Node* head, int n) {
    Node* list = new Node(0);
    list->next = head;
    Node* a = list;
    Node* b = list;

    for (int i = 0; i < n + 1; ++i){
        b = b->next;
    }

    while (b != NULL){
        a = a->next;
        b = b->next;
    }
    a->next = a->next->next;
    return list->next;
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

void linkList_del_last_n_main(){
	int arr[6] = {1, 2, 3, 4, 5, 6};
	Node *head = createList(arr, 6);
	cout<<"******原始单向链表*******";
	print_list(head);
	head = removeNthFromEnd(head,3);
	cout<<"******删除倒数第3个节点后链表*******";
	print_list(head);
}


