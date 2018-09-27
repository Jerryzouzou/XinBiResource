#include "allh.h"
using namespace std;

/*
*����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
*����: [-2,1,-3,4,-1,2,1,-5,4],���: 6;����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��
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

	//ʾ������ 
	vector<int> _p;
    _p.push_back(-2);_p.push_back(1);_p.push_back(-3);_p.push_back(4);
	_p.push_back(-1);_p.push_back(2);_p.push_back(1);_p.push_back(-5);_p.push_back(4);
    
    cout<<"**********ʹ�õݹ鷽ʽ************"<<endl;
	//res = digui_get_roadWays(n, p, k , m);
	//cout<<"    ---����"<<res<<"�ַ�������-----"<<endl;
	cout<<"********ʹ�ö�̬�滮��ʽ**********"<<endl;
	res = maxSubArray(_p);
	cout<<"    ---������������Ϊ"<<res<<"-----"<<endl;
}
