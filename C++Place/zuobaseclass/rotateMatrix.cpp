#include "allh.h"
using namespace std;

void rotateEdge(vector<vector<int> >& matrix, int tR, int tC, int dR, int dC);
/*
* ����������˳ʱ����ת90�� 
* ��ά�������飬����Χ�����Ŀ������θ������ϽǺ����½������γ�һ��������Ȧ
* ����������תÿ������ ��ÿ�������ı߶�Ӧ�㽻����ת--��������������� 
*/
void rotate_matrix(vector<vector<int> >& matrix){
	int tR=0, tC=0;
	int dR=matrix.size()-1, dC=matrix[0].size()-1;
	while(tR < dR){		//
		rotateEdge(matrix, tR++, tC++, dR--, dC--);	//���ϽǺ����½����м��ƣ��γ�СȦ 
	}
	//cout<<endl;
} 

/*
* �ֳ�dR-tR�飬Ȼ��������Ӧ��λ��ȥ 
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
	cout<<"      ********������תǰ*********        "<<endl;
	printMatrix_vector(matrix); 
	cout<<"      ********������ת��*********        "<<endl;
	rotate_matrix(matrix);
	printMatrix_vector(matrix); 
} 


