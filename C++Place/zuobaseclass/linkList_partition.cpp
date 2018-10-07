#include "allh.h"
using namespace std;

/*
* �����ų�С���������������� 
* һ���Ȱ������ֵ���������У�ʹ������ķ�ʽpartition���ٷ��������� 
* ������6����������ָ��С�ڵ��ڴ�������ͷβ��������һ���ҵ������ĵ�һ����
* �����ڶ��齫ʣ�µ������������������ٽ������������� 
*/

struct Node{
	int value;
	Node* next;
	Node(int a=0):value(a), next(NULL){};
};

void node_swap(vector<Node>& nodeArr, int a, int b);
void nodeArrPartition(vector<Node>& nodeArr, int pivot);
static void print_list(struct Node* head);

/*
* ����partition--�Ȱ�ÿ���ڵ�������������У�Ȼ�������鷽ʽpartition
* Ȼ���ٰ�����partition�õ�ÿ���ڵ�Ż������� 
*/
struct Node* listPartition_useArray(Node* head, int pivot){
	if(head == NULL){
		return head;
	}
	Node* cur = head;
	vector<Node> nodeArr;
	while(cur != NULL){
		nodeArr.push_back(*cur);
		cur = cur->next;
	}
	
	nodeArrPartition(nodeArr, pivot);
	cur = head;
	for(int i=0; i<nodeArr.size(); i++){
		cur->value = nodeArr[i].value;
		cur = cur->next;
	}
	return head;
}

void nodeArrPartition(vector<Node>& nodeArr, int pivot){
	int little = -1;
	int large = nodeArr.size();
	int index = 0;
	while(index < large){
		if(nodeArr[index].value < pivot){
			node_swap(nodeArr, ++little, index++);
		}else if(nodeArr[index].value > pivot){
			node_swap(nodeArr, --large, index);
		}else{
			index++;
		}
	}
}

void node_swap(vector<Node>& nodeArr, int a, int b){
	Node tmp = nodeArr[a];
	nodeArr[a] = nodeArr[b];
	nodeArr[b] = tmp;
}

/*
* ����6��ָ����ڵ���С����������һ�齫ÿ���ڵ�����Ӧ������Ӧ����ÿ��
* ����������Ҫ������������ٰ��������������γ����������� 
*/
struct Node* listPartition_use6Pointer(Node* head, int pivot){
	Node* sH = NULL; // small head
	Node* sT = NULL; // small tail
	Node* eH = NULL; // equal head
	Node* eT = NULL; // equal tail
	Node* bH = NULL; // big head
	Node* bT = NULL; // big tail
	Node* next = NULL; // save next node
	while(head != NULL){
		next = head->next;
		head->next = NULL;
		if(head->value < pivot){
			if(sH == NULL){		//��û�����С������ͷβָ�붼ָ��ýڵ� 
				sH = head;
				sT = head;
			}else{
				sT->next = head;	//����С����β 
				sT = head;	//С�����ڵ������ƣ�ʼ��ָ�����һ�� 
			}
		}else if(head->value == pivot){
			if(eH == NULL){
				eH = head;
				eT = head;
			}else{
				eT->next = head;
				eT = head;
			}
		}else{
			if(bH == NULL){
				bH = head;
				bT = head;
			}else{
				bT->next = head;
				bT = head;
			}
		}
		head = next;
	}
	//sT��ΪNULL˵��������Ϊ�գ�sT��nextָ�������eH
	if(sT != NULL){
		sT->next = eH;
		eT = eT==NULL ? sT : eT;	//eTΪNULL˵��������Ϊ�գ���ʱeTָ��sT������ָ��С������Ϊ������������� 
	}
	
	if(eT != NULL){
		eT->next = bH; 
	}
	return sH!=NULL ? sH : eH!=NULL ? eH : bH;	//���ز�Ϊ�յ�����ͷ 
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

void linkList_partition_main(){
	int arr[7] = {7, 9, 1, 8, 5, 2, 5};
	int p[2] = {0, 0}; 
	Node *head1 = createList(arr, 7);
	Node *head2 = createList(arr, 7);
	
	cout<<"ԭ����partition==";
	print_int_array(arr, 7);
	partition(arr, p, 0, 6, 5);
	cout<<"����partition==";
	print_int_array(arr, 7);
	
	head1 = listPartition_useArray(head1, 5);
	cout<<"������Array-partition==";
	print_list(head1); 
	
	head2 = listPartition_use6Pointer(head2, 5);
	cout<<"������ָ��-partition==";
	print_list(head2);
}


