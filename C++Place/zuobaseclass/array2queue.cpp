#include "allh.h"
using namespace std;

/*
* 用数组实现一个队列
* first用于读的索引，last用于写的指引，size表示队列的大小 
*/

class ArrayQueue{
private:
	int *arr;
	int arr_len, size, first, last;
	
public:
	ArrayQueue(int initSize){
		this->size = 0;
		this->first = 0;
		this->last = 0;
		this->arr_len = initSize; 
		arr = new int[initSize];
	}
	
	/*
	* 返回true表示得到队列头成功，返回false表示队列是空的，得到队列头失败 
	* res是 队列头的数 
	*/ 
	bool peek(int &res){
		if(size <= 0) return false;
		res = arr[first];
		return true;
	}
	
	/*
	* 返回true表示v填入队列成功，返回false表示队列是满的，数填入队列失败
	*/
	bool push(int v){
		if(size == arr_len) return false;
		size++; 
		arr[last] = v;
		last = last==(arr_len-1) ? 0 : last+1;	//到达数组尾了，可以调到0位置，循环寸，循环取 
		return true;
	} 
	
	/*
	* 返回true表示弹出队列头成功，返回false表示队列是空的，弹出队列头失败 
	* res是 队列的数 
	*/ 
	bool pop(int &res){
		if(size <= 0) return false;
		size--;
		res = arr[first];
		first = first==(first-1) ? 0 : first+1;	//到达数组尾了，可以调到0位置，循环寸，循环取
		return true;
	}
	
};

void array2queue_main(){
	bool ret = false;
	int res = 0;
	ArrayQueue arrayqueue(3);
	arrayqueue.push(3);arrayqueue.push(5);arrayqueue.push(1);
	for(int i=0; i<3; i++){
		ret = arrayqueue.pop(res);
		if(ret) cout<<res<<" ";
	}
	cout<<endl;
}

