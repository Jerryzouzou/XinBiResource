#include "allh.h"
using namespace std;

/*
* 查找局部最小值位置--二分法
* 局部最小值定义：数组数要比两边的数都小，如果是头尾位置数比一边小。
* 通过二分法查找，mid是局部最小则直接返回，否则重新构建left/right边界去再次二分 
*/

static int getLessIndex(int* arr, int len){
	if(len < 1){
		return -1;
	}
	if(len==1 || arr[0] < arr[1]){
		return 0;
	}
	if(arr[len-1]<arr[len-2]){
		return len-1;
	}
	int left=1, right=len-2, mid=0;
	while(left < right){
		mid = (left+right)/2;
		if(arr[mid] > arr[mid+1]){
			left = mid+1;
		}else if(arr[mid] > arr[mid-1]){
			right = mid - 1;
		}else{
			return mid;
		}
	}
	return left;
} 


void findOneLessValueIndex_main(){
	int arr[7] = {6, 5, 3, 4, 6, 7, 8};
	int index = getLessIndex(arr, 7);
	cout<<"局部最小值--原数组---";
	print_int_array(arr, 7);
	cout<<"局部最小值--位置index=="<<index<<"--arr[index]=="<<arr[index]<<endl; 
}

