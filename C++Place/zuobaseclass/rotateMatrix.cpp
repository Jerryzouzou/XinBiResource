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
		rotateEdge(matrix, tR++, tC++, dR--, dC--);
	}
	//cout<<endl;
	//��ӡ	
} 

void rotateEdge(vector<vector<int> >& matrix, int tR, int tC, int dR, int dC){
	
}


