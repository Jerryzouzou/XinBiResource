#include "allh.h"
using namespace std;

/*
* 折纸问题：竖着的纸，每次从下往上折，第一次出现一个下折痕，后面每次都是上一次
* 折痕两边新增下上折痕，那么折N次就是高度为N的完美二叉树，每个节点的左孩子是下折痕 
* 右孩子是上折痕。从上往下打印折痕就是二叉树的中序遍历 
* 可以不建立二叉树，直接用中序遍历递归方式打印 
*/

//value：1代表下折痕 ，2代表上折痕 
struct Node{
	int value;
	Node* left;
	Node* right;
	Node(int a=0):value(a), left(NULL), right(NULL){};
};

/*
* i:打印到第i层
* N:二叉树深度
* down:打印down还是up 
*/
void printProcess(int i, int N, bool down){
	if(i > N){
		return;
	} 
	printProcess(i+1, N, true);
	if(down){
		cout<<"down"<<endl;
	}else{
		cout<<"up"<<endl;
	}
	printProcess(i+1, N, false);
}

void printAllFolds(int N){
	printProcess(1, N, true);
}

void tree_paperFolding_main(){
	int N = 4;
	printAllFolds(N);
}

