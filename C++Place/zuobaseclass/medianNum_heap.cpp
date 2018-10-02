#include "allh.h"
using namespace std;

/*
* 用堆的方式获取数组的中位数 
* 数组开始往大根堆填入数，新数字比大根堆小时填入大根堆，大于时填入小根堆，每加入一个数字都要调整两个堆的大小使个数相差在2个以内
* 这样数组填入完之后，小的数字在大根堆里，大的数字在小根堆里，并且大根堆对头的本身的最大数，小根堆堆头是本身的 最小数，
* 这样中位数就在两个堆头产生（奇个数偶个数判断） 
*/

priority_queue<int> maxHeap; //默认大根堆
priority_queue<int,vector<int>,greater<int> > minHeap; //小根堆
/** addition 
equal_to       相等 
not_equal_to   不相等 
less           小于 
greater        大于 
less_equal     小于等于 
greater_equal 大于等 这些在所有的排序算法中同样适用 */

/*
* 调整堆结构，使得大根堆和小根堆的大小范围相差在2以内  
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
	if(maxHeap.empty()){	//大根堆空时第一次填入，直接填入 
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
	
	if(((maxHeap_size+minHeap_size)&1) == 0){	//说明是偶数个 
		return ((maxHeap_top+minHeap_top)/2);
	}
	
	return maxHeap_size>minHeap_size ? maxHeap_top : minHeap_top;	//奇数个的时候数多一个的那个堆顶是中位数 
}

//排序，然后获取中位数 
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
	cout<<"中位数是："<<res<<endl;
	res = getMedian_sort(arr, 7);
	cout<<"中位数是："<<res<<endl;*/
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





