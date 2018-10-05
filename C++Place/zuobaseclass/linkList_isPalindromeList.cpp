#include "allh.h"
using namespace std;

/*
* �����ǻ��Ľṹ 
* һ���������ֵȫ�������Ұ벿��ѹ��ջ�У�Ȼ�������ͷ��ʼ�͵�����ջ���Ƚ��Ƿ���� 
* �����ҵ��м�λ�ã����Ұ벿������ת��Ȼ���������м����αȽ� 
*/

struct Node{
	int value;
	Node* next;
	Node(int a=0):value(a), next(NULL){};
};

//������ÿ���ڵ�ѹ��ջ�У�Ȼ�������ͷ��ʼ�͵�����ջ���Ƚ�ֵ�Ƿ����--����ռ�O(N) 
bool isPalindromeList_useStack(Node* head){
	struct Node *p = head;
	stack<Node> helpStack;
	while(p != NULL){
		helpStack.push(*p);
		p = p->next;
	}
	while(head != NULL){
		if(head->value != helpStack.top().value){
			//helpStack.pop();
			return false;
		}
		helpStack.pop();
		head = head->next;
	}
	
	return true;
}

//�������Ұ벿��ÿ���ڵ�ѹ��ջ�У�Ȼ�������ͷ��ʼ�͵�����ջ�����൱����ߺ��ұ߱Ƚϣ��Ƚ�ֵ�Ƿ����--����ռ�O(N/2)
bool isPalindromeList_useHalfStack(Node* head){
	if(head == NULL || head->next==NULL){
		return true;
	}
	Node* right = head->next;	//�ӵڶ����ڵ㿪ʼ 
	Node* cur = head;
	while(cur->next!=NULL && cur->next->next!=NULL){
		right = right->next;
		cur = cur->next->next;		//curһ����������rightһ����һ�������������ʱ��right�����Ұ벿�ֵĵ�һ�� 
	}
	stack<Node> rightStack;
	while(right != NULL){	//���Ұ벿��ѹ��ջ 
		rightStack.push(*right);
		right = right->next;
	}
	while(!rightStack.empty()){		//��ջ�����ұߵĺ���߱Ƚϣ��������Ļ��м��Ǹ����ù� 
		if(head->value != rightStack.top().value){
			//helpStack.pop();
			return false;
		}
		rightStack.pop();
		head = head->next;
	}
	return true;
}

bool  isPalindromeList_to2list(Node* head){
	
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

void linkList_isPalindromeList_main(){
	int arr1[2] = {1, 2};
	int arr2[2] = {1, 1};
	int arr3[3] = {1, 2, 3};
	int arr4[3] = {1, 2, 1};
	int arr5[4] = {1, 2, 3, 1};
	int arr6[5] = {1, 2, 2, 1};
	int arr7[5] = {1, 2, 3, 2, 1};
//	Node *head1 = (struct Node*)malloc(sizeof(Node));
//	Node *head2 = (struct Node*)malloc(sizeof(Node));
//	head1 = createList(arr1, 4);
//	head2 = createList(arr2, 5);
//	cout<<"����1===";
//	print_list(head1);
//	cout<<"����2===";
//	print_list(head2);
//	printListCommonPart(*head1, *head2);
	Node *head1 = NULL;
	cout<<"����Ϊ";
	print_list(head1);
	cout<<"ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useStack(head1)<<endl;
	cout<<"��ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useHalfStack(head1)<<endl;
	
	cout<<"======================="<<endl;
	
	Node *head2=new Node(1); //(struct Node*)malloc(sizeof(Node));
	cout<<"����Ϊ";
	print_list(head2);
	cout<<"ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useStack(head2)<<endl;
	cout<<"��ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useHalfStack(head2)<<endl;
	
	cout<<"======================="<<endl;
	
	Node *head3 = createList(arr1, 2);
	cout<<"����Ϊ";
	print_list(head3);
	cout<<"ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useStack(head3)<<endl;
	cout<<"��ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useHalfStack(head3)<<endl;
	
	cout<<"======================="<<endl;
	
	Node *head4 = createList(arr2, 2);
	cout<<"����Ϊ";
	print_list(head4);
	cout<<"ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useStack(head4)<<endl;
	cout<<"��ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useHalfStack(head4)<<endl;
	
	cout<<"======================="<<endl;
	
	Node *head5 = createList(arr3, 3);
	cout<<"����Ϊ";
	print_list(head5);
	cout<<"ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useStack(head5)<<endl;
	cout<<"��ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useHalfStack(head5)<<endl;
	
	cout<<"======================="<<endl;
	
	Node *head6 = createList(arr4, 3);
	cout<<"����Ϊ";
	print_list(head6);
	cout<<"ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useStack(head6)<<endl;
	cout<<"��ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useHalfStack(head6)<<endl;
	
	cout<<"======================="<<endl;
	
	Node *head7 = createList(arr5, 4);
	cout<<"����Ϊ";
	print_list(head7);
	cout<<"ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useStack(head7)<<endl;
	cout<<"��ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useHalfStack(head7)<<endl;
	
	cout<<"======================="<<endl;
	
	Node *head8 = createList(arr6, 4);
	cout<<"����Ϊ";
	print_list(head8);
	cout<<"ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useStack(head8)<<endl;
	cout<<"��ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useHalfStack(head8)<<endl;
	
	cout<<"======================="<<endl;
	
	Node *head9 = createList(arr7, 5);
	cout<<"����Ϊ";
	print_list(head9);
	cout<<"ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useStack(head9)<<endl;
	cout<<"��ջ��ʽ--�����Ƿ��ǻ��Ľṹ��"<<isPalindromeList_useHalfStack(head9)<<endl;
	
	cout<<"======================="<<endl;
}


