#include "allh.h"
using namespace std;

/*
* 链表排成小于区等于区大于区 
* 一、先把链表的值放入数组中，使用数组的方式partition，再返回链表中 
* 二、用6个变量依次指向小于等于大于区的头尾，遍历第一遍找到各区的第一个数
* 遍历第二遍将剩下的数串入各自区，最后再将三个区串起来 
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
* 链表partition--先把每个节点遍历放入数组中，然后用数组方式partition
* 然后再把数组partition好的每个节点放回链表中 
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
* 定义6个指向大于等于小于区，遍历一遍将每个节点放入对应区，对应区放每个
* 数自身区域要串起来，最后再把三个区域串起来形成完整的链表 
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
			if(sH == NULL){		//还没填过的小于区的头尾指针都指向该节点 
				sH = head;
				sT = head;
			}else{
				sT->next = head;	//填入小于区尾 
				sT = head;	//小于区节点往下移，始终指向最后一个 
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
	//sT不为NULL说明该区不为空，sT的next指向等于区eH
	if(sT != NULL){
		sT->next = eH;
		eT = eT==NULL ? sT : eT;	//eT为NULL说明等于区为空，此时eT指向sT，重新指回小于区，为下面连向大于区 
	}
	
	if(eT != NULL){
		eT->next = bH; 
	}
	return sH!=NULL ? sH : eH!=NULL ? eH : bH;	//返回不为空的区的头 
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

void linkList_partition_main(){
	int arr[7] = {7, 9, 1, 8, 5, 2, 5};
	int p[2] = {0, 0}; 
	Node *head1 = createList(arr, 7);
	Node *head2 = createList(arr, 7);
	
	cout<<"原数组partition==";
	print_int_array(arr, 7);
	partition(arr, p, 0, 6, 5);
	cout<<"数组partition==";
	print_int_array(arr, 7);
	
	head1 = listPartition_useArray(head1, 5);
	cout<<"链表用Array-partition==";
	print_list(head1); 
	
	head2 = listPartition_use6Pointer(head2, 5);
	cout<<"链表用指针-partition==";
	print_list(head2);
}


