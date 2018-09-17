#include "allh.h"

using namespace std;

template<typename T>
static int count(T& x){		//����x�ĳ��� 
    int s1 = sizeof(x);
    int s2 = sizeof(x[0]);
    int result = s1 / s2;
    return result;
}

/**
*int �����У�i��jλ�õ�ֵ�Ե� 
*/
void array_ij_swap(int* arr, int i, int j){
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

/**
*�������ֵmaxvalueΪ����������� 
*/
void generateRandomArray(int* arr, int len, int maxvalue){
	for(int i=0; i<len; i++){
		arr[i] = (int)(random(maxvalue) - random(maxvalue));
	}
}

/**
*����arrarr_from���鵽 arr_to���� 
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
*�ж�int�����Ƿ���ͬ 
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
*��ӡint���飬�Կո��� 
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





