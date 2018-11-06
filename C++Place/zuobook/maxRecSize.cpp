#include "allh.h"
using namespace std;

/*
* ��Ŀ����ά����ֻ��1 0����ֵ����ȫ��1�����о��������У�����������Ϊ1������
* ��ά����ֳ�һ��һ�У���ĳ��ʱ�Ӷ���ĳ���д�ֱ�ж��ٸ�1��������һ��������
* ��һά������ջ����ջ����ջ�͵ݼ�������ʱ��(i-k-1)*height[j]���㷵�����г��ֹ������ֵ
* iΪ��ǰλ�ã�jΪջ��ֵ��kΪ����ջ������ջ��ֵ�� 
*/

int maxRecFromBottom(vector<int> height);

int maxRexSize(vector<vector<int> > map){
	if(map.size()==0 || map[0].size()==0){
		return 0;
	}
	int maxArea = 0;
	vector<int> height(map[0].size());
	
	for(int i=0; i<map.size(); i++){
		for(int j=0; j<map[0].size(); j++){
			height[j] = map[i][j]==0 ? 0 : height[j]+1;		//����0Ҫ�������㣬��Ȼ������ȫ��1�ľ��� 
		}
		maxArea = max(maxRecFromBottom(height), maxArea);  //ȡ���п��ܵ����ֵ 
	}
	return maxArea;
} 

int maxRecFromBottom(vector<int> height){
	if(height.size() == 0){
		return 0;
	}
	int maxArea = 0;
	stack<int> st;
	for(int i=0; i<height.size(); i++){
		while((!st.empty()) && height[i]<=height[st.top()]){
			int j = st.top();
			st.pop();
			int k = st.empty() ? -1 : st.top();
			int curArea = (i - k - 1) * height[j];	//�������j�Ŀ��ܵ����
			maxArea = max(maxArea, curArea); 
		}
		st.push(i);
	}
	
	while(!st.empty()){
		int j = st.top();
		st.pop();
		int k = st.empty() ? -1 : st.top();
		int curArea = (height.size() - k - 1) * height[j];	//�������j�Ŀ��ܵ����
		maxArea = max(maxArea, curArea); 
	}
	
	return maxArea;
}

void maxRecSize_main(){
	vector<vector<int> > map(3, vector<int>(4));
	map[0][0] = 1; map[0][1] = 0; map[0][2] = 1; map[0][3] = 1;
	map[1][0] = 1; map[1][1] = 1; map[1][2] = 1; map[1][3] = 1;
	map[2][0] = 1; map[2][1] = 1; map[2][2] = 1; map[2][3] = 0;
	
	int size = maxRexSize(map);
	cout<<"���ε�1�ľ����������Ϊ---"<<size<<endl;
}

