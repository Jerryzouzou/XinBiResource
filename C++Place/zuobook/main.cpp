#include "allh.h"

using namespace std;

void test(const int i){
	//i++;
	///printf("asaf222--i==%d", i);
}

void demo1(){
	char *str = "hello world!";
	cout<<"str=="<<str<<endl;
	int *p = (int *)str;
	cout<<"str111=="<<str<<endl;
	p++;
	cout<<"str222=="<<str<<endl;
	*p = 0;
	cout<<"str333=="<<*p<<endl;
}

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
	cout<<"------------����������max-min<=num�����������------------" <<endl;
	allLessNumSubArray_main();
	cout<<"------------��������˫������ɾ��������K���ڵ�------------" <<endl;
	removeLastKthNode_main();
	cout<<"------------ɾ�������м�ڵ��a/b���ڵ�------------" <<endl;
	remove_mid_ab_Node_main();
	cout<<"------------��ת��������------------" <<endl;
	linkList_reversePart_main();
	cout<<"------------���������Լɪ������------------" <<endl;
	linkList_josephusProblem_main();
	cout<<"------------ʢ���ˮ������------------" <<endl;
	maxArea_water_main();
	/*cout<<"------------ð�ݷ�����------------" <<endl;
	bubble_main();		//ð�ݷ����� */
	
	/*const int i=10;
	printf("asaf--i==%d", i);
	test(i);*/
	demo1();
	return 0;
}
