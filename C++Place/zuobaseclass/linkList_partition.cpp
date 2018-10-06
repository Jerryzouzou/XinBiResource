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

struct Node* listPartition_useArray(Node* head, int pivot){
	if(head == NULL){
		return head;
	}
	Node* cur = head;
	int i=0;
	vector<Node> nodeArr;
	while(cur != NULL){
		nodeArr.push_back(*cur);
		cur = cur->next;
	}
	
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
	Node *head = createList(arr, 7);
}


