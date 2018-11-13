#include "allh.h"
using namespace std;

/*
* ��Ŀ����������arr������num���������ж��ٸ����������㣺max(arr[i...j])-min(arr[i...j]) <= num
* ˼·�����arr[i...j]��������Ҫ������������������Ҫ�����arr[i...j]������������������鶼������ 
* �ο��������ֵ��������˫�߶��б���qmax,qmin����j���������ƶ�(j++)�������ϸ���qmax,qmin����ʹ������Ҫ��
* ֱ�����ֲ����㣬����i��Ϊ��һ��Ԫ�ص�����������Ҫ��ĸ�����res+= j-i����Ȼ��i++�������沽��ֱ�������� 
* ˫�˶���deque--push_backβ������Ԫ�أ�push_frontͷ������Ԫ�� ��pop_front��pop_backɾ��ͷβ��front��back����ͷβ 
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
			while((!qmin.empty()) && arr[qmin.back()]>=arr[j]){	//����qmin�������У�����ͷ����Сֵ 
				qmin.pop_back();
			}
			qmin.push_back(j);
			
			while((!qmax.empty()) && arr[qmax.back()]<=arr[j]){	//����qmax�ݼ����У���ͷ�����ֵ 
				qmax.pop_back();
			}
			qmax.push_back(j);
			
			if(arr[qmax.front()]-arr[qmin.front()] > num){	//������������˵����ǰiҪ����һ���� 
				break;
			}
			j++;
		}
		if(qmin.front() == i){		//��ʱ���� 
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
	cout<<"����6 6 7 0 7 4 7 4 5 0 5 2 5 1 0 2 8 1 0 6 9 6 9 7 1 5 9 4 0 7��<=5�����������=="<<res; 
}
