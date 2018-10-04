#include "allh.h"

using namespace std;

template<typename T>
static int count(T& x){		//计算x的长度 
    int s1 = sizeof(x);
    int s2 = sizeof(x[0]);
    int result = s1 / s2;
    return result;
}

/**
*int 数组中，i，j位置的值对调 
*/
void array_ij_swap(int* arr, int i, int j){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

/**
*产生最大值maxvalue为的随机数数组 
*/
void generateRandomArray(int* arr, int len, int maxvalue){
	for(int i=0; i<len; i++){
		arr[i] = (int)(random(maxvalue) - random(maxvalue));
	}
}

/**
*拷贝arrarr_from数组到 arr_to数组 
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
*判断int数组是否相同 
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
*打印int数组，以空格间隔 
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
* 打印vector-int的二维数组 
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
* 荷兰国旗问题，将排序成小于区等于区和大于区
* 左下标<最后一个数，小于区下一数字和左下标交换，小于区下标++右移，左下标++右移；
* 左下标>最后一个数，大于区前一数字和左下标交换，大于区下标--左移；
* 左下标==最后一个数，左下标++右移；
* 遍历完后返回等于区的第一个和最后一个位置 
* l是数组要 partition的左边界，r是数组要partition的右边界，v是参照值(等于区的值) 
*/
void partition(int* arr, int* p, int l, int r, int v){
	int little = l - 1;		//小于区边界 
	int large = r+1;		//大于区边界 
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
	p[0] = little+1;	//返回等于区左右边界 
	p[1] = large-1;
}

/*
* 升序数组二分查找 v是否存在 
*/ 
bool digui_erfen(int* arr, int l, int r, int v){
	if(l == r){		//如果递归到l==r了，这个值是v就返回true，不相等就返回false ，递归结束 
		if(arr[l] == v){
			return true;
		}else{
			return false;
		}
	} 
	int mid = (l+r)/2;
	if(arr[mid]==v){	//如果中间位置等于v，返回true，递归结束 
		return true;
	}else if(arr[mid] < v){		//如果中间位置小于v，说明v只能在mid~r范围内，继续递归 
		digui_erfen(arr, mid, r, v);
	}else if(arr[mid] > v){		//如果中间位置大于v，说明v只能在l~mid范围内，继续递归
		digui_erfen(arr, l, mid, v);
	}
} 





