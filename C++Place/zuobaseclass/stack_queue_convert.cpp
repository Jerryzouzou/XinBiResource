#include "allh.h"
using namespace std;

/*
* 队列结构和栈结构相互转换 
*/

/*
* 队列结构实现栈结构 
* 用两个队列，维持某一队列只有最新的数，前面其他的数都在另外一个队列中
* 栈的获取或者弹出从只有一个最新数的队列中操作，持续维持上面规则
* 只有一个数的队列不是固定就是那个队列的， 
*/
class TwoQueue2Stack{
private:
	queue<int> dataQueue;
	queue<int> helpQueue;
public:
	void push(int num){
		dataQueue.push(num);
	}
	
	//只返回栈顶不弹出 
	int peek(){
		if(dataQueue.empty()){
			cout<<"Stack is empty"<<endl;
			exit(0);
		}
		//return dataQueue.back();		//C++可以直接用back
		while(dataQueue.size() != 1){		//把队列除了最新数都弹到辅助队列中，这样队列的对头就是最后进来的新数 
			helpQueue.push(dataQueue.front());
			dataQueue.pop();
		}
		int res = dataQueue.front();
		helpQueue.push(res);
		dataQueue.pop();
		//dataQueue.swap(helpQueue);
		swap(dataQueue, helpQueue);		//队列交换，把数据换回dataQueue
		return res;
	}
	
	//返回栈顶和弹出 
	int pop(){
		if(dataQueue.empty()){
			cout<<"Stack is empty"<<endl;
			exit(0);
		}
		//return dataQueue.back();		//C++可以直接用back
		while(dataQueue.size() != 1){		//把队列除了最新数都弹到辅助队列中，这样队列的对头就是最后进来的新数 
			helpQueue.push(dataQueue.front());
			dataQueue.pop();
		}
		int res = dataQueue.front();
		dataQueue.pop();
		swap(dataQueue, helpQueue);		//队列交换，把数据换回dataQueue
		return res;
	}
	
};

/*
* 栈结构实现队列结构 
* 用两个栈实现，一个专门用于push操作，另一个用于pop或top操作的固定栈 
* 一、用于push的栈倒数据进另一个栈时一定要倒完；
* 二、用于pop或top操作的栈不为空时，不给倒
* 三、每次操作都要尝试去倒 
*/
class TwoStack2Queue{
private:
	stack<int> stackPush;
	stack<int> stackPop;
public:
	void push(int num){
		stackPush.push(num);
	}
	
	//返回队列头并弹出 
	int pop(){
		if(stackPush.empty() && stackPop.empty()){
			cout<<"queue is empty!"<<endl;
			exit(0);
		}else if(stackPop.empty()){	//pop或top操作的栈不为空时，不给倒
			while(!stackPush.empty()){		//push的栈倒数据进另一个栈时一定要倒完
				stackPop.push(stackPush.top());
				stackPush.pop();
			}
		}
		int res = stackPop.top();
		stackPop.pop();
		return res;	
	}
	
	//返回队列头不弹出 
	int top(){
		if(stackPush.empty() && stackPop.empty()){
			cout<<"queue is empty!"<<endl;
			exit(0);
		}else if(stackPop.empty()){	//pop或top操作的栈不为空时，不给倒
			while(!stackPush.empty()){		//push的栈倒数据进另一个栈时一定要倒完
				stackPop.push(stackPush.top());
				stackPush.pop();
			}
		}
		return stackPop.top();	
	}
};




