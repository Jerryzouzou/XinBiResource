#include "allh.h"
using namespace std;

/*
* ʵ��һ��RandomPool�ṹ�����ֹ��ܣ�insert(key)--��ĳ��key����ýṹ���������ظ�����
* delete(key)--���ṹ�е�ĳ��key�Ƴ���getRandom()--�ȸ���������ؽṹ���κ�һ��key
* ������ʹ������map��һ����map(����,index)��һ����map(index, ����)��size��insert(key)
* ���ǲ��뵽����map�У�delete(key)����ͨ��key�ҵ�index��Ȼ�����һ��index��ֵ���뵽
* ����map�У�getRandom()�������0~size�ĵȸ�������Ȼ���ҵ���Ӧ���� 
*/
