#include "allh.h"
using namespace std;

/*
* ��̬�滮�����⣺ ����n��Χ�����λ��p�� ����k�������ߵ�Ŀ�ĵ�m�ķ�����
* �������ݹ鷽ʽ�����޺�Ч�����⣬
* ������̬�滮����Ŀ�ĵ�m��ʼ����0~K���ܵ��������ķ�����ȫ������������ÿ��λ��
* ֻ����һ�Σ����ȡ�����λ��p�� ����k������ķ����� 
*/

int digui_get_ways(int curPosition, int remainStep, int n, int m);
int dp_get_ways(int n, int p, int k, int m);

/*
* �ݹ鷽ʽ��ȡ 
* n��Χ1-n�����λ��p������k��Ŀ�ĵ�m 
*/ 
int digui_get_roadWays(int n, int p, int k, int m){
	if(n<2 || p<1 || p>n || m<1 || m>n){	//�߽����� 
		return 0;
	}
	return digui_get_ways(p, k, n, m);
}

/*
* �ݹ麯������ǰλ�� curPosition�� ʣ�ಽ�� remainStep
* �߽磺 ��������remainStep==0ʱ������Ŀ�ĵ�˵������·��ͨ�ģ�����1
* �ߵ������ʱ���ұ���һ�����µݹ飻remainStep-1  
* �ߵ����ұ�ʱ������һ�����µݹ飻remainStep-1 
* ����λ���������ߵݹ飬��Ϊ������ 
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
* ��̬�滮��ʽ��ȡ 
*/ 
int dp_get_roadWays(int n, int p, int k, int m){
	if(n<2 || p<1 || p>n || m<1 || m>n){	//�߽����� 
		return 0;
	}
	return dp_get_ways(n, p, k, m);
}

/*
* ��̬�滮��������Ŀ�ĵ�m��ʼ����0~K���ܵ��������ķ�����ȫ������������ÿ��λ��
* ֻ����һ�Σ����ȡ�����λ��p�� ����k������ķ�����
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
	cout<<"**********ʹ�õݹ鷽ʽ************"<<endl;
	res = digui_get_roadWays(n, p, k , m);
	cout<<"    ---����"<<res<<"�ַ�������-----"<<endl;
	cout<<"********ʹ�ö�̬�滮��ʽ**********"<<endl;
	res = dp_get_roadWays(n, p, k , m);
	cout<<"    ---����"<<res<<"�ַ�������-----"<<endl;
}
