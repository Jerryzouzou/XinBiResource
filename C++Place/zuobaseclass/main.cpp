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
	
	return 0;
}
