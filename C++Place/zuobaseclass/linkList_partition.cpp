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
	Node *head = createList(arr, 7);
}


