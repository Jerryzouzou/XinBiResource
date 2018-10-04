#include "allh.h"
using namespace std;

/*
* ���нṹ��ջ�ṹ�໥ת�� 
*/

/*
* ���нṹʵ��ջ�ṹ 
* ���������У�ά��ĳһ����ֻ�����µ�����ǰ������������������һ��������
* ջ�Ļ�ȡ���ߵ�����ֻ��һ���������Ķ����в���������ά���������
* ֻ��һ�����Ķ��в��ǹ̶������Ǹ����еģ� 
*/
class TwoQueue2Stack{
private:
	queue<int> dataQueue;
	queue<int> helpQueue;
public:
	void push(int num){
		dataQueue.push(num);
	}
	
	//ֻ����ջ�������� 
	int peek(){
		if(dataQueue.empty()){
			cout<<"Stack is empty"<<endl;
			exit(0);
		}
		//return dataQueue.back();		//C++����ֱ����back
		while(dataQueue.size() != 1){		//�Ѷ��г������������������������У��������еĶ�ͷ���������������� 
			helpQueue.push(dataQueue.front());
			dataQueue.pop();
		}
		int res = dataQueue.front();
		helpQueue.push(res);
		dataQueue.pop();
		//dataQueue.swap(helpQueue);
		swap(dataQueue, helpQueue);		//���н����������ݻ���dataQueue
		return res;
	}
	
	//����ջ���͵��� 
	int pop(){
		if(dataQueue.empty()){
			cout<<"Stack is empty"<<endl;
			exit(0);
		}
		//return dataQueue.back();		//C++����ֱ����back
		while(dataQueue.size() != 1){		//�Ѷ��г������������������������У��������еĶ�ͷ���������������� 
			helpQueue.push(dataQueue.front());
			dataQueue.pop();
		}
		int res = dataQueue.front();
		dataQueue.pop();
		swap(dataQueue, helpQueue);		//���н����������ݻ���dataQueue
		return res;
	}
	
};

/*
* ջ�ṹʵ�ֶ��нṹ 
* ������ջʵ�֣�һ��ר������push��������һ������pop��top�����Ĺ̶�ջ 
* һ������push��ջ�����ݽ���һ��ջʱһ��Ҫ���ꣻ
* ��������pop��top������ջ��Ϊ��ʱ��������
* ����ÿ�β�����Ҫ����ȥ�� 
*/
class TwoStack2Queue{
private:
	stack<int> stackPush;
	stack<int> stackPop;
public:
	void push(int num){
		stackPush.push(num);
	}
	
	//���ض���ͷ������ 
	int pop(){
		if(stackPush.empty() && stackPop.empty()){
			cout<<"queue is empty!"<<endl;
			exit(0);
		}else if(stackPop.empty()){	//pop��top������ջ��Ϊ��ʱ��������
			while(!stackPush.empty()){		//push��ջ�����ݽ���һ��ջʱһ��Ҫ����
				stackPop.push(stackPush.top());
				stackPush.pop();
			}
		}
		int res = stackPop.top();
		stackPop.pop();
		return res;	
	}
	
	//���ض���ͷ������ 
	int top(){
		if(stackPush.empty() && stackPop.empty()){
			cout<<"queue is empty!"<<endl;
			exit(0);
		}else if(stackPop.empty()){	//pop��top������ջ��Ϊ��ʱ��������
			while(!stackPush.empty()){		//push��ջ�����ݽ���һ��ջʱһ��Ҫ����
				stackPop.push(stackPush.top());
				stackPush.pop();
			}
		}
		return stackPop.top();	
	}
};




