#include "allh.h"
using namespace std;

/*
* ���ƴ������ָ�������
* ����һ��ͨ��haspmap��ԭ����ÿ���ڵ�key-value����haspmap�У�Ȼ����ͨ��ԭ�����
* ���ӹ�ϵȥŪ�ÿ����ڵ�Ĺ�ϵ
* ��������������ÿ���ڵ㶼���뵽ԭ�ڵ���a->a'->b...������Ȼ��ÿ��������a,a'��
* ͨ��a�ҵ�a��randָ��ڵ�i��Ȼ��a'��rand��ָ��i����һ����i'���������ԭ����
* �Ϳ���������---�ռ临�Ӷ�O(1) 
*/

struct Node{
	int value;
	Node* next;
	Node* rand;
	Node(int a=0):value(a), next(NULL), rand(NULL){};
};

/*
* ������ÿ���ڵ㶼���뵽ԭ�ڵ���a->a'->b...������Ȼ��ÿ��������a,a'��
* ͨ��a�ҵ�a��randָ��ڵ�i��Ȼ��a'��rand��ָ��i����һ����i'���������ԭ����
* �Ϳ���������
*/
static struct Node* copyListWithRand(Node* head){
	if(head == NULL){
		return NULL;
	}
	Node* cur = head;
	Node* next = NULL;
	while(cur != NULL){
		Node* tmp = (struct Node*)malloc(sizeof(Node));
		tmp->value = cur->next;
		
	}
	
} 

