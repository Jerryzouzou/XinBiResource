#include "allh.h"
using namespace std;

void rotateEdge(vector<vector<int> >& matrix, int tR, int tC, int dR, int dC);
/*
* 正方形数组顺时针旋转90° 
* 二维矩阵数组，从外围到中心可以依次根据左上角和右下角坐标形成一个个矩形圈
* 依次依次旋转每个矩形 ，每个矩形四边对应点交换旋转--这个是正方形数组 
*/
void rotate_matrix(vector<vector<int> >& matrix){
	int tR=0, tC=0;
	int dR=matrix.size()-1, dC=matrix[0].size()-1;
	while(tR < dR){		//
		rotateEdge(matrix, tR++, tC++, dR--, dC--);	//左上角和右下角往中间移，形成小圈 
	}
	//cout<<endl;
} 

/*
* 分成dR-tR组，然后跳到对应的位置去 
*/
void rotateEdge(vector<vector<int> >& matrix, int tR, int tC, int dR, int dC){
	int groups = dR - tR;
	int tmp=0;
	for(int i=0; i<groups; i++){
		tmp = matrix[tR][tC+i];
		matrix[tR][tC+i] = matrix[dR-i][tC];
		matrix[dR-i][tC] = matrix[dR][dC-i];
		matrix[dR][dC-i] = matrix[tR+i][dC];
		matrix[tR+i][dC] = tmp;
	} 
}

void rotateMatrix_main(){
	int arr[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 },
				{ 13, 14, 15, 16 } };
	vector<vector<int> > matrix(4, vector<int>(4,0));
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			matrix[i][j] = arr[i][j];
		}
	}
	cout<<"      ********数组旋转前*********        "<<endl;
	printMatrix_vector(matrix); 
	cout<<"      ********数组旋转后*********        "<<endl;
	rotate_matrix(matrix);
	printMatrix_vector(matrix); 
} 


