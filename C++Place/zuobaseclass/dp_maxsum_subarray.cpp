#include "allh.h"
using namespace std;

/*
*给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
*输入: [-2,1,-3,4,-1,2,1,-5,4],输出: 6;解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/
int digui_subArray_max(vector<int>& nums, int i);

/*
* 动态规划： 
*/
int maxSubArray(vector<int>& nums) {
    int len=nums.size();
    int max = 0;
    int* dp = new int[len]();
    if(len<1){
        return 0;
    }else if(len == 1){
        return nums.at(0);
    }
    dp[0] = nums.at(0); 
    max = dp[0];
        
    for(int i=1; i<len; i++){
        dp[i] = nums.at(i)+(dp[i-1]>0 ? dp[i-1] : 0);
        max = max>dp[i] ? max : dp[i];
    }
    return max;
}


int digui_maxSubArray(vector<int>& nums) {
    int len=nums.size();
    if(len<1){
        return 0;
    }else if(len == 1){
        return nums.at(0);
    }
   
    return digui_subArray_max(nums, len-1);
}

static int maxt = 0;
int digui_subArray_max(vector<int>& nums, int i){
	//static int maxt = 0;
	//int maxt = 0;
	int res = 0;
	int temp = 0;
	if(i==0){
		return nums.at(0);
	}
	temp = digui_subArray_max(nums, i-1);
	res = temp>0 ? (temp+nums.at(i)) : nums.at(i);
	maxt = maxt>res ? maxt : res;
	//return maxt = max(maxt, nums.at(i)+(digui_subArray_max(nums, i-1)>0 ? digui_subArray_max(nums, i-1) : 0));
	return maxt;
}
    
void maxsum_subarr_main(){
	int res = 0;
    /*int _p_size = 0;
    cin >> _p_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _p;
    int _p_item;
    for(int _p_i=0; _p_i<_p_size; _p_i++) {
        cin >> _p_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _p.push_back(_p_item);
    }*/

	//示例数据 
	vector<int> _p;
    _p.push_back(-2);_p.push_back(1);_p.push_back(-3);_p.push_back(4);
	_p.push_back(-1);_p.push_back(2);_p.push_back(1);_p.push_back(-5);_p.push_back(4);
    
    cout<<"**********使用递归方式************"<<endl;
	res = digui_maxSubArray(_p);
	cout<<"    ---数组最大子序和为"<<res<<"-----"<<endl;
	cout<<"********使用动态规划方式**********"<<endl;
	res = maxSubArray(_p);
	cout<<"    ---数组最大子序和为"<<res<<"-----"<<endl;
}
