#include "allh.h"
using namespace std;

int *partition(int *arr,int l,int r)
{
	int randindex = rand() % (r - l + 1)+l;
	array_ij_swap(arr, randindex, r);
	int *p = new int[2];
	int little = l - 1;
	int large = r;
	while(l < large){
		if(arr[l] < arr[r]){
			array_ij_swap(arr, ++little, l++);
		}else if(arr[l] > arr[r]){
			array_ij_swap(arr, --large, l);
		}else{
			l++;
		}
	}
	array_ij_swap(arr, large, r);
	p[0] = little+1;
	p[1] = large;
	
	return p;
}

/*思路：1.p[0] <= k <= p[1]，打印0~k-1位置数
2.k在小于区，数组变成l~p[0]-1，继续partition，
3.k在大于区，数组变成p[1]+1~r，继续partition*/
int *find_k_littleNUm(int *arr, int l, int r,int k)
{
	if (k<0 || k>r)
		return 0;
	else
	{
		int *result = new int[k];
		int *p = new int[2];
		int start = l;
		int end = r;
		p = partition(arr, start, end);
		
		while (k < p[0] || k > p[1]) {
			if (k < p[0]) {
				end = p[0] - 1;
				p = partition(arr, start, end);
			}
			else if (k > p[1]) {
				start = p[1] + 1;
				p = partition(arr, start, end);
			}
		}
		for (int i = 0; i < k; i++)
			result[i] = arr[i];
		
		return result;
	}
}

void find_k_littleNUm_main()
{
	int k[6] = { 1,2,3,4,5,6 };
	int arr[8] = {22, 3, 4, 2, 5, 6, 8, 9};
	//int *result = new int[size];
	
	for (int i = 0; i < 6; i++)
	{
		find_k_littleNUm(arr, 0, 7, k[i]);
		cout<<"现在数组状态---"; 
		print_int_array(arr, 8);
		cout<<"最小"<<k[i]<<"个数------"; 
		for (int j = 0; j < k[i]; j++)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
	}
}
