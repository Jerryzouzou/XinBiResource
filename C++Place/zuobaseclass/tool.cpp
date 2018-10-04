#include "allh.h"

using namespace std;

template<typename T>
static int count(T& x){		//����x�ĳ��� 
    int s1 = sizeof(x);
    int s2 = sizeof(x[0]);
    int result = s1 / s2;
    return result;
}

/**
*int �����У�i��jλ�õ�ֵ�Ե� 
*/
void array_ij_swap(int* arr, int i, int j){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

/**
*�������ֵmaxvalueΪ����������� 
*/
void generateRandomArray(int* arr, int len, int maxvalue){
	for(int i=0; i<len; i++){
		arr[i] = (int)(random(maxvalue) - random(maxvalue));
	}
}

/**
*����arrarr_from���鵽 arr_to���� 
*/
void copy_array(int* arr_from, int* arr_to, int len1, int len2){
	if(len1==0 || len2==0 ||(len1!=len2)){
		return;
	}
	for(int i=0; i<len1; i++){
		arr_to[i] = arr_from[i];
	}
} 

/**
*�ж�int�����Ƿ���ͬ 
*/
bool isEqual_intArr(int *arr1, int* arr2, int len1, int len2){
	if((len1==0 && len2!=0)||(len1!=0 && len2==0)||(len1!=len2)){
		return false;
	}
	if(len1==0 && len2==0){
		return true;
	}
	for(int i=0; i<len1; i++){
		if(arr1[i] != arr2[i]){
			return false;
		}
	}
	
	return true;
}

/**
*��ӡint���飬�Կո��� 
*/
void print_int_array(int* arr, int len){
	if(len == 0){
		return;
	}
	for(int i=0; i<len; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

/*
* ��ӡvector-int�Ķ�ά���� 
*/
void printMatrix_vector(vector<vector<int> > matrix){
	int lenR = matrix.size();
	int lenC = matrix[0].size();
	for(int i=0; i<lenR; i++){
		for(int j=0; j<lenC; j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
 	}	
} 

/*
* �����������⣬�������С�����������ʹ�����
* ���±�<���һ������С������һ���ֺ����±꽻����С�����±�++���ƣ����±�++���ƣ�
* ���±�>���һ������������ǰһ���ֺ����±꽻�����������±�--���ƣ�
* ���±�==���һ���������±�++���ƣ�
* ������󷵻ص������ĵ�һ�������һ��λ�� 
* l������Ҫ partition����߽磬r������Ҫpartition���ұ߽磬v�ǲ���ֵ(��������ֵ) 
*/
void partition(int* arr, int* p, int l, int r, int v){
	int little = l - 1;		//С�����߽� 
	int large = r+1;		//�������߽� 
	while(l < large){
		if(arr[l] < v){
			array_ij_swap(arr, ++little, l++);
		}else if(arr[l] > v){
			array_ij_swap(arr, --large, l);
		}else{
			l++;
		}
	}
	//array_ij_swap(arr, large, r);
	p[0] = little+1;	//���ص��������ұ߽� 
	p[1] = large-1;
}

/*
* ����������ֲ��� v�Ƿ���� 
*/ 
bool digui_erfen(int* arr, int l, int r, int v){
	if(l == r){		//����ݹ鵽l==r�ˣ����ֵ��v�ͷ���true������Ⱦͷ���false ���ݹ���� 
		if(arr[l] == v){
			return true;
		}else{
			return false;
		}
	} 
	int mid = (l+r)/2;
	if(arr[mid]==v){	//����м�λ�õ���v������true���ݹ���� 
		return true;
	}else if(arr[mid] < v){		//����м�λ��С��v��˵��vֻ����mid~r��Χ�ڣ������ݹ� 
		digui_erfen(arr, mid, r, v);
	}else if(arr[mid] > v){		//����м�λ�ô���v��˵��vֻ����l~mid��Χ�ڣ������ݹ�
		digui_erfen(arr, l, mid, v);
	}
} 





