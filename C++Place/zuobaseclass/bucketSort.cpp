#include "allh.h"
using namespace std;

/*
*桶排序代码
*0~200值范围内速度比较快 ,直接对每个数计数出现多少次，然后根据次数重写数组 
*时间复杂度O(n),额外空间复杂度O(n),不稳定 
*/

/*
*桶法排序数组 
*0~200值范围内速度比较快 ,直接对每个数计数出现多少次，然后根据次数重写数组 
*时间复杂度O(n),额外空间复杂度O(n),不稳定  
*/
void bucket_sort(int* arr, int len){
	if(len <= 1){
		return;
	}
	int max = -1;
	for(int i=0; i<len; i++){
		max = max > arr[i] ? max : arr[i];
	}
	if(max <= 0) return;
	int* bucket = new int[max+1]();		//要先全部初始化为0 
	for(int i=0; i<len; i++){
		bucket[arr[i]]++;
	}
	int i=0;
	//cout<<"--"<<endl;
	for(int j=0; j<max+1; j++){
		while(bucket[j]-- > 0){
			arr[i++] = j;
			//cout<<"max=="<<max<<"--i=="<<i<<"--j=="<<j<<"--len=="<<len<<endl;
		}
	}
} 

/*
*库函数sort排序 
*/
static void own_sort(int* arr, int len){
	sort(arr, arr+len);
}

/*
*
*/
void getRandomArray(int* arr, int len, int maxvalue){
	for(int i=0; i<len; i++){
		int tmp = (int)(random(maxvalue) - random(maxvalue));
		if(tmp >= 0){
			arr[i] = tmp;
		}else{
			i--;
		}
	}
}

void bucket_sort_main(){
	string strRes = "";
	int testTime = 10;
	int maxSize = 100;
	int maxValue = 150;
	bool succeed = true;
	for (int i = 0; i < testTime; i++) {
		int len = random(maxSize);
		int* arr1 = new int[len];
		int* arr2 = new int[len];
		getRandomArray(arr1, len, maxValue);
		copy_array(arr1, arr2, len, len);
		bucket_sort(arr1, len);
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
	getRandomArray(arr, len, maxValue);
	print_int_array(arr, len);
	bucket_sort(arr, len);
	print_int_array(arr, len);
}



