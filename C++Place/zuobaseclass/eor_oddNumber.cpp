#include "allh.h"
using namespace std;

/*
* һ�����飬һ�������������Σ�������������ż���Σ�����������ɶ 
* ��0ȥ��������е�ÿ�����������ó��ľ��������ε���
* 0^N=N   N^N=0   ������㽻���ɽ���� 
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
	cout<<"���������ε�����"<<res<<endl;
}
