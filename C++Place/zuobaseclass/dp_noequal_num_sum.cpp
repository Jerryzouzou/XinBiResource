#include "allh.h"
using namespace std;

/*
* С�ױ������⣺ ��һ�����ʾ���鳤�ȡ��ڶ������������ͬ���Ĳ�Ʒ������������ʾҪ��ϵĽ�� 
* ����ÿ�����ֻ����һ�Σ�����Ƿ�����ϳɹ�1/0 
* ͨ������78% 
*/

/*
* ������������Ľ��϶�������ϳɵģ�Ȼ��M���� j - p.at(i)������ϳɵĻ���jҲ������ϳɵ�
* �������M������������ϳɵĽ�����ж���û��M 
* ��ӡ�����һ�����ϵ� 
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
			if (dp[j - p.at(i)]) {		//j - p.at(i)Ϊtrue����˵��j - p.at(i)������������ϳɵģ���ôj���Ҳ������ϳɵ� 
				dp[j] = true;			//����������ϳɵĽ���С�������ε�������ǰ�������ǰ���ӽ��Ľ�� 
				tmp1 = list[j-p.at(i)];
				tmp1.push_back(p.at(i));
				list[j] = tmp1;	
			}
		}
		dp[p.at(i)] = true;		//��������Ľ��϶�������ϳɵ� 
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

	//ʾ������ 
	vector<int> _p;
	/*_p.push_back(99);_p.push_back(199);_p.push_back(1999);
	_p.push_back(10000);_p.push_back(39);_p.push_back(1499);
    int _M = 10238;*/
    _p.push_back(3);_p.push_back(7);_p.push_back(4);
	_p.push_back(8);_p.push_back(11);_p.push_back(5);
    int _M = 10;
    
    res = miHomeGiftBag(_p, _M);
	cout<<"---С��--res=="<<res<<endl;
}

