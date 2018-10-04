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
		rotateEdge(matrix, tR++, tC++, dR--, dC--);
	}
	//cout<<endl;
	//打印	
} 

void rotateEdge(vector<vector<int> >& matrix, int tR, int tC, int dR, int dC){
	
}


