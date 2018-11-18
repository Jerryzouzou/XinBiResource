#include "allh.h"
using namespace std;

/*
* 二叉树序列化和反序列化---二叉树转化为字符串序列化--和通过字符串构造出二叉树
* 递归方式：前序遍历方式序列化，将打印时改为序列化字符串有值是为"v_"，无值时为"#_"
* 反序列化同理。
*  
*/

struct Node{
	int value;
	Node* left;
	Node* right;
	Node(int a=0):value(a), left(NULL), right(NULL){};
};

