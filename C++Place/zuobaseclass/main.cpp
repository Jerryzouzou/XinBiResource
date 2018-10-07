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
	cout<<"------------堆排序法------------" <<endl;
	heap_sort_main();		//堆排序法 
	cout<<"------------桶排序--0~200 ------------" <<endl;
	bucket_sort_main();		//桶排序--0~200 
	cout<<"------------二叉树遍历------------" <<endl;
	pre_in_pos_2tree_traversal_main();		//二叉树遍历 
	cout<<"------------小米笔试-DP------------" <<endl;
	xiaomi_main();		//动态规划--不同数组不重复能否组合成指定数 
	cout<<"------------获取走的方法数-DP------" <<endl;
	dp_roadWays_main();	//动态规划--范围1~n，当前位置p，走k步，能走到m的方法数； 
	cout<<"------------数组最大子序和-DP------" <<endl;
	maxsum_subarr_main();	//动态规划--数组内最大和的连续子数组的和 
	cout<<"------------异或得到出现奇数次的数----" <<endl;
	eor_getOddNum_main();	//异或得到出现奇数次的数 
	cout<<"------------系统sort的各种排序----" <<endl;
	comparator_main();		//系统sort的各种排序 
	cout<<"------------堆方式获取数组中位数-------" <<endl;
	medianNUm_heap_main();		//用大小跟堆方式获取中位数 
	cout<<"------------自定义排序的priority_queue------" <<endl;
	priority_queue_comparator_main();	//自定义排序的priority_queue 
	cout<<"------------数组内数字相差最大值-桶------" <<endl;
	maxGrap_main();		//不用排序用桶得到数组内数字相差最大值 
	cout<<"------------数组实现栈stack-----------" <<endl;
	array2stack_main();	//用数组实现栈stack 
	cout<<"------------数组实现栈queue-----------" <<endl;
	array2queue_main();	//用数组实现栈queue 
	cout<<"------------可以获取最小数的栈-----------" <<endl;
	getMin_stack_main();	//实现一个可以获取最小数的栈 
	cout<<"------------之型打印二维数组-----------" <<endl;
	printMatrixZigZag_main();	//之型打印二维数组 
	cout<<"------------正方形数组旋转-----------" <<endl;
	rotateMatrix_main();		//正方形数组旋转 
	cout<<"------------转圈打印数组-----------" <<endl;
	printMatrixSpiralOrdar_main();	//转圈打印数组 
	cout<<"------------查找数组最小k个数-----------" <<endl;
	find_k_littleNUm_main();	//查找数组最小k个数 
	cout<<"------------打印两个有序链表公共部分-----------" <<endl;
	linkList_printCommonPart_main();	//打印两个有序链表公共部分 
	cout<<"------------有序二维数组找某数-----------" <<endl;
	findNumInSortedMatrix_main();	//有序二维数组找某数 
	cout<<"------------链表是否是回文结构-----------" <<endl;
	linkList_isPalindromeList_main();	//链表是否是回文结构 
	cout<<"------------链表partition-----------" <<endl;
	linkList_partition_main();	//链表partition 
	
	return 0;
}
