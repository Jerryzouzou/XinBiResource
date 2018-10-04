#include "allh.h"
using namespace std;

/*
* 之(Z)型打印数组 
* 两个指针指向开头，一个往右走（走到最右往下走），一个往下走（走到最下往右走）
* 直到两个指针相遇。每走一次的两点连线即为对角线，依次上到下，下到上轮询打印斜线 
*/

/*
* 之型打印：两个点指向开头，一个往右走（走到最右往下走），一个往下走（走到最下往右走）
* 直到两个点相遇。每走一次的两点连线即为对角线，依次上到下，下到上轮询打印斜线 
*/
void printMatrixZigZag(vector<vector<int> > matrix){
	int tR=0, tC=0, dR=0, dC=0;
	int endR=matrix.size()-1, endC=matrix[0].size()-1;
	bool fromUp = false;
	while(tR != endR+1){		//最后会在右下角相遇 
		printLevel(matrix, tR, tC, dR, dC, fromUp);
		tR = tC==endC ? tR+1 : tR;		//上面的点走到最右了就往下走,没有的话是往右走 
		tC = tC==endC ? tC : tC+1;
		dC = dR==endR ? dC+1 : dC;		//上面的点走到最下了就往右走，没有的话是往下走 
		dR = dR==endR ? dR : dR+1; 
		fromUp = !fromUp;
	}
	cout<<endl;	
} 

/*
*打印斜线 ；fromUp为true从上往左下打印，false是从下往右上打印 
*/
void printLevel(vector<vector<int> > matrix, int tR, int tC, int dR, int dC, bool fromUp){
	if(fromUp){
		while(tR != dR+1){
			cout<<matrix[tR++][tC--]<<" ";
		}
	}else{
		while(dC != tC+1){
			cout<<matrix[dR--][dC++]<<" ";
		}
	}
	//cout<<endl;
}

void printMatrixZigZag_main(){
	int data[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	vector<vector<int> > matrix(3, vector<int>(4,0));	//3*4的二维vector，所有元素为0
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			matrix[i][j] = data[i][j];
		}
	}
	printMatrixZigZag(matrix);
} 


