#include "allh.h"
using namespace std;

/*
* ���������л��ͷ����л�---������ת��Ϊ�ַ������л�--��ͨ���ַ��������������
* �ݹ鷽ʽ��ǰ�������ʽ���л�������ӡʱ��Ϊ���л��ַ�����ֵ��Ϊ"v_"����ֵʱΪ"#_"
* �����л�ͬ��
*  
*/

struct Node{
	int value;
	Node* left;
	Node* right;
	Node(int a=0):value(a), left(NULL), right(NULL){};
};

