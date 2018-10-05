#include "allh.h"
using namespace std;

/*
* 行列都排好序的二维M*N数组找某数 
* 从右上角数(0, N)开始找target，target大于该位置数往下走 
* target小于该位置数往左走，直到找到该数或到左下角确定找不到 
* 时间复杂度O(m+n) 
*/

bool isContains(vector<vector<int> > matrix, int target){
	int row=0, col=matrix[0].size()-1;	//初始化点是右上角点
	while(row<matrix.size() && col>-1){
		if(matrix[row][col] == target){
			return true;
		}else if(target > matrix[row][col]){
			row++;
		}else{
			col--;
		}
	} 
	return false;
}

void findNumInSortedMatrix_main(){
	int arr[8][7] = { { 0, 1, 2, 3, 4, 5, 6 },// 0
				{ 10, 12, 13, 15, 16, 17, 18 },// 1
				{ 23, 24, 25, 26, 27, 28, 29 },// 2
				{ 44, 45, 46, 47, 48, 49, 50 },// 3
				{ 65, 66, 67, 68, 69, 70, 71 },// 4
				{ 96, 97, 98, 99, 100, 111, 122 },// 5
				{ 166, 176, 186, 187, 190, 195, 200 },// 6
				{ 233, 243, 321, 341, 356, 370, 380 } // 7
		};
	int target = 233;
	vector<vector<int> > matrix(8, vector<int>(7,0));
	for(int i=0; i<8; i++){
		for(int j=0; j<7; j++){
			matrix[i][j] = arr[i][j];
		}
	}
	cout<<"是否找到数=="<<(isContains(matrix, target)==1 ? "true":"false")<<endl;
}


