#include "allh.h"
using namespace std;

/*
*ѡ���������
*ÿ��ѭ���ҵ���ǰ��Χ��С��������Ȼ�����С��ͷ������������С��Χ
*ʱ�临�Ӷ�O(n2),����ռ临�Ӷ�O(1),���ȶ� 
*/

/*
*ѡ���������� 
*ÿ��ѭ���ҵ���ǰ��Χ��С��������Ȼ�����С��ͷ������������С��Χ
*ʱ�临�Ӷ�O(n2),����ռ临�Ӷ�O(1),���ȶ� 
*/
void select_sort(int* arr, int len){
	if(len <= 1){
		return;
	}
	for(int i=0; i<len; i++){
		int minIndex = i;
		for(int j=i+1; j<len; j++){
			minIndex = arr[minIndex]<arr[j] ? minIndex : j;
		}
		if(i != minIndex) array_ij_swap(arr, i, minIndex);
	} 
} 

/*
*�⺯��sort���� 
*/
static void own_sort(int* arr, int len){
	sort(arr, arr+len);
}

void select_sort_main(){
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
		select_sort(arr1, len);
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
	select_sort(arr, len);
	print_int_array(arr, len);
}



