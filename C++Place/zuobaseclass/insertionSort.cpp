#include "allh.h"
using namespace std;

/*
*插入排序代码
*从头开始的某个范围是有序的，范围外下一个数和前面的不断比较交换，插入到合适位置，保持+1范围有序，范围不断扩大 
*时间复杂度O(n2),额外空间复杂度O(1),稳定 
*/

/*
*插入法排序数组 
*从头开始的某个范围是有序的，范围外下一个数和前面的不断比较交换，插入到合适位置，保持+1范围有序，范围不断扩大 
*时间复杂度O(n2),额外空间复杂度O(1),稳定
*/
void insertion_sort(int* arr, int len){
	if(len <= 1){
		return;
	}
	for(int i=1; i<len; i++){
		for(int j=i-1; j>=0&&arr[j]>arr[j+1]; j--){
			array_ij_swap(arr, j, j+1);
		}
	}
} 

/*
*库函数sort排序 
*/
static void own_sort(int* arr, int len){
	sort(arr, arr+len);
}

void insertion_sort_main(){
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
		insertion_sort(arr1, len);
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
	insertion_sort(arr, len);
	print_int_array(arr, len);
}



