#include "allh.h"
using namespace std;

/*
*һ�����飬�ҵ�����֮������ֵ����϶�� ,��ʹ������ķ�ʽ�� 
* ����N��������N+1��Ͱ�У�ÿ��Ͱֻ��ŵ�ǰͰ���ֵ����Сֵ��Ȼ�����������Ͱ֮��Ĳ�ֵ��ȡ����ֵ 
* ʱ�临�Ӷ�O(N)�� �ռ临�Ӷ�O(N) 
*/
int bucket_id(long num, long len, long min, long max);

int get_maxGrap(int* arr, int len){
	if(len < 2){
		return 0;
	}
	int maxi=arr[0], mini=arr[0], bid=0;		//maxi��mini���ܳ�ʼ��Ϊ0 
	for(int i=0; i<len; i++){
		maxi = max(maxi, arr[i]);
		mini = min(mini, arr[i]); 
	}
	if(maxi == mini){
		return 0;
	}
	//cout<<"max=="<<maxi<<"--min=="<<mini<<endl;
	bool* hasNum = new bool[len+1]();		//Ͱi�Ƿ����� 
	int* maxs = new int[len+1]();		//Ͱi�����ֵ 
	int* mins = new int[len+1]();		//Ͱi����Сֵ
	for(int i=0; i<len; i++){
		bid = bucket_id(arr[i], len, mini,maxi);	//��ȡ��Ӧ��Ͱ�ţ�Ȼ�����bidͰ�����ֵ����Сֵ 
		//if(hasNum[bid]) cout<<"it is true"<<endl;
		maxs[bid] = hasNum[bid] ? max(arr[i], maxs[bid]) : arr[i];
		mins[bid] = hasNum[bid] ? min(arr[i], mins[bid]) : arr[i]; 
		//cout<<"num=="<<arr[i]<<"--bid=="<<bid<<"--maxi=="<<maxs[bid]<<"--mini=="<<mins[bid]<<endl;
		hasNum[bid] = true;
	} 
	int res=0, lastMax = maxs[0];
	for(int i=1; i<=len; i++){
		if(hasNum[i]){
			res = max(res, mins[i]-lastMax);	//iͰ��ǰ��������Ͱ�Ĵ�ֵ�����ȡ��� 
			lastMax = maxs[i];
			//cout<<"res=="<<res<<"--lastMax"<<lastMax<<endl;
		}
	}
	return res;
}

//len����len+1��Ͱ��ÿ��Ͱ�ķ�Χ��(max-min)/len����������num��Ӧ��Ͱ�����±��ʽ 
int bucket_id(long num, long len, long min, long max){
	return (int)((num-min)*len/(max-min));
}

//���Ժ���������Ȼ����� 
int get_maxGrap_bySort(int* arr, int len){
	if(len < 2) return 0;
	int res = 0;
	sort(arr, arr+len);
	for(int i=1; i<len; i++){
		res = max(res, arr[i]-arr[i-1]);
	}
	return res;
}

void maxGrap_main(){
	string strRes = "";
	int testTime = 1000;//1000;
	int maxSize = 100;
	int maxValue = 100;
	bool succeed = true;
	for (int i = 0; i < testTime; i++) {
		int len = random(maxSize);
		int* arr1 = new int[len];
		int* arr2 = new int[len];
		generateRandomArray(arr1, len, maxValue);
		copy_array(arr1, arr2, len, len);
		
		if(get_maxGrap(arr1, len) != get_maxGrap_bySort(arr2, len)){
			succeed = false;
			print_int_array(arr1, len);
			break;
		}
		/*int res1 = get_maxGrap(arr1, len);
		int res2 = get_maxGrap_bySort(arr2, len);
		if(res1 != res2){
			succeed = false;
			cout<<"res1=="<<res1<<"--res2=="<<res2<<endl;
			print_int_array(arr1, len);print_int_array(arr2, len);
			break;
		}*/
	}
	strRes=succeed ? "Nice!" : "Fucking fucked!";
	cout<<strRes<<endl;
}

