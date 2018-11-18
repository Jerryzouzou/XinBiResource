#include "allh.h"
using namespace std;

/*
* 完全二叉树节点个数：二叉树高度N，如果头节点的右子树的最左到达了最深，说明左子树
* 是满二叉树，左子树的节点个数是2^(N-1)-1; 如果头节点的右子树的最左少一层说明右子树是
* 满二叉树，右子树的节点个数是2^(N-1-1)-1;两种情况的另一半继续递归 
*/ 
 
struct Node{
	int value;
	Node* left;
	Node* right;
	Node(int a=0):value(a), left(NULL), right(NULL){};
};

