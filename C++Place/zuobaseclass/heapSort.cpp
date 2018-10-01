#include "allh.h"
using namespace std;

/*
* 堆排序代码
* 先将数组不断填入堆中形成大根堆，然后不断将当前堆头最大数放到当前堆最后，这样就排好序
* 堆的两种基本操作 ：heapInsert上升操作，heapify下沉操作 
*时间复杂度O(n*logn),额外空间复杂度O(1),不稳定 
*/

void heap_insert(int* arr, int index);
void heap_ify(int* arr, int index, int size);
 
/*
* 堆排序算法排序数组 
* 一是插入一个数(heapInsert)-->堆大小加1，新数放到最后-->新数往上浮使数组维持堆结构；
* 二是弹出头位置数-->返回头位置数(heapIfy)，最后一个数和头位置交换，堆大小减1-->头位置新数往下沉使数组维持堆结构；
* 先将数组不断填入堆中形成大根堆，然后不断将当前堆头最大数放到当前堆最后，这样就排好序 
*/
void heap_sort(int* arr, int len){
	int size = len;
	if(len <= 1){
		return;
	}
	for(int i=0; i<len; i++){	//使堆结构的size从0到len维持堆结构 
		heap_insert(arr, i);
	}
	array_ij_swap(arr, 0, --size);	//将头位置最大的数放到数组最后面，堆结构大小减1，维持堆结构 
	while(size > 0){
		heap_ify(arr, 0, size);
		array_ij_swap(arr, 0, --size);		//每次都将堆结构数组最大数(即头)和堆尾交换，堆不断缩小 ，到最后就排好序 
	}
}

/*
*大根堆数组在index(这个值就是当前堆结构的大小)，插入一个数
* 使数组0~index范围维持大根堆结构 
* i位置的父节点就是(i-1)/2; 
*/
void heap_insert(int* arr, int index){
	while(arr[index] > arr[(index - 1)/2]){
		array_ij_swap(arr, index, (index-1)/2);
		index = (index-1)/2;
	}
} 

/*
*大根堆数组在index(这个值就是当前头节点)位置发生变化 
* 使数组index~size范围维持大根堆结构 
* i位置的左孩子位置是2i+1；右孩子位置是2i+2； 
*/
void heap_ify(int* arr, int index, int size){
	int l= index*2 + 1;	//index的左孩子 
	while(l<size){
		int largest = (l+1)<size && arr[l+1]>arr[l] ? l+1 : l;		//index的右孩子存在且比左孩子大才返回右孩子索引
		/*largest = arr[largest] > arr[index] ? largest : index;
		if(largest == index){
			break;
		}*/
		if(arr[largest] <= arr[index]){	//index比它的大孩子还要大了，说明下沉到合适位置了 
			break;
		}
		array_ij_swap(arr, index, largest);
		index = largest;	//更新位置，继续往下沉 
		l= index*2 + 1;
	}
}

/*
*库函数sort排序 
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

