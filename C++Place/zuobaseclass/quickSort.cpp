#include "allh.h"
using namespace std;
/*
*���ٷ��������
* �� partition������ķֳ�С�ڵ������ʹ��������ٲ��õݹ�ķ�ʽ��С�����ټ��� partition�� ����������partition�����ѭ�� 
*ʱ�临�Ӷ�O(n*logn),����ռ临�Ӷ�O(1),���ȶ� 
*/

void quick_sort(int* arr, int l, int r);
void partition(int* arr, int* p, int l, int j);

/*
*���ٷ��������� 
* �� partition������ķֳ�С�ڵ������ʹ��������ٲ��õݹ�ķ�ʽ��С�����ټ��� partition�� ����������partition�����ѭ�� 
*ʱ�临�Ӷ�O(n*logn),����ռ临�Ӷ�O(1),���ȶ� 
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
		int* p = new int[2](); 	//����ָ���������һ���������һ����λ�� 
		array_ij_swap(arr, (l+random(r-l+1)), r);	//���ȡ���鵱ǰ��Χ��ĳ����������󣬱��������������ʱ�临�ӶȺܴ� 
		partition(arr, p, l, r);
		quick_sort(arr, l, p[0]-1);		//С�����ݹ� 
		quick_sort(arr, p[1]+1, r);		//�������ݹ� 
	}
}

/*
* �����������⣬�������С�����������ʹ�����
* ���±�<���һ������С������һ���ֺ����±꽻����С�����±�++���ƣ����±�++���ƣ�
* ���±�>���һ������������ǰһ���ֺ����±꽻�����������±�--���ƣ�
* ���±�==���һ���������±�++���ƣ�
* ��������������һ���������һ�������������ص������ĵ�һ�������һ��λ�� 
*/
void partition(int* arr, int* p, int l, int r){
	int little = l - 1;
	int large = r;
	while(l < large){
		if(arr[l] < arr[r]){
			array_ij_swap(arr, ++little, l++);
		}else if(arr[l] > arr[r]){
			array_ij_swap(arr, --large, l);
		}else{
			l++;
		}
	}
	array_ij_swap(arr, large, r);
	p[0] = little+1;
	p[1] = large;
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

