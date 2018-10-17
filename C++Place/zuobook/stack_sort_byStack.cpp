#include "allh.h"
using namespace std;

/*
* ʵ�ֽ�ջ�Ӷ����״Ӵ�С����ֻ��������һ��ջhelp
* ��m_stack��ִ�е���ջ����������Ԫ��Ϊcur��
* ���cur<=help��ջ��Ԫ�أ���curֱ��ѹ��help��
* ���cur>help��ջ��Ԫ�أ���help��Ԫ����һ��������һѹ��m_stack��ֱ��
* cur<=help��ջ��Ԫ�أ��ٽ�curѹ��help�� 
* ������help��֤ջ�� 
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
	cout<<"ԭջ��->ջ���ǣ�3->1->9->2->5"<<endl;
	sortStackByStack(m_stack);
	cout<<"�����ջ��->ջ���ǣ�";
	while(!m_stack.empty()){
		cout<<m_stack.top()<<"->";
		m_stack.pop();
	}
	cout<<endl;
}
