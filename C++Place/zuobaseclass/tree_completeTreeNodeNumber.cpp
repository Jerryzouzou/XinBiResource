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

static int mostLeftLevel(Node* node, int level);
static int bs(Node* node, int l, int h);

static int nodeNum(Node* head){
	if(head == NULL){
		return 0;
	}
	return bs(head, 1, mostLeftLevel(head, 1)); 
}

/*
* 递归计算以node为头节点的二叉树的节点个数
* l:当前第l层;
* h:整二叉树的深度 
*/
static int bs(Node* node, int l, int h){
	if(l == h){
		return 1;
	}
	if(mostLeftLevel(node->right, l+1) == h){	//右子树的最左到达最深 
		//此时左子树节点个数是确定的为2^(h-l)-1，加上当前头结点，所以 
		//为(1<<(h-l))，然后再加上右子树的继续递归求解 
		return ((1<<(h-l)) + bs(node->right, l+1, h));
	}else{
		//此时右子树是少一层的满二叉树，节点个数是确定的为2^(h-l-1)-1,加上当前头结点，所以 
		//为(1<<(h-l-1))，然后再加上左子树的继续递归求解  
		return ((1<<(h-l-1)) + bs(node->left, l+1, h));
	}
}

/*
* 返回一直左孩子的高度 
*/ 
static int mostLeftLevel(Node* node, int level){
	while(node != NULL){
		level++;
		node = node->left;
	}
	return level - 1;
}

void tree_completeTreeNodeNumber_main(){
	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->left = new Node(4);
	head->left->right = new Node(5);
	head->right->left = new Node(6);
	cout<<"node number is == "<<nodeNum(head)<<endl;
}

