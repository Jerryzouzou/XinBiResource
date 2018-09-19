#include "allh.h"
using namespace std;
/*
*�鲢���������
*���õݹ�ķ�ʽ�����Ͻ�����ֳ����������֣��ݹ�ȥ�������������ָ��������֮���ٲ��Ϻ���һ�� 
*ʱ�临�Ӷ�O(n*logn),����ռ临�Ӷ�O(n),���ȶ� 
*/

void quick_sort(int* arr, int l, int r);
void partition(int* arr, int* p, int l, int j);

/*
*�鲢���������� 
*���õݹ�ķ�ʽ�����Ͻ�����ֳ����������֣��ݹ�ȥ�������������ָ��������֮���ٲ��Ϻ���һ�� 
*ʱ�临�Ӷ�O(n*logn),����ռ临�Ӷ�O(n),���ȶ�
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
		int* p = new int[2](); 	//����ָ���������һ�����ʹ�������һ����λ�� 
		array_ij_swap(arr, (l+random(r-l+1)), r);
		partition(arr, p, l, r);
		quick_sort(arr, l, p[0]-1);
		quick_sort(arr, p[1], r);
	}
}

void partition(int* arr, int* p, int l, int r){
	int little = l - 1;
	int large = r;
	while(l < large){
		//if
	}
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

