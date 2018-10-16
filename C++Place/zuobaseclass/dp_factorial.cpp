#include "allh.h"
using namespace std;

/*
* n！阶乘---递归方式和dp方式 
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
	cout<<"递归------12!=="<<digui_getFactorial(n)<<endl;
	cout<<"动态规划--12!=="<<dp_getFactorial(n)<<endl;
}
