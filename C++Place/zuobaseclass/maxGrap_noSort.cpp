#include "allh.h"
using namespace std;

/*
*一个数组，找到两数之间最大差值（间隙） ,不使用排序的方式， 
* 数组N个数放入N+1个桶中，每个桶只寸放当前桶最大值和最小值，然后计算有数的桶之间的差值，取最大差值 
* 时间复杂度O(N)， 空间复杂度O(N) 
*/
int bucket_id(long num, long len, long min, long max);

int get_maxGrap(int* arr, int len){
	if(len < 2){
		return 0;
	}
	int maxi=arr[0], mini=arr[0], bid=0;		//maxi和mini不能初始化为0 
	for(int i=0; i<len; i++){
		maxi = max(maxi, arr[i]);
		mini = min(mini, arr[i]); 
	}
	if(maxi == mini){
		return 0;
	}
	//cout<<"max=="<<maxi<<"--min=="<<mini<<endl;
	bool* hasNum = new bool[len+1]();		//桶i是否有数 
	int* maxs = new int[len+1]();		//桶i的最大值 
	int* mins = new int[len+1]();		//桶i的最小值
	for(int i=0; i<len; i++){
		bid = bucket_id(arr[i], len, mini,maxi);	//获取对应的桶号，然后更新bid桶的最大值和最小值 
		//if(hasNum[bid]) cout<<"it is true"<<endl;
		maxs[bid] = hasNum[bid] ? max(arr[i], maxs[bid]) : arr[i];
		mins[bid] = hasNum[bid] ? min(arr[i], mins[bid]) : arr[i]; 
		//cout<<"num=="<<arr[i]<<"--bid=="<<bid<<"--maxi=="<<maxs[bid]<<"--mini=="<<mins[bid]<<endl;
		hasNum[bid] = true;
	} 
	int res=0, lastMax = maxs[0];
	for(int i=1; i<=len; i++){
		if(hasNum[i]){
			res = max(res, mins[i]-lastMax);	//i桶和前面有数的桶的大值的相差取最大 
			lastMax = maxs[i];
			//cout<<"res=="<<res<<"--lastMax"<<lastMax<<endl;
		}
	}
	return res;
}

//len个数len+1个桶，每个桶的范围是(max-min)/len，所以数字num对应的桶号如下表达式 
int bucket_id(long num, long len, long min, long max){
	return (int)((num-min)*len/(max-min));
}

//测试函数，排序然后遍历 
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

