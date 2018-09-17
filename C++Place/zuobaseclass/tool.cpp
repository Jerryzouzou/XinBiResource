#include "allh.h"

using namespace std;

template<typename T>
static int count(T& x){		//计算x的长度 
    int s1 = sizeof(x);
    int s2 = sizeof(x[0]);
    int result = s1 / s2;
    return result;
}

/**
*int 数组中，i，j位置的值对调 
*/
void array_ij_swap(int* arr, int i, int j){
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

/**
*产生最大值maxvalue为的随机数数组 
*/
void generateRandomArray(int* arr, int len, int maxvalue){
	for(int i=0; i<len; i++){
		arr[i] = (int)(random(maxvalue) - random(maxvalue));
	}
}

/**
*拷贝arrarr_from数组到 arr_to数组 
*/
void copy_array(int* arr_from, int* arr_to, int len1, int len2){
	if(len1==0 || len2==0 ||(len1!=len2)){
		return;
	}
	for(int i=0; i<len1; i++){
		arr_to[i] = arr_from[i];
	}
} 

/**
*判断int数组是否相同 
*/
bool isEqual_intArr(int *arr1, int* arr2, int len1, int len2){
	if((len1==0 && len2!=0)||(len1!=0 && len2==0)||(len1!=len2)){
		return false;
	}
	if(len1==0 && len2==0){
		return true;
	}
	for(int i=0; i<len1; i++){
		if(arr1[i] != arr2[i]){
			return false;
		}
	}
	
	return true;
}

/**
*打印int数组，以空格间隔 
*/
void print_int_array(int* arr, int len){
	if(len == 0){
		return;
	}
	for(int i=0; i<len; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}





