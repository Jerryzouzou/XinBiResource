#include "allh.h"
using namespace std;

/*
* ������ʵ��һ������
* first���ڶ���������last����д��ָ����size��ʾ���еĴ�С 
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
	* ����true��ʾ�õ�����ͷ�ɹ�������false��ʾ�����ǿյģ��õ�����ͷʧ�� 
	* res�� ����ͷ���� 
	*/ 
	bool peek(int &res){
		if(size <= 0) return false;
		res = arr[first];
		return true;
	}
	
	/*
	* ����true��ʾv������гɹ�������false��ʾ���������ģ����������ʧ��
	*/
	bool push(int v){
		if(size == arr_len) return false;
		size++; 
		arr[last] = v;
		last = last==(arr_len-1) ? 0 : last+1;	//��������β�ˣ����Ե���0λ�ã�ѭ���磬ѭ��ȡ 
		return true;
	} 
	
	/*
	* ����true��ʾ��������ͷ�ɹ�������false��ʾ�����ǿյģ���������ͷʧ�� 
	* res�� ���е��� 
	*/ 
	bool pop(int &res){
		if(size <= 0) return false;
		size--;
		res = arr[first];
		first = first==(first-1) ? 0 : first+1;	//��������β�ˣ����Ե���0λ�ã�ѭ���磬ѭ��ȡ
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

