#include "allh.h"
using namespace std;

/*
* 题目：给定数组arr和整数num，共返回有多少个子数组满足：max(arr[i...j])-min(arr[i...j]) <= num
* 思路：如果arr[i...j]满足上面要求则它的子数组满足要求，如果arr[i...j]不满足则包含它的数组都不满足 
* 参考窗口最大值，用两个双边队列保存qmax,qmin，令j不断向右移动(j++)，并不断更新qmax,qmin队列使得满足要求，
* 直到出现不满足，则以i作为第一个元素的子数组满足要求的个数有res+= j-i个。然后i++重新上面步骤直到遍历完 
* 双端队列deque--push_back尾部插入元素，push_front头部插入元素 ，pop_front、pop_back删除头尾，front、back返回头尾 
*/

int getNum(vector<int> arr, int num){
	if(arr.size() == 0){
		return 0;
	}
	int res=0, i=0, j=0;
	deque<int> qmax;
	deque<int> qmin;
	while(i<arr.size()){
		while(j<arr.size()){
			while((!qmin.empty()) && arr[qmin.back()]>=arr[j]){	//保持qmin递增队列，队列头是最小值 
				qmin.pop_back();
			}
			qmin.push_back(j);
			
			while((!qmax.empty()) && arr[qmax.back()]<=arr[j]){	//保持qmax递减序列，对头是最大值 
				qmax.pop_back();
			}
			qmax.push_back(j);
			
			if(arr[qmax.front()]-arr[qmin.front()] > num){	//不满足条件了说明当前i要换下一个了 
				break;
			}
			j++;
		}
		if(qmin.front() == i){		//过时弹出 
			qmin.pop_front();
		}
		if(qmax.front() == i){
			qmax.pop_front();
		}
		res += j-i;
		i++;
	}
	return res;
} 

void allLessNumSubArray_main(){
	int arr[30] = { 6, 6, 7, 0, 7, 4, 7, 4, 5, 0, 5, 2, 5, 1, 0, 2, 8, 1, 0, 6, 9, 6, 9, 7, 1, 5, 9, 4, 0, 7 };
	vector<int> varr(arr, arr+30);
	int num=5;
	int res = getNum(varr, num);
	cout<<"数组6 6 7 0 7 4 7 4 5 0 5 2 5 1 0 2 8 1 0 6 9 6 9 7 1 5 9 4 0 7的<=5的子数组个数=="<<res; 
}
