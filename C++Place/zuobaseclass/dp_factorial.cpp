#include "allh.h"
using namespace std;

/*
* n���׳�---�ݹ鷽ʽ��dp��ʽ 
*/

static long digui_getFactorial(int n){
	if(n==1){
		return 1L;
	}
	return (long)(n*digui_getFactorial(n-1));
} 

static long dp_getFactorial(int n){
	long res = 1L;
	for(int i=1; i<=n; i++){
		res *= i;
	}
	return res;
}

void dp_factorial_main(){
	int n=12;
	cout<<"�ݹ�------12!=="<<digui_getFactorial(n)<<endl;
	cout<<"��̬�滮--12!=="<<dp_getFactorial(n)<<endl;
}
