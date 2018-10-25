#include "allh.h"
using namespace std;

/*
* 数组生成窗口最大值数组---一个整型数组和一个大小为w的窗口从数组的最左边滑到最右边，每次向右滑一个位置，
* 每个窗口每次都返回一个当前最大值形成的数组 
* 定义一个双端队列作为辅助寸坐标，遍历数组每个数，保证队列中存放的索引对应的值从对头到队尾是递减的，如果
* 当前值比队尾值大则队尾一直弹除 
* 双端队列deque--push_back尾部插入元素，push_front头部插入元素 ，pop_front、pop_back删除头尾，front、back返回头尾 
*/

static vector<int> getMaxWindow(vector<int> arr, int w){
	vector<int> res;
	if(w<1 || arr.size()<w){
		return res;
	}
	deque<int> qMax;
	int index = 0;
	for(int i=0; i<arr.size(); i++){
		while(!qMax.empty() && arr[qMax.back()]<=arr[i]){
			qMax.pop_back();	//队尾对应值小则队尾弹出，保持队列中索引对应值递减 
		}
		qMax.push_back(i);
		if(qMax.front() == i-w){
			qMax.pop_front();	//队列头索引超过窗口了，要弹除 
		}
		if(i >= w-1){	//从符合能形成窗口开始有窗口最大值 
			res.push_back(arr[qMax.front()]);
		}
	}
	return res;
} 

void array_window_getMax_main(){
	//int arr[8] = {4,3,5,4,3,3,6,7};
	vector<int> arr;
	arr.push_back(4);arr.push_back(3);arr.push_back(5);arr.push_back(4);
	arr.push_back(3);arr.push_back(3);arr.push_back(6);arr.push_back(7);
	
	vector<int> res = getMaxWindow(arr, 3);
	
	for(int i=0; i<res.size(); i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}
