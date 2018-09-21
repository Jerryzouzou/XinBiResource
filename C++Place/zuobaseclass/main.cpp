#include <iostream>
#include "allh.h"

using namespace std;


int main(int argc, char** argv) {
	
	cout<<"------------冒泡法排序------------" <<endl;
	bubble_main();		//冒泡法排序 
	cout<<"------------选择排序------------" <<endl;
	select_sort_main();	//选择法排序 
	cout<<"------------插入法排序------------" <<endl;
	insertion_sort_main();	//插入法排序 
	cout<<"------------归并法排序------------" <<endl;
	merge_sort_main();		//归并法排序 
	cout<<"------------快速排序法------------" <<endl;
	quick_sort_main();		//快速排序法 
	cout<<"------------桶排序--0~200 ------------" <<endl;
	bucket_sort_main();		//桶排序--0~200 
	cout<<"------------二叉树遍历------------" <<endl;
	pre_in_pos_2tree_traversal_main();		//二叉树遍历 
	cout<<"------------小米笔试-DP------------" <<endl;
	xiaomi_main();		//动态规划--不同数组不重复能否组合成指定数 
	
	return 0;
}
