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
	cout<<"------------������------------" <<endl;
	heap_sort_main();		//������ 
	cout<<"------------Ͱ����--0~200 ------------" <<endl;
	bucket_sort_main();		//Ͱ����--0~200 
	cout<<"------------����������------------" <<endl;
	pre_in_pos_2tree_traversal_main();		//���������� 
	cout<<"------------С�ױ���-DP------------" <<endl;
	xiaomi_main();		//��̬�滮--��ͬ���鲻�ظ��ܷ���ϳ�ָ���� 
	cout<<"------------��ȡ�ߵķ�����-DP------" <<endl;
	dp_roadWays_main();	//��̬�滮--��Χ1~n����ǰλ��p����k�������ߵ�m�ķ������� 
	cout<<"------------������������-DP------" <<endl;
	maxsum_subarr_main();	//��̬�滮--���������͵�����������ĺ� 
	cout<<"------------���õ����������ε���----" <<endl;
	eor_getOddNum_main();	//���õ����������ε��� 
	cout<<"------------ϵͳsort�ĸ�������----" <<endl;
	comparator_main();		//ϵͳsort�ĸ������� 
	cout<<"------------�ѷ�ʽ��ȡ������λ��-------" <<endl;
	medianNUm_heap_main();		//�ô�С���ѷ�ʽ��ȡ��λ�� 
	cout<<"------------�Զ��������priority_queue------" <<endl;
	priority_queue_comparator_main();	//�Զ��������priority_queue 
	cout<<"------------����������������ֵ-Ͱ------" <<endl;
	maxGrap_main();		//����������Ͱ�õ�����������������ֵ 
	cout<<"------------����ʵ��ջstack-----------" <<endl;
	array2stack_main();	//������ʵ��ջstack 
	cout<<"------------����ʵ��ջqueue-----------" <<endl;
	array2queue_main();	//������ʵ��ջqueue 
	cout<<"------------���Ի�ȡ��С����ջ-----------" <<endl;
	getMin_stack_main();	//ʵ��һ�����Ի�ȡ��С����ջ 
	cout<<"------------֮�ʹ�ӡ��ά����-----------" <<endl;
	printMatrixZigZag_main();	//֮�ʹ�ӡ��ά���� 
	cout<<"------------������������ת-----------" <<endl;
	rotateMatrix_main();		//������������ת 
	cout<<"------------תȦ��ӡ����-----------" <<endl;
	printMatrixSpiralOrdar_main();	//תȦ��ӡ���� 
	cout<<"------------����������Сk����-----------" <<endl;
	find_k_littleNUm_main();	//����������Сk���� 
	cout<<"------------��ӡ������������������-----------" <<endl;
	linkList_printCommonPart_main();	//��ӡ������������������ 
	cout<<"------------�����ά������ĳ��-----------" <<endl;
	findNumInSortedMatrix_main();	//�����ά������ĳ�� 
	cout<<"------------�����Ƿ��ǻ��Ľṹ-----------" <<endl;
	linkList_isPalindromeList_main();	//�����Ƿ��ǻ��Ľṹ 
	cout<<"------------����partition-----------" <<endl;
	linkList_partition_main();	//����partition 
	
	return 0;
}
