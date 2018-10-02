#ifndef __TOOL_H__
#define __TOOL_H__

void array_ij_swap(int* arr, int i, int j);		//int 数组中，i，j位置的值对调
void generateRandomArray(int* arr, int len, int maxvalue);	//产生最大值maxvalue为的随机数数组
void copy_array(int* arr_from, int* arr_to, int len1, int len2);	//拷贝arrarr_from数组到 arr_to数组 
bool isEqual_intArr(int *arr1, int* arr2, int len1, int len2);	//判断int数组是否相同
void print_int_array(int* arr, int len);	//打印int数组，以空格间隔 
void partition(int* arr, int* p, int l, int r, int v); 		//对数组l~r范围划分小于区等于区大于区，P是参照值 

#endif
