#include "allh.h"
using namespace std;

/*
* 用数组实现一个栈， 
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
	* 返回true表示得到栈顶数成功，返回false表示栈是空的，得到栈顶数失败 
	* res是 栈顶的数 
	*/ 
	bool peek(int &res){
		if(size <= 0) return false;
		res = arr[size-1];
		return true;
	}
	
	/*
	* 返回true表示v填入栈成功，返回false表示栈是满的，数填入栈失败
	*/
	bool push(int v){
		if(size == arr_len) return false;
		arr[size++] = v;
		return true;
	} 
	
	/*
	* 返回true表示弹出栈顶数成功，返回false表示栈是空的，弹出栈顶数失败 
	* res是 栈顶的数 
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

