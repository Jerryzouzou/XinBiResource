#include "allh.h"
using namespace std;

/*
*�����������
*��ͷ��ʼ��ĳ����Χ������ģ���Χ����һ������ǰ��Ĳ��ϱȽϽ��������뵽����λ�ã�����+1��Χ���򣬷�Χ�������� 
*ʱ�临�Ӷ�O(n2),����ռ临�Ӷ�O(1),�ȶ� 
*/

/*
*���뷨�������� 
*��ͷ��ʼ��ĳ����Χ������ģ���Χ����һ������ǰ��Ĳ��ϱȽϽ��������뵽����λ�ã�����+1��Χ���򣬷�Χ�������� 
*ʱ�临�Ӷ�O(n2),����ռ临�Ӷ�O(1),�ȶ�
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
*�⺯��sort���� 
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



