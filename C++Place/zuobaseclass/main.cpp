#include <iostream>
#include "allh.h"

using namespace std;


int main(int argc, char** argv) {
	
	cout<<"------------ð�ݷ�����------------" <<endl;
	bubble_main();		//ð�ݷ����� 
	cout<<"------------ѡ������------------" <<endl;
	select_sort_main();	//ѡ������ 
	cout<<"------------���뷨����------------" <<endl;
	insertion_sort_main();	//���뷨���� 
	cout<<"------------�鲢������------------" <<endl;
	merge_sort_main();		//�鲢������ 
	cout<<"------------��������------------" <<endl;
	quick_sort_main();		//�������� 
	cout<<"------------Ͱ����--0~200 ------------" <<endl;
	bucket_sort_main();		//Ͱ����--0~200 
	cout<<"------------����������------------" <<endl;
	pre_in_pos_2tree_traversal_main();		//���������� 
	cout<<"------------С�ױ���-DP------------" <<endl;
	xiaomi_main();		//��̬�滮--��ͬ���鲻�ظ��ܷ���ϳ�ָ���� 
	
	return 0;
}
