#include "allh.h"
using namespace std;

/*
* ���õݹ麯����ջ��������һ��ջ 
*/

/*
* �ݹ鷽ʽ�õ�ջ�͵�ֵ���Ƴ� 
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
* �ݹ鷽ʽ��ÿ�ζ��õ����Ƴ�ջ�ͣ��ٷ���pushֵ���������� 
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
	cout<<"ԭջ��->ջ���ǣ�5->4->3->2->1"<<endl;
	stack_reverse(m_stack);
	cout<<"�����ջ��->ջ���ǣ�";
	while(!m_stack.empty()){
		cout<<m_stack.top()<<"->";
		m_stack.pop();
	}
	cout<<endl;
}
