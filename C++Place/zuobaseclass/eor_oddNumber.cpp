#include "allh.h"
using namespace std;

/*
* 一个数组，一个数出现奇数次，其他数都出现偶数次，求奇数次是啥 
* 用0去异或数组中的每个数，异或完得出的就是奇数次的数
* 0^N=N   N^N=0   异或满足交换律结合律 
*/

int eor_getOddNum(int* arr, int len){
	int eor=0;
	for(int i=0; i<len; i++){
		eor = eor^arr[i];
	}
	return eor;
} 


void eor_getOddNum_main(){
	int res=0;
	int len=7;
	int arr[7] = {2,6,2,5,6,5,5};
	
	res = eor_getOddNum(arr, len);
	cout<<"出现奇数次的数是"<<res<<endl;
}
