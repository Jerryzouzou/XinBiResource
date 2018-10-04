#include "allh.h"
using namespace std;

void printEdge(vector<vector<int> > matrix, int tR, int tC, int dR, int dC);
/*
* תȦ��ӡ����
* ��ά�������飬����Χ�����Ŀ������θ������ϽǺ����½������γ�һ��������Ȧ
* ���δ�ӡÿ������ --�Ϻ������º�����һ�δ�ӡ 
*/
void spiralOrderPrint(vector<vector<int> > matrix){
	int tR=0, tC=0;
	int dR=matrix.size()-1, dC=matrix[0].size()-1;
	while(tR < dR){		//
		printEdge(matrix, tR++, tC++, dR--, dC--);	//���ϽǺ����½����м��ƣ��γ�СȦ 
	}
	//cout<<endl;
}  

/*
* �������ϽǺ����½��γɵľ������δ�ӡ�Ϻ������º�����һ 
*/
void printEdge(vector<vector<int> > matrix, int tR, int tC, int dR, int dC){
	if(tR == dR){		//ֻ��һ�ᣬ���ӡһ�� 
		for(int i=tC; i<=dC; i++){
			cout<<matrix[tR][i]<<" ";
		}
		cout<<endl;
	}else if(tC == dC){	//ֻ��һ�������ӡһ�� 
		for(int i=tR; i<=dR; i++){
			cout<<matrix[i][tC]<<" ";
		}
		cout<<endl;
	}else{
		int curR = tR;
		int curC = tC;
		while(curC != dC){		//�ȴ�ӡ���Ͻǵ����Ͻ� 
			cout<<matrix[tR][curC]<<" ";
			curC++;
		}
		while(curR != dR){		//��ӡ���Ͻǵ����½�
			cout<<matrix[curR][dC]<<" ";
			curR++;
		}
		while(curC != tC){		//��ӡ���½ǵ����½�
			cout<<matrix[dR][curC]<<" ";
			curC--;
		}
		while(curR != tR){		//��ӡ���½ǵ����Ͻ�
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
	cout<<"      ********����*********        "<<endl;
	printMatrix_vector(matrix); 
	cout<<"      ********תȦ��ӡ����*******  "<<endl;
	spiralOrderPrint(matrix);
	cout<<endl; 
}



