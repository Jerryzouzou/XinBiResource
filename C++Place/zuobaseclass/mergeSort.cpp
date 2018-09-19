#include "allh.h"
using namespace std;
/*
*�鲢���������
*���õݹ�ķ�ʽ�����Ͻ�����ֳ����������֣��ݹ�ȥ�������������ָ��������֮���ٲ��Ϻ���һ�� 
*ʱ�临�Ӷ�O(n*logn),����ռ临�Ӷ�O(n),���ȶ� 
*/

void merge_sort(int* arr, int l, int r);
void merge_data(int* arr, int l, int mid, int r);

/*
*�鲢���������� 
*���õݹ�ķ�ʽ�����Ͻ�����ֳ����������֣��ݹ�ȥ�������������ָ��������֮���ٲ��Ϻ���һ�� 
*ʱ�临�Ӷ�O(n*logn),����ռ临�Ӷ�O(n),���ȶ�
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
	merge_sort(arr, l, mid);		//�ݹ�������� 
	merge_sort(arr, mid+1, r);		//�ݹ������ұ� 
	merge_data(arr, l, mid, r);		//���Ҳ��������֮��ϲ���һ����������õ� 
}

/*
*ͨ���������飬�������±�ָ�������Ͻ�С��������������������֮���ٿ�����ԭ������ 
*/
void merge_data(int* arr, int l, int mid, int r){
	int len = r-l+1, i=0;
	int p1 = l;
	int p2 = mid+1;
	int* help = new int[len]();
	while(p1<=mid && p2<=r){
		help[i++] = arr[p1]<arr[p2] ? arr[p1++] : arr[p2++];
	}
	while(p1<=mid){		//��ߵĻ���ʣ 
		help[i++] = arr[p1++];
	}
	while(p2<=r){		//�ұߵĻ���ʣ 
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

