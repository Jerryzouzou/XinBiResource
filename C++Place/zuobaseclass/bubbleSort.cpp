#include "allh.h"
using namespace std;

/*
*冒泡排序代码
*每次循环从头到尾不断比较，大的换到后面，每次循环最大的在当前范围最后，不断缩小范围
*时间复杂度O(n2),额外空间复杂度O(1),稳定 
*/

/*
*冒泡法排序数组 
*每次循环从头到尾不断比较，大的换到后面，每次循环最大的在当前范围最后，不断缩小范围
*时间复杂度O(n2),额外空间复杂度O(1),稳定 
*/
void bubble_sort(int* arr, int len){
	if(len <= 1){
		return;
	}
	for(int j=len-1; j>0; j--){
		for(int i=0; i<j; i++){
			if(arr[i] > arr[i+1]){
				array_ij_swap(arr, i, i+1);
			}
		}
	}
} 

/*
*库函数sort排序 
*/
static void own_sort(int* arr, int len){
	sort(arr, arr+len);
}

void bubble_main(){
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
		bubble_sort(arr1, len);
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
	bubble_sort(arr, len);
	print_int_array(arr, len);
}



