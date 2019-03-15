#include "allh.h"
using namespace std;

/*
* ��Ŀ������ n ���Ǹ����� a1��a2��...��an��ÿ�������������е�һ���� (i, ai) ���������ڻ� n ����ֱ�ߣ�
* ��ֱ�� i �������˵�ֱ�Ϊ (i, ai) �� (i, 0)���ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ�� 
* ˼·����������ָ�룬left��right����ʼʱ��ָ���ײ���β������������ָ��֮������area1 = min(height[left]��height[right])*(right-left)��
*  height[left]��height[right]��˭С˭�������ߣ�����ѭ���е����ֵ 
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
	cout<<"�����ʢˮ��==="<<res<<endl;
}
