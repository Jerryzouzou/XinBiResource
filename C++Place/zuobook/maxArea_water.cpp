#include "allh.h"
using namespace std;

/*
* 题目：给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，
* 垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。 
* 思路：定义两个指针，left和right，初始时，指向首部和尾部；计算两个指针之间的面积area1 = min(height[left]，height[right])*(right-left)；
*  height[left]和height[right]，谁小谁往里面走；返回循环中的最大值 
*/

int maxArea(vector<int>& height) {
    if(height.size() == 0){
        return 0;
    }
    int left=0, right=height.size()-1;
    int maxArea = 0;
        
    while(left < right){
        maxArea = max(maxArea, min(height[left], height[right])*(right-left));
        if(height[left] < height[right]){
            left++;
        }else{
            right--;
        }
    }

    return maxArea;
}

void maxArea_water_main(){
	int arr[9] = {1,8,6,2,5,4,8,3,7};
	vector<int> height(arr, arr+9);
	
	int res = maxArea(height);
	print_int_array(arr, 9);
	cout<<"的最大盛水量==="<<res<<endl;
}
