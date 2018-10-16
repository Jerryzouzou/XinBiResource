#include "allh.h"
using namespace std;

/*
* С�������⣺����ÿ������ǰ��������С�����ĺ�
* �����ö��ֹ鲢�ķ�������merge��ʱ��ȷ��ÿ�����ڵ�ǰ��Χ�Ⱥ�����С��ʱ��
* ����ȷ����С��Ƶ��ȥ��͡� 
*/
static int merge_sort(int* arr, int l, int r);
static int merge_data(int* arr, int l, int mid, int r);

int small_sum(int* arr, int len){
	if(len <= 1){
		return 0;
	}
	return merge_sort(arr, 0, len-1);
}

/*
* �鲢���򷽷����ݹ鷽ʽmerge�����ʱ��ȷ����벿������Ұ벿��С���� 
*/
static int merge_sort(int* arr, int l, int r){
	if(l == r){
		return 0;
	}
	int mid = l + ((r-l)>>1);
	return merge_sort(arr, l, mid)+merge_sort(arr, mid+1, r)+merge_data(arr, l, mid, r);
}

/*
*ͨ���������飬�������±�ָ�������Ͻ�С��������������������֮���ٿ�����ԭ������ 
* ��벿��С����ǰ��ݹ��ʱ���Ѿ����ˣ�����ֻ��Ҫ������벿��������Ұ벿�ֵ�С���� 
*/
static int merge_data(int* arr, int l, int mid, int r){
	int len = r-l+1, i=0;
	int res = 0;
	int p1 = l;
	int p2 = mid+1;
	int* help = new int[len]();
	while(p1<=mid && p2<=r){
		res += arr[p1]<arr[p2] ? (r-p2+1)*arr[p1] : 0;	//arr[p1]С�Ļ������Ҳ��ָ���������õģ����Ի���(r-p2+1)��С 
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
	return res;
}

static int comparator(int* arr, int len){
	if(len <= 1){
		return 0;
	}
	int res=0;
	for(int i=1; i<len; i++){
		for(int j=0; j<i; j++){
			res += arr[j]<arr[i] ? arr[j] : 0;
		}
	}
	return res;
}

void smallSum_main(){
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
		if(small_sum(arr1, len) != comparator(arr2, len)){
			succeed = false;
			print_int_array(arr1, len);
			print_int_array(arr2, len);
			break;
		}
	}
	strRes=succeed ? "Nice!" : "Fucking fucked!";
	cout<<strRes<<endl;
}

