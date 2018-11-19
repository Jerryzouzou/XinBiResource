#include "allh.h"
using namespace std;

/*
* ��ֽ���⣺���ŵ�ֽ��ÿ�δ��������ۣ���һ�γ���һ�����ۺۣ�����ÿ�ζ�����һ��
* �ۺ��������������ۺۣ���ô��N�ξ��Ǹ߶�ΪN��������������ÿ���ڵ�����������ۺ� 
* �Һ��������ۺۡ��������´�ӡ�ۺ۾��Ƕ�������������� 
* ���Բ�������������ֱ������������ݹ鷽ʽ��ӡ 
*/

//value��1�������ۺ� ��2�������ۺ� 
struct Node{
	int value;
	Node* left;
	Node* right;
	Node(int a=0):value(a), left(NULL), right(NULL){};
};

/*
* i:��ӡ����i��
* N:���������
* down:��ӡdown����up 
*/
void printProcess(int i, int N, bool down){
	if(i > N){
		return;
	} 
	printProcess(i+1, N, true);
	if(down){
		cout<<"down"<<endl;
	}else{
		cout<<"up"<<endl;
	}
	printProcess(i+1, N, false);
}

void printAllFolds(int N){
	printProcess(1, N, true);
}

void tree_paperFolding_main(){
	int N = 4;
	printAllFolds(N);
}

