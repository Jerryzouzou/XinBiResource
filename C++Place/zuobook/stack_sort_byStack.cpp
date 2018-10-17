#include "allh.h"
using namespace std;

/*
* 实现将栈从顶到底从大到小排序，只允许申请一个栈help
* 在m_stack上执行弹出栈顶，弹出的元素为cur，
* 如果cur<=help的栈顶元素，则将cur直接压入help；
* 如果cur>help的栈顶元素，则将help的元素逐一弹出，逐一压入m_stack，直到
* cur<=help的栈顶元素，再将cur压入help。 
* 这样就help保证栈顶 
*/

static void sortStackByStack(stack<int>& m_stack){
	stack<int> help;
	while(!m_stack.empty()){
		int cur = m_stack.top();
		m_stack.pop();
		while(!help.empty() && help.top()<cur){
			m_stack.push(help.top());
			help.pop();
		}
		help.push(cur);
	} 
	while(!help.empty()){
		m_stack.push(help.top());
		help.pop();
	}
}

void sortStackByStack_main(){
	stack<int> m_stack;
	m_stack.push(5);m_stack.push(2);m_stack.push(9);m_stack.push(1);m_stack.push(3);
	cout<<"原栈顶->栈低是：3->1->9->2->5"<<endl;
	sortStackByStack(m_stack);
	cout<<"排序后栈顶->栈低是：";
	while(!m_stack.empty()){
		cout<<m_stack.top()<<"->";
		m_stack.pop();
	}
	cout<<endl;
}
