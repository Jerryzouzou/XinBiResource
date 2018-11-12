#include "allh.h"

using namespace std;


int main(int argc, char** argv) {
	
	cout<<"------------仅用递归逆序栈------------" <<endl;
	stack_reverse_main();
	cout<<"------------栈从顶到底从大到小排序------------" <<endl;
	sortStackByStack_main();	//栈从顶到底从大到小排序--只用一个辅助栈
	cout<<"------------数组生成窗口最大值数组------------" <<endl;
	array_window_getMax_main();		//数组生成窗口最大值数组 
	cout<<"------------数组生成MaxTree------------" <<endl;
	maxTree_main();
	cout<<"------------最大子矩阵的大小------------" <<endl;
	maxRecSize_main();
	cout<<"------------数组子数组max-min<=num的子数组个数------------" <<endl;
	allLessNumSubArray_main();
	cout<<"------------单向链表双向链表删除倒数第K个节点------------" <<endl;
	removeLastKthNode_main();
	cout<<"------------删除链表中间节点和a/b处节点------------" <<endl;
	remove_mid_ab_Node_main();
	cout<<"------------反转部分链表------------" <<endl;
	linkList_reversePart_main();
	/*cout<<"------------冒泡法排序------------" <<endl;
	bubble_main();		//冒泡法排序 */
	
	
	return 0;
}
