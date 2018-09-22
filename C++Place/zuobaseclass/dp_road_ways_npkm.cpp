#include "allh.h"
using namespace std;

/*
* 动态规划笔试题： 输入n范围，起点位置p， 行走k步，能走到目的地m的方法数
* 先做出递归方式，是无后效性问题，
* 再做动态规划，从目的地m开始，走0~K步能到达的坐标的方法数全部遍历出来，每个位置
* 只计算一次，最后取出起点位置p， 行走k步坐标的方法数 
*/

int digui_get_ways(int curPosition, int remainStep, int n, int m);
int dp_get_ways(int n, int p, int k, int m);

/*
* 递归方式获取 
* n范围1-n，起点位置p，步数k，目的地m 
*/ 
int digui_get_roadWays(int n, int p, int k, int m){
	if(n<2 || p<1 || p>n || m<1 || m>n){	//边界问题 
		return 0;
	}
	return digui_get_ways(p, k, n, m);
}

/*
* 递归函数：当前位置 curPosition， 剩余步数 remainStep
* 边界： 步数走完remainStep==0时，到达目的地说明这条路是通的，返回1
* 走到最左边时往右边走一格，往下递归；remainStep-1  
* 走到最右边时往左走一格，往下递归；remainStep-1 
* 其他位置是往两边递归，和为方法数 
*/
int digui_get_ways(int curPosition, int remainStep, int n, int m){
	if(remainStep==0){		//base case 
		return curPosition==m ? 1 : 0;
	}
	if(curPosition == 1){
		return digui_get_ways(2, remainStep-1, n, m);
	}
	if(curPosition == n){
		return digui_get_ways(n-1, remainStep-1, n, m);
	}else{
		return digui_get_ways(curPosition-1, remainStep-1, n, m)+digui_get_ways(curPosition+1, remainStep-1, n, m);
	}
}

/*
* 动态规划方式获取 
*/ 
int dp_get_roadWays(int n, int p, int k, int m){
	if(n<2 || p<1 || p>n || m<1 || m>n){	//边界问题 
		return 0;
	}
	return dp_get_ways(n, p, k, m);
}

/*
* 动态规划函数，从目的地m开始，走0~K步能到达的坐标的方法数全部遍历出来，每个位置
* 只计算一次，最后取出起点位置p， 行走k步坐标的方法数
*/
int dp_get_ways(int n, int p, int k, int m){
	int** dp= new int* [k+1];
	for(int i=0; i<k+1; i++){
		dp[i] = new int[n+1]();
	}
	//int dp[k+1][n+1] = {0};
	dp[0][m] = 1;
	
	for(int i=1; i<k+1; i++){
		for(int j=1; j<n+1; j++){
			if(j==1){
				dp[i][j] = dp[i-1][j+1];
			}else if(j == n){
				dp[i][j] = dp[i-1][j-1];
			}else{
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
			}
		}
	}
	
	/*for(int i=0; i<k+1; i++){
		for(int j=0; j<n+1; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	return dp[k][p];
}

void dp_roadWays_main(){
	int n, p, k, m;
	int res = 0;
	//cin>>n>>p>>k>>m;
	n=7; p=2; k=4; m=4;
	cout<<"**********使用递归方式************"<<endl;
	res = digui_get_roadWays(n, p, k , m);
	cout<<"    ---共有"<<res<<"种方法到达-----"<<endl;
	cout<<"********使用动态规划方式**********"<<endl;
	res = dp_get_roadWays(n, p, k , m);
	cout<<"    ---共有"<<res<<"种方法到达-----"<<endl;
}
