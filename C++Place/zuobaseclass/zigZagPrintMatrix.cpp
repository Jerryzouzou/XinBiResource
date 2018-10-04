#include "allh.h"
using namespace std;

/*
* ֮(Z)�ʹ�ӡ���� 
* ����ָ��ָ��ͷ��һ�������ߣ��ߵ����������ߣ���һ�������ߣ��ߵ����������ߣ�
* ֱ������ָ��������ÿ��һ�ε��������߼�Ϊ�Խ��ߣ������ϵ��£��µ�����ѯ��ӡб�� 
*/

/*
* ֮�ʹ�ӡ��������ָ��ͷ��һ�������ߣ��ߵ����������ߣ���һ�������ߣ��ߵ����������ߣ�
* ֱ��������������ÿ��һ�ε��������߼�Ϊ�Խ��ߣ������ϵ��£��µ�����ѯ��ӡб�� 
*/
void printMatrixZigZag(vector<vector<int> > matrix){
	int tR=0, tC=0, dR=0, dC=0;
	int endR=matrix.size()-1, endC=matrix[0].size()-1;
	bool fromUp = false;
	while(tR != endR+1){		//���������½����� 
		printLevel(matrix, tR, tC, dR, dC, fromUp);
		tR = tC==endC ? tR+1 : tR;		//����ĵ��ߵ������˾�������,û�еĻ��������� 
		tC = tC==endC ? tC : tC+1;
		dC = dR==endR ? dC+1 : dC;		//����ĵ��ߵ������˾������ߣ�û�еĻ��������� 
		dR = dR==endR ? dR : dR+1; 
		fromUp = !fromUp;
	}
	cout<<endl;	
} 

/*
*��ӡб�� ��fromUpΪtrue���������´�ӡ��false�Ǵ��������ϴ�ӡ 
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
	vector<vector<int> > matrix(3, vector<int>(4,0));	//3*4�Ķ�άvector������Ԫ��Ϊ0
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			matrix[i][j] = data[i][j];
		}
	}
	printMatrixZigZag(matrix);
} 


