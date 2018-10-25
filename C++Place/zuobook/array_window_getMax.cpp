#include "allh.h"
using namespace std;

/*
* �������ɴ������ֵ����---һ�����������һ����СΪw�Ĵ��ڴ����������߻������ұߣ�ÿ�����һ�һ��λ�ã�
* ÿ������ÿ�ζ�����һ����ǰ���ֵ�γɵ����� 
* ����һ��˫�˶�����Ϊ���������꣬��������ÿ��������֤�����д�ŵ�������Ӧ��ֵ�Ӷ�ͷ����β�ǵݼ��ģ����
* ��ǰֵ�ȶ�βֵ�����βһֱ���� 
* ˫�˶���deque--push_backβ������Ԫ�أ�push_frontͷ������Ԫ�� ��pop_front��pop_backɾ��ͷβ��front��back����ͷβ 
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
			qMax.pop_back();	//��β��ӦֵС���β���������ֶ�����������Ӧֵ�ݼ� 
		}
		qMax.push_back(i);
		if(qMax.front() == i-w){
			qMax.pop_front();	//����ͷ�������������ˣ�Ҫ���� 
		}
		if(i >= w-1){	//�ӷ������γɴ��ڿ�ʼ�д������ֵ 
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
