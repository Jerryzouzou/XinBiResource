#include "allh.h"
using namespace std;

/*
* ���Ҿֲ���Сֵλ��--���ַ�
* �ֲ���Сֵ���壺������Ҫ�����ߵ�����С�������ͷβλ������һ��С��
* ͨ�����ַ����ң�mid�Ǿֲ���С��ֱ�ӷ��أ��������¹���left/right�߽�ȥ�ٴζ��� 
*/

static int getLessIndex(int* arr, int len){
	if(len < 1){
		return -1;
	}
	if(len==1 || arr[0] < arr[1]){
		return 0;
	}
	if(arr[len-1]<arr[len-2]){
		return len-1;
	}
	int left=1, right=len-2, mid=0;
	while(left < right){
		mid = (left+right)/2;
		if(arr[mid] > arr[mid+1]){
			left = mid+1;
		}else if(arr[mid] > arr[mid-1]){
			right = mid - 1;
		}else{
			return mid;
		}
	}
	return left;
} 


void findOneLessValueIndex_main(){
	int arr[7] = {6, 5, 3, 4, 6, 7, 8};
	int index = getLessIndex(arr, 7);
	cout<<"�ֲ���Сֵ--ԭ����---";
	print_int_array(arr, 7);
	cout<<"�ֲ���Сֵ--λ��index=="<<index<<"--arr[index]=="<<arr[index]<<endl; 
}

