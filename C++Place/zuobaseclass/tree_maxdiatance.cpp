#include "allh.h"
using namespace std;

/*
* 二叉树的最大间隔
* 递归方式---ReturnData为当前节点为头的最大间隔和深度；分别得到left和right的
* ReturnData，当前节点的深度为较大深度+1，最大间隔为left的最大间隔、right的 
* 最大间隔、(left_deep+right_deep+1)的最大值即为当前节点为头结点的最大间隔 
*/
