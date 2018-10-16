#include "allh.h"
using namespace std;

/*
* 小数和问题：数组每个数它前面数比它小的数的和
* 可以用二分归并的方法，在merge的时候确定每个数在当前范围比后面数小的时候
* 即可确定它小的频次去求和。 
*/
static int merge_sort(int* arr, int l, int r);
static int merge_data(int* arr, int l, int mid, int r);

int small_sum(int* arr, int len){
	if(len <= 1){
		return 0;
	}
	return merge_sort(arr, 0, len-1);
}

/*
* 归并排序方法，递归方式merge数组的时候确定左半部分相对右半部分小数和 
*/
static int merge_sort(int* arr, int l, int r){
	if(l == r){
		return 0;
	}
	int mid = l + ((r-l)>>1);
	return merge_sort(arr, l, mid)+merge_sort(arr, mid+1, r)+merge_data(arr, l, mid, r);
}

/*
*通过帮助数组，和两个下标指引，不断将小的数往帮助数组填，排序好之后再拷贝回原来数组 
* 左半部分小数和前面递归的时候已经求了，所以只需要计算左半部分相对于右半部分的小数和 
*/
static int merge_data(int* arr, int l, int mid, int r){
	int len = r-l+1, i=0;
	int res = 0;
	int p1 = l;
	int p2 = mid+1;
	int* help = new int[len]();
	while(p1<=mid && p2<=r){
		res += arr[p1]<arr[p2] ? (r-p2+1)*arr[p1] : 0;	//arr[p1]小的话，左右部分各自是排序好的，所以会有(r-p2+1)次小 
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
	return res;
}

static int comparator(int* arr, int len){
	if(len <= 1){
		return 0;
	}
	int res=0;
	for(int i=1; i<len; i++){
		for(int j=0; j<i; j++){
			res += arr[j]<arr[i] ? arr[j] : 0;
		}
	}
	return res;
}

void smallSum_main(){
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
		if(small_sum(arr1, len) != comparator(arr2, len)){
			succeed = false;
			print_int_array(arr1, len);
			print_int_array(arr2, len);
			break;
		}
	}
	strRes=succeed ? "Nice!" : "Fucking fucked!";
	cout<<strRes<<endl;
}

