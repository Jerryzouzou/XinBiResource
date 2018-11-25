#include "allh.h"
using namespace std;

/*
* 实现一种RandomPool结构有三种功能：insert(key)--将某个key加入该结构且做到不重复加入
* delete(key)--将结构中的某个key移除；getRandom()--等概率随机返回结构中任何一个key
* 方法：使用两个map，一个是map(样本,index)，一个是map(index, 样本)和size；insert(key)
* 就是插入到两个map中，delete(key)是先通过key找到index，然后将最后一个index的值填入到
* 两个map中；getRandom()是先求出0~size的等概率数，然后找到对应样本 
*/
