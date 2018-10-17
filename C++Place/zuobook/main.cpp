#include "allh.h"

using namespace std;


int main(int argc, char** argv) {
	
	cout<<"------------仅用递归逆序栈------------" <<endl;
	stack_reverse_main();
	cout<<"------------栈从顶到底从大到小排序------------" <<endl;
	sortStackByStack_main();	//栈从顶到底从大到小排序--只用一个辅助栈 
	/*cout<<"------------冒泡法排序------------" <<endl;
	bubble_main();		//冒泡法排序 */
	
	
	return 0;
}
