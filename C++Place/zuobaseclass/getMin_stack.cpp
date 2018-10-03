#include "allh.h"
using namespace std;

/*
* 实现一个能过去最小数的栈
* 用两个栈，一个栈正常放数出数，另一个栈新数比栈顶小放入，大于时不放数或者重复放一个栈顶
* getMin的时候，从放小数的栈中取栈顶 
*/

//放小数的栈大小和另一个栈大小保持一致的栈 
class customStack{
private:
	stack<int> dataStack;
	stack<int> minStack;
public:

	//只返回栈顶不弹出 
	int top(){
		if(dataStack.empty()){
			cout<<"stack is empty"<<endl;
			exit(0); 
		}
		return dataStack.top();
	}
	
	//只弹出不返回 
	void pop(){
		if(dataStack.empty()){
			cout<<"stack is empty"<<endl;
			exit(0); 
		}
		dataStack.pop();
		minStack.pop();
	}
	
	/*
	* 新数比栈顶小放入，大于时重复放一个栈顶，保持两个栈大小一致 
	*/
	void push(int num){
		if(minStack.empty()){
			minStack.push(num);
		}else if(num <= this->getMin()){
			minStack.push(num);
		}else{
			minStack.push(this->getMin());
		}
		dataStack.push(num);
	}

	/*
	* 只返回栈的最小数，不弹出 
	*/ 
	int getMin(){
		if(minStack.empty()){
			cout<<"stack is empty"<<endl;
			exit(0); 
		}
		return minStack.top();
	} 
};

//放小数的栈大小和另一个栈大小不一定一致，小数栈小数只放一个 
class customStack2{
private:
	stack<int> dataStack;
	stack<int> minStack;
public:

	//只返回栈顶不弹出 
	int top(){
		if(dataStack.empty()){
			cout<<"stack is empty"<<endl;
			exit(0); 
		}
		return dataStack.top();
	}
	
	//只弹出不返回 , 小数栈和数据栈栈顶相同时才弹出 
	void pop(){
		if(dataStack.empty()){
			cout<<"stack is empty"<<endl;
			exit(0); 
		}
		if(dataStack.top() == minStack.top()){
			minStack.pop();
		} 
		dataStack.pop();
	}
	
	/*
	* 新数比栈顶小放入，大于时不放数放一个栈顶，保持两个栈大小一致 
	*/
	void push(int num){
		if(minStack.empty()){
			minStack.push(num);
		}else if(num <= this->getMin()){
			minStack.push(num);
		}
		dataStack.push(num);
	}

	/*
	* 只返回栈的最小数，不弹出 
	*/ 
	int getMin(){
		if(minStack.empty()){
			cout<<"stack is empty"<<endl;
			exit(0); 
		}
		return minStack.top();
	} 
};

void getMin_stack_main(){
	customStack stack1;
	stack1.push(3);
	cout<<"--in 3--min=="<<stack1.getMin()<<endl;
	stack1.push(4);
	cout<<"--in 4--min=="<<stack1.getMin()<<endl;
	stack1.push(1);
	cout<<"--in 1--min=="<<stack1.getMin()<<endl;
	cout<<"----top=="<<stack1.top()<<endl;
	stack1.pop();
	cout<<"--after pop--min=="<<stack1.getMin()<<endl;
	
	cout<<"-------------华丽的分割线--------------"<<endl;
	
	customStack2 stack2;
	stack2.push(3);
	cout<<"--in 3--min=="<<stack2.getMin()<<endl;
	stack2.push(4);
	cout<<"--in 4--min=="<<stack2.getMin()<<endl;
	stack2.push(1);
	cout<<"--in 1--min=="<<stack2.getMin()<<endl;
	cout<<"----top=="<<stack2.top()<<endl;
	stack2.pop();
	cout<<"--after pop--min=="<<stack2.getMin()<<endl;
}


