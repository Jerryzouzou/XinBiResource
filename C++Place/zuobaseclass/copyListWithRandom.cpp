#include "allh.h"
using namespace std;

/*
* 复制带有随机指针的链表
* 方法一、通过haspmap将原链表每个节点key-value放入haspmap中，然后再通过原链表的
* 连接关系去弄好拷贝节点的关系
* 方法二、拷贝的每个节点都插入到原节点上a->a'->b...这样，然后每次拿两个a,a'，
* 通过a找到a的rand指向节点i，然后a'的rand就指向i的下一个即i'，最后分离回原链表
* 和拷贝的链表 
*/

struct Node{
	int value;
	Node* next;
	Node* rand;
	Node(int a=0):value(a), next(NULL), rand(NULL){};
};

