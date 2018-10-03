#include "allh.h"
using namespace std;

/*
* 行列都排好序的二维M*N数组找某数 
* 从右上角数(0, N)开始找target，target大于该位置数往下走 
* target小于该位置数往左走，直到找到该数或到左下角确定找不到 
* 时间复杂度O(m+n) 
*/
