#include "allh.h"
using namespace std;

/*
* 仅用递归函数和栈操作逆序一个栈 
*/

/*
* 递归方式得到栈低的值并移除 
*/
static int getAndRemoveLastElement(stack<int>& m_stack){
	int res = m_stack.top();
	m_stack.pop();
	if(m_stack.empty()){
		return res;
	}else{
		int last = getAndRemoveLastElement(m_stack);
		m_stack.push(res);
		return last;
	}
}

/*
* 递归方式，每次都得到并移除栈低，再反向push值，就逆序了 
*/
static void stack_reverse(stack<int>& m_stack){
	if(m_stack.empty()){
		return;
	}
	int i = getAndRemoveLastElement(m_stack);
	stack_reverse(m_stack);
	m_stack.push(i);
}

void stack_reverse_main(){
	stack<int> m_stack;
	m_stack.push(1);m_stack.push(2);m_stack.push(3);m_stack.push(4);m_stack.push(5);
	cout<<"原栈顶->栈低是：5->4->3->2->1"<<endl;
	stack_reverse(m_stack);
	cout<<"逆序后栈顶->栈低是：";
	while(!m_stack.empty()){
		cout<<m_stack.top()<<"->";
		m_stack.pop();
	}
	cout<<endl;
}
