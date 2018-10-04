#include "allh.h"
using namespace std;

void printEdge(vector<vector<int> > matrix, int tR, int tC, int dR, int dC);
/*
* 转圈打印数组
* 二维矩阵数组，从外围到中心可以依次根据左上角和右下角坐标形成一个个矩形圈
* 依次打印每个矩形 --上横右竖下横左竖一次打印 
*/
void spiralOrderPrint(vector<vector<int> > matrix){
	int tR=0, tC=0;
	int dR=matrix.size()-1, dC=matrix[0].size()-1;
	while(tR < dR){		//
		printEdge(matrix, tR++, tC++, dR--, dC--);	//左上角和右下角往中间移，形成小圈 
	}
	//cout<<endl;
}  

/*
* 根据左上角和右下角形成的矩形依次打印上横右竖下横左竖一 
*/
void printEdge(vector<vector<int> > matrix, int tR, int tC, int dR, int dC){
	if(tR == dR){		//只有一横，则打印一横 
		for(int i=tC; i<=dC; i++){
			cout<<matrix[tR][i]<<" ";
		}
		cout<<endl;
	}else if(tC == dC){	//只有一竖，则打印一竖 
		for(int i=tR; i<=dR; i++){
			cout<<matrix[i][tC]<<" ";
		}
		cout<<endl;
	}else{
		int curR = tR;
		int curC = tC;
		while(curC != dC){		//先打印左上角到右上角 
			cout<<matrix[tR][curC]<<" ";
			curC++;
		}
		while(curR != dR){		//打印右上角到右下角
			cout<<matrix[curR][dC]<<" ";
			curR++;
		}
		while(curC != tC){		//打印右下角到左下角
			cout<<matrix[dR][curC]<<" ";
			curC--;
		}
		while(curR != tR){		//打印左下角到左上角
			cout<<matrix[curR][tC]<<" ";
			curR--;
		}
	}
}

void printMatrixSpiralOrdar_main(){
	int arr[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 },
				{ 13, 14, 15, 16 } };
	vector<vector<int> > matrix(4, vector<int>(4,0));
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			matrix[i][j] = arr[i][j];
		}
	}
	cout<<"      ********数组*********        "<<endl;
	printMatrix_vector(matrix); 
	cout<<"      ********转圈打印数组*******  "<<endl;
	spiralOrderPrint(matrix);
	cout<<endl; 
}



