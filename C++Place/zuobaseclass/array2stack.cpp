#include "allh.h"
using namespace std;

/*
* ������ʵ��һ��ջ�� 
*/

class ArrayStack{
private:
	int *arr;
	int arr_len;
	int size;
	
public:
	ArrayStack(int initSize){
		this->size = 0;
		this->arr_len = initSize; 
		arr = new int[initSize];
	}
	
	/*
	* ����true��ʾ�õ�ջ�����ɹ�������false��ʾջ�ǿյģ��õ�ջ����ʧ�� 
	* res�� ջ������ 
	*/ 
	bool peek(int &res){
		if(size <= 0) return false;
		res = arr[size-1];
		return true;
	}
	
	/*
	* ����true��ʾv����ջ�ɹ�������false��ʾջ�����ģ�������ջʧ��
	*/
	bool push(int v){
		if(size == arr_len) return false;
		arr[size++] = v;
		return true;
	} 
	
	/*
	* ����true��ʾ����ջ�����ɹ�������false��ʾջ�ǿյģ�����ջ����ʧ�� 
	* res�� ջ������ 
	*/ 
	bool pop(int &res){
		if(size <= 0) return false;
		res = arr[--size];
		return true;
	}
	
};

void array2stack_main(){
	bool ret = false;
	int res = 0;
	ArrayStack arraystack(3);
	arraystack.push(3);arraystack.push(5);arraystack.push(1);
	for(int i=0; i<3; i++){
		ret = arraystack.pop(res);
		if(ret) cout<<res<<" ";
	}
	cout<<endl;
}

