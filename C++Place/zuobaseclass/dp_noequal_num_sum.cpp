#include "allh.h"
using namespace std;

/*
* 小米笔试问题： 第一输入表示数组长度。第二输入数组代表不同金额的产品，第三个数表示要组合的金额 
* 数组每个金额只能用一次，输出是否能组合成功1/0 
* 通过率是78% 
*/

/*
* 首先数组包含的金额肯定是能组合成的，然后M以内 j - p.at(i)是能组合成的话，j也是能组合成的
* 存放所有M以内所有能组合成的金额，最后判断有没有M 
* 打印了最后一个符合的 
*/
bool miHomeGiftBag(vector < int > p, int M) {
    bool* dp = new bool[M + 1];
	//vector < int >* list = new vector < int > [M+1]; 
	vector < vector < int > > list(M+1);
	vector < int > tmp1;	
	for (int i = 0; i < p.size(); i++) {
		if (p.at(i) > M) {
			continue;
		}
		for (int j = M; j >= p.at(i); j--) {
			if (dp[j - p.at(i)]) {		//j - p.at(i)为true，则说明j - p.at(i)这个金额是能组合成的，那么j金额也是能组合成的 
				dp[j] = true;			//这样就能组合成的金额从小到大都依次递增，当前金额依赖前面子金额的结果 
				tmp1 = list[j-p.at(i)];
				tmp1.push_back(p.at(i));
				list[j] = tmp1;	
			}
		}
		dp[p.at(i)] = true;		//数组包含的金额肯定是能组合成的 
		tmp1.clear();
		tmp1.push_back(p.at(i));
		list[p.at(i)] = tmp1;
	}
	
	if(dp[M]){
		tmp1 = list[M];
		for(int i=0; i<tmp1.size(); i++){
			cout<<tmp1.at(i)<<" ";
		}
		cout<<endl;
	}	
	return dp[M]; 
}
    
void xiaomi_main(){
	bool res;

    /*int _p_size = 0;
    cin >> _p_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _p;
    int _p_item;
    for(int _p_i=0; _p_i<_p_size; _p_i++) {
        cin >> _p_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _p.push_back(_p_item);
    }


    int _M;
    cin >> _M;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');*/

	//示例数据 
	vector<int> _p;
	/*_p.push_back(99);_p.push_back(199);_p.push_back(1999);
	_p.push_back(10000);_p.push_back(39);_p.push_back(1499);
    int _M = 10238;*/
    _p.push_back(3);_p.push_back(7);_p.push_back(4);
	_p.push_back(8);_p.push_back(11);_p.push_back(5);
    int _M = 10;
    
    res = miHomeGiftBag(_p, _M);
	cout<<"---小米--res=="<<res<<endl;
}

