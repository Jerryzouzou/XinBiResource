#include "allh.h"

using namespace std;


int main(int argc, char** argv) {
	
	cout<<"------------���õݹ�����ջ------------" <<endl;
	stack_reverse_main();
	cout<<"------------ջ�Ӷ����״Ӵ�С����------------" <<endl;
	sortStackByStack_main();	//ջ�Ӷ����״Ӵ�С����--ֻ��һ������ջ
	cout<<"------------�������ɴ������ֵ����------------" <<endl;
	array_window_getMax_main();		//�������ɴ������ֵ���� 
	cout<<"------------��������MaxTree------------" <<endl;
	maxTree_main();
	cout<<"------------����Ӿ���Ĵ�С------------" <<endl;
	maxRecSize_main();
	/*cout<<"------------ð�ݷ�����------------" <<endl;
	bubble_main();		//ð�ݷ����� */
	
	
	return 0;
}
