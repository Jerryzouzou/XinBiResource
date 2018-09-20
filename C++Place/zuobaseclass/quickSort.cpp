#include "allh.h"
using namespace std;
/*
*快速法排序代码
* 用 partition将数组的分成小于等于区和大于区，再采用递归的方式，小于区再继续 partition， 大于区继续partition，如此循环 
*时间复杂度O(n*logn),额外空间复杂度O(1),不稳定 
*/

void quick_sort(int* arr, int l, int r);
void partition(int* arr, int* p, int l, int j);

/*
*快速法排序数组 
* 用 partition将数组的分成小于等于区和大于区，再采用递归的方式，小于区再继续 partition， 大于区继续partition，如此循环 
*时间复杂度O(n*logn),额外空间复杂度O(1),不稳定 
*/
void quick_sort(int* arr, int len){
	if(len <= 1){
		return;
	}
	quick_sort(arr, 0, len-1);
}

void quick_sort(int* arr, int l, int r){
	if(l < r){
		int len = r - l + 1;
		int* p = new int[2](); 	//用于指向等于区第一个数和最后一个数位置 
		array_ij_swap(arr, (l+random(r-l+1)), r);	//随机取数组当前范围中某个数调换最后，避免奇异数组造成时间复杂度很大 
		partition(arr, p, l, r);
		quick_sort(arr, l, p[0]-1);		//小于区递归 
		quick_sort(arr, p[1]+1, r);		//大于区递归 
	}
}

/*
* 荷兰国旗问题，将排序成小于区等于区和大于区
* 左下标<最后一个数，小于区下一数字和左下标交换，小于区下标++右移，左下标++右移；
* 左下标>最后一个数，大于区前一数字和左下标交换，大于区下标--左移；
* 左下标==最后一个数，左下标++右移；
* 遍历完后大于区第一个数和最后一个数交换，返回等于区的第一个和最后一个位置 
*/
void partition(int* arr, int* p, int l, int r){
	int little = l - 1;
	int large = r;
	while(l < large){
		if(arr[l] < arr[r]){
			array_ij_swap(arr, ++little, l++);
		}else if(arr[l] > arr[r]){
			array_ij_swap(arr, --large, l);
		}else{
			l++;
		}
	}
	array_ij_swap(arr, large, r);
	p[0] = little+1;
	p[1] = large;
}

static void own_sort(int* arr, int len){
	sort(arr, arr+len);
}

void quick_sort_main(){
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
		quick_sort(arr1, len);
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
	quick_sort(arr, len);
	print_int_array(arr, len);
}

