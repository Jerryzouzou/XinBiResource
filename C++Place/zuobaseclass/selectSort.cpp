#include "allh.h"
using namespace std;

/*
*选择排序代码
*每次循环找到当前范围最小点索引，然后把最小和头交换，不断缩小范围
*时间复杂度O(n2),额外空间复杂度O(1),不稳定 
*/

/*
*选择法排序数组 
*每次循环找到当前范围最小点索引，然后把最小和头交换，不断缩小范围
*时间复杂度O(n2),额外空间复杂度O(1),不稳定 
*/
void select_sort(int* arr, int len){
	if(len <= 1){
		return;
	}
	for(int i=0; i<len; i++){
		int minIndex = i;
		for(int j=i+1; j<len; j++){
			minIndex = arr[minIndex]<arr[j] ? minIndex : j;
		}
		if(i != minIndex) array_ij_swap(arr, i, minIndex);
	} 
} 

/*
*库函数sort排序 
*/
static void own_sort(int* arr, int len){
	sort(arr, arr+len);
}

void select_sort_main(){
	string strRes = "";
	int testTime = 10;
	int maxSize = 100;
	int maxValue = 100;
	bool succeed = true;
	for (int i = 0; i < testTime; i++) {
		int len = random(maxSize);
		int* arr1 = new int[len];
		int* arr2 = new int[len];
		generateRandomArray(arr1, len, maxValue);
		copy_array(arr1, arr2, len, len);
		select_sort(arr1, len);
		own_sort(arr2, len);
		if (!isEqual_intArr(arr1, arr2, len, len)) {
			succeed = false;
			break;
		}
	}
	strRes=succeed ? "Nice!" : "Fucking fucked!";
	cout<<strRes<<endl;

	int len = random(maxSize);
	int* arr = new int[len];
	generateRandomArray(arr, len, maxValue);
	print_int_array(arr, len);
	select_sort(arr, len);
	print_int_array(arr, len);
}



