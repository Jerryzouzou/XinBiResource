#ifndef __TOOL_H__
#define __TOOL_H__

void array_ij_swap(int* arr, int i, int j);		//int �����У�i��jλ�õ�ֵ�Ե�
void generateRandomArray(int* arr, int len, int maxvalue);	//�������ֵmaxvalueΪ�����������
void copy_array(int* arr_from, int* arr_to, int len1, int len2);	//����arrarr_from���鵽 arr_to���� 
bool isEqual_intArr(int *arr1, int* arr2, int len1, int len2);	//�ж�int�����Ƿ���ͬ
void print_int_array(int* arr, int len);	//��ӡint���飬�Կո��� 
void partition(int* arr, int* p, int l, int r, int v); 		//������l~r��Χ����С������������������P�ǲ���ֵ 

#endif
