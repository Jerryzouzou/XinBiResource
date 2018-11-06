#include "allh.h"
using namespace std;

/*
* 题目：二维数组只有1 0两种值，求全是1的所有矩形区域中，最大矩形区域为1的数量
* 二维数组分成一行一行，到某行时从顶到某行有垂直有多少个1保存在另一个数组中
* 对一维数组用栈保持栈顶到栈低递减，遍历时用(i-k-1)*height[j]计算返回所有出现过的最大值
* i为当前位置，j为栈顶值，k为弹出栈顶的新栈顶值。 
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
			height[j] = map[i][j]==0 ? 0 : height[j]+1;		//遇到0要重新清零，不然不符合全是1的矩形 
		}
		maxArea = max(maxRecFromBottom(height), maxArea);  //取所有可能的最大值 
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
			int curArea = (i - k - 1) * height[j];	//算的是以j的可能的面积
			maxArea = max(maxArea, curArea); 
		}
		st.push(i);
	}
	
	while(!st.empty()){
		int j = st.top();
		st.pop();
		int k = st.empty() ? -1 : st.top();
		int curArea = (height.size() - k - 1) * height[j];	//算的是以j的可能的面积
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
	cout<<"矩形的1的矩形最大数量为---"<<size<<endl;
}

