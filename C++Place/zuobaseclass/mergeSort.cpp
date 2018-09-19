#include "allh.h"
using namespace std;
/*
*归并法排序代码
*采用递归的方式，不断将数组分成左右两部分，递归去排序，左右两部分各自排序好之后，再不断合在一起 
*时间复杂度O(n*logn),额外空间复杂度O(n),不稳定 
*/

void merge_sort(int* arr, int l, int r);
void merge_data(int* arr, int l, int mid, int r);

/*
*归并法排序数组 
*采用递归的方式，不断将数组分成左右两部分，递归去排序，左右两部分各自排序好之后，再不断合在一起 
*时间复杂度O(n*logn),额外空间复杂度O(n),不稳定
*/
void merge_sort(int* arr, int len){
	if(len <= 1){
		return;
	}
	merge_sort(arr, 0, len-1);
}

void merge_sort(int* arr, int l, int r){
	if(l == r){
		return;
	}
	int mid = l + ((r-l)>>1);
	merge_sort(arr, l, mid);		//递归排序左边 
	merge_sort(arr, mid+1, r);		//递归排序右边 
	merge_data(arr, l, mid, r);		//左右部分排序好之后合并在一起且是排序好的 
}

/*
*通过帮助数组，和两个下标指引，不断将小的数往帮助数组填，排序好之后再拷贝回原来数组 
*/
void merge_data(int* arr, int l, int mid, int r){
	int len = r-l+1, i=0;
	int p1 = l;
	int p2 = mid+1;
	int* help = new int[len]();
	while(p1<=mid && p2<=r){
		help[i++] = arr[p1]<arr[p2] ? arr[p1++] : arr[p2++];
	}
	while(p1<=mid){		//左边的还有剩 
		help[i++] = arr[p1++];
	}
	while(p2<=r){		//右边的还有剩 
		help[i++] = arr[p2++];
	}
	for(int j=0; j<len; j++){
		arr[l+j] = help[j];
	}
}

static void own_sort(int* arr, int len){
	sort(arr, arr+len);
}

void merge_sort_main(){
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
		merge_sort(arr1, len);
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
	merge_sort(arr, len);
	print_int_array(arr, len);
}

