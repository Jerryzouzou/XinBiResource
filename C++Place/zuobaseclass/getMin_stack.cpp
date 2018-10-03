#include "allh.h"
using namespace std;

/*
* ʵ��һ���ܹ�ȥ��С����ջ
* ������ջ��һ��ջ����������������һ��ջ������ջ��С���룬����ʱ�����������ظ���һ��ջ��
* getMin��ʱ�򣬴ӷ�С����ջ��ȡջ�� 
*/

//��С����ջ��С����һ��ջ��С����һ�µ�ջ 
class customStack{
private:
	stack<int> dataStack;
	stack<int> minStack;
public:

	//ֻ����ջ�������� 
	int top(){
		if(dataStack.empty()){
			cout<<"stack is empty"<<endl;
			exit(0); 
		}
		return dataStack.top();
	}
	
	//ֻ���������� 
	void pop(){
		if(dataStack.empty()){
			cout<<"stack is empty"<<endl;
			exit(0); 
		}
		dataStack.pop();
		minStack.pop();
	}
	
	/*
	* ������ջ��С���룬����ʱ�ظ���һ��ջ������������ջ��Сһ�� 
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
	* ֻ����ջ����С���������� 
	*/ 
	int getMin(){
		if(minStack.empty()){
			cout<<"stack is empty"<<endl;
			exit(0); 
		}
		return minStack.top();
	} 
};

//��С����ջ��С����һ��ջ��С��һ��һ�£�С��ջС��ֻ��һ�� 
class customStack2{
private:
	stack<int> dataStack;
	stack<int> minStack;
public:

	//ֻ����ջ�������� 
	int top(){
		if(dataStack.empty()){
			cout<<"stack is empty"<<endl;
			exit(0); 
		}
		return dataStack.top();
	}
	
	//ֻ���������� , С��ջ������ջջ����ͬʱ�ŵ��� 
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
	* ������ջ��С���룬����ʱ��������һ��ջ������������ջ��Сһ�� 
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
	* ֻ����ջ����С���������� 
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
	
	cout<<"-------------�����ķָ���--------------"<<endl;
	
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


