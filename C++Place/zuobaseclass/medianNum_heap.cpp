#include "allh.h"
using namespace std;

/*
* �öѵķ�ʽ��ȡ�������λ�� 
* ���鿪ʼ��������������������ֱȴ����Сʱ�������ѣ�����ʱ����С���ѣ�ÿ����һ�����ֶ�Ҫ���������ѵĴ�Сʹ���������2������
* ��������������֮��С�������ڴ��������������С��������Ҵ���Ѷ�ͷ�ı�����������С���Ѷ�ͷ�Ǳ���� ��С����
* ������λ������������ͷ�����������ż�����жϣ� 
*/

priority_queue<int> maxHeap; //Ĭ�ϴ����
priority_queue<int,vector<int>,greater<int> > minHeap; //С����
/** addition 
equal_to       ��� 
not_equal_to   ����� 
less           С�� 
greater        ���� 
less_equal     С�ڵ��� 
greater_equal ���ڵ� ��Щ�����е������㷨��ͬ������ */

/*
* �����ѽṹ��ʹ�ô���Ѻ�С���ѵĴ�С��Χ�����2����  
*/
void modify_twoHeap_size(){
	if(maxHeap.size() == (minHeap.size()+2)){
		minHeap.push(maxHeap.top());
		maxHeap.pop();
	}
	if(minHeap.size() == (maxHeap.size()+2)){
		maxHeap.push(minHeap.top());
		minHeap.pop();
	}
}

void add_num(int num){
	if(maxHeap.empty()){	//����ѿ�ʱ��һ�����룬ֱ������ 
		maxHeap.push(num);
		return;
	}
	if(maxHeap.top() > num){
		maxHeap.push(num);
	}else{
		if(minHeap.empty()){
			minHeap.push(num);
		}else if(minHeap.top() > num){
			maxHeap.push(num);
		}else{
			minHeap.push(num);
		}
	}
	modify_twoHeap_size();
} 

int getMedian(){
	int maxHeap_size = maxHeap.size();
	int minHeap_size = minHeap.size();
	
	if((maxHeap_size+minHeap_size) == 0){
		return NULL;
	}
	
	int maxHeap_top = maxHeap.top();
	int minHeap_top = minHeap.top();
//	cout<<"maxHeap_size=="<<maxHeap_size<<endl;
//	cout<<"minHeap_size=="<<minHeap_size<<endl;
//	cout<<"maxHeap_top=="<<maxHeap_top<<endl;
//	cout<<"minHeap_top=="<<minHeap_top<<endl;
	
	if(((maxHeap_size+minHeap_size)&1) == 0){	//˵����ż���� 
		return ((maxHeap_top+minHeap_top)/2);
	}
	
	return maxHeap_size>minHeap_size ? maxHeap_top : minHeap_top;	//��������ʱ������һ�����Ǹ��Ѷ�����λ�� 
}

//����Ȼ���ȡ��λ�� 
int getMedian_sort(int* arr, int len){
	if(len == 0){
		return NULL;
	}
	int mid = (len-1)/2; 
	sort(arr, arr+len);
	if((len&1) == 0){
		return (arr[mid]+arr[mid+1])/2;
	}else{
		return arr[mid];
	}
}

void medianNUm_heap_main(){
	/*int res = 0;
	int arr[7] = {3, 2, 1, 5, 6, 4, 7};
	for(int i=0; i<7; i++){
		add_num(arr[i]);
	}
	res = getMedian();
	cout<<"��λ���ǣ�"<<res<<endl;
	res = getMedian_sort(arr, 7);
	cout<<"��λ���ǣ�"<<res<<endl;*/
	string strRes = "";
	int testTime = 1000;
	int maxSize = 10;
	int maxValue = 100;
	bool succeed = true;
	for (int i = 0; i < testTime; i++) {
		int len = random(maxSize);
		int* arr1 = new int[len];
		int* arr2 = new int[len];
		generateRandomArray(arr1, len, maxValue);
		copy_array(arr1, arr2, len, len);
		
		while(!maxHeap.empty()) maxHeap.pop();
		while(!minHeap.empty()) minHeap.pop();
 		for(int i=0; i<len; i++){
			add_num(arr1[i]);
		}
		if(getMedian() != getMedian_sort(arr2, len)){
			succeed = false;
			print_int_array(arr1, len);
			break;
		}
	}
	strRes=succeed ? "Nice!" : "Fucking fucked!";
	cout<<strRes<<endl;
}





