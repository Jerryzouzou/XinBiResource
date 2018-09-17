#include "allh.h"
using namespace std;

/*
*Ã°ÅİÅÅĞò´úÂë
*/

/*
*Ã°Åİ·¨ÅÅĞòÊı×é 
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
*¿âº¯ÊısortÅÅĞò 
*/
void own_sort(int* arr, int len){
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



