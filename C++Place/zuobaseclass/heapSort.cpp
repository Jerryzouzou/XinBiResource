#include "allh.h"
using namespace std;

/*
* ���������
* �Ƚ����鲻����������γɴ���ѣ�Ȼ�󲻶Ͻ���ǰ��ͷ������ŵ���ǰ������������ź���
* �ѵ����ֻ������� ��heapInsert����������heapify�³����� 
*ʱ�临�Ӷ�O(n*logn),����ռ临�Ӷ�O(1),���ȶ� 
*/

void heap_insert(int* arr, int index);
void heap_ify(int* arr, int index, int size);
 
/*
* �������㷨�������� 
* һ�ǲ���һ����(heapInsert)-->�Ѵ�С��1�������ŵ����-->�������ϸ�ʹ����ά�ֶѽṹ��
* ���ǵ���ͷλ����-->����ͷλ����(heapIfy)�����һ������ͷλ�ý������Ѵ�С��1-->ͷλ���������³�ʹ����ά�ֶѽṹ��
* �Ƚ����鲻����������γɴ���ѣ�Ȼ�󲻶Ͻ���ǰ��ͷ������ŵ���ǰ������������ź��� 
*/
void heap_sort(int* arr, int len){
	int size = len;
	if(len <= 1){
		return;
	}
	for(int i=0; i<len; i++){	//ʹ�ѽṹ��size��0��lenά�ֶѽṹ 
		heap_insert(arr, i);
	}
	array_ij_swap(arr, 0, --size);	//��ͷλ���������ŵ���������棬�ѽṹ��С��1��ά�ֶѽṹ 
	while(size > 0){
		heap_ify(arr, 0, size);
		array_ij_swap(arr, 0, --size);		//ÿ�ζ����ѽṹ���������(��ͷ)�Ͷ�β�������Ѳ�����С ���������ź��� 
	}
}

/*
*�����������index(���ֵ���ǵ�ǰ�ѽṹ�Ĵ�С)������һ����
* ʹ����0~index��Χά�ִ���ѽṹ 
* iλ�õĸ��ڵ����(i-1)/2; 
*/
void heap_insert(int* arr, int index){
	while(arr[index] > arr[(index - 1)/2]){
		array_ij_swap(arr, index, (index-1)/2);
		index = (index-1)/2;
	}
} 

/*
*�����������index(���ֵ���ǵ�ǰͷ�ڵ�)λ�÷����仯 
* ʹ����index~size��Χά�ִ���ѽṹ 
* iλ�õ�����λ����2i+1���Һ���λ����2i+2�� 
*/
void heap_ify(int* arr, int index, int size){
	int l= index*2 + 1;	//index������ 
	while(l<size){
		int largest = (l+1)<size && arr[l+1]>arr[l] ? l+1 : l;		//index���Һ��Ӵ����ұ����Ӵ�ŷ����Һ�������
		/*largest = arr[largest] > arr[index] ? largest : index;
		if(largest == index){
			break;
		}*/
		if(arr[largest] <= arr[index]){	//index�����Ĵ��ӻ�Ҫ���ˣ�˵���³�������λ���� 
			break;
		}
		array_ij_swap(arr, index, largest);
		index = largest;	//����λ�ã��������³� 
		l= index*2 + 1;
	}
}

/*
*�⺯��sort���� 
*/
static void own_sort(int* arr, int len){
	sort(arr, arr+len);
}

void heap_sort_main(){
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
		heap_sort(arr1, len);
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
	heap_sort(arr, len);
	print_int_array(arr, len);
}

