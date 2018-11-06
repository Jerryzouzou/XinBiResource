#include "allh.h"
using namespace std;

/*
* ���������MaxTree, �������У�ÿ���ڵ㶼���ӽڵ�����ɷ���ԭ������£�
* 1.ÿһ�����ĸ��ڵ���������ߵ�һ��������������ұߵ�һ������������бȽ�С���Ǹ�
* 2.���һ������ߺ��ұ߶�û�б����������˵������ͷ��� 
* ����ջ��һ�������߱����������һ������ұ߱������������ջΪ--�����ұ���ʱ��ջ������С
* ʱ���ϵ���֪��ջ�����������û������ջ�б��ֵݼ�����,Ȼ����map����ÿ���ڵ��Ӧ��ߵ�һ���������
* �ұߴ���� 
*/

struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int n=0): val(n), left(NULL), right(NULL){};
	bool operator < (const Node &a)const
    {
        return val < a.val;
    }
};

void popStackSetMap(stack<Node*>& mStack, map<Node*, Node*>& mMap);

static Node* getMaxTree(vector<int> arr){
	vector<Node*> nArr;//(arr.size());
	for(int i=0; i<arr.size(); i++){
		//nArr[i] = new Node(arr[i]);
		nArr.push_back(new Node(arr[i]));
	}
	stack<Node*> mStack;
	map<Node*, Node*> lBigMap;		//�����ߴ�ֵ 
	map<Node*, Node*> rBigMap;		//����ұߴ�ֵ
	for(int i=0; i<arr.size(); i++){
		Node* curNode = nArr[i];
		//ջ�ǵݼ�����ģ�ջ��С�ڵ�ǰ�ڵ�ʱ����ȥջ�н�ջ����Ӧ����ߵ�һ����Ľڵ��ϵ 
		//Ȼ�󽫵�ǰ�ڵ����ջ���У�ʹ��ջ���ֵݼ�������һ��һ�����ڵ��Ӧ��ߵ�һ����Ľڵ��Һ÷���map�� 
		while((!mStack.empty()) && mStack.top()->val < curNode->val){
			popStackSetMap(mStack, lBigMap);
		}
		mStack.push(curNode);
	}
	//û���µĽڵ��ˣ���ջ�л�δ����Ľڵ�����ҵ���Ӧ��ϵ��ߵ�һ����Ľڵ� 
	while(!mStack.empty()){
		popStackSetMap(mStack, lBigMap);
	} 
	
	for(int i=arr.size()-1; i>=0; i--){
		Node* curNode = nArr[i];
		while((!mStack.empty()) && mStack.top()->val < curNode->val){
			popStackSetMap(mStack, rBigMap);
		}
		mStack.push(curNode);
	}
	while(!mStack.empty()){
		popStackSetMap(mStack, rBigMap);
	} 
	Node* head = NULL;
	for(int i=0; i<arr.size(); i++){
		Node* curNode = nArr[i];
		Node* left = lBigMap[curNode];
		Node* right = rBigMap[curNode];
		if(left==NULL && right==NULL){
			head = curNode;
		}else if(left == NULL){
			if(right->left == NULL){
				right->left = curNode;
			}else{
				right->right = curNode;
			}
		}else if(right == NULL){
			if(left->left == NULL){
				left->left = curNode;
			}else{
				left->right = curNode;
			}
		}else{
			Node* parent = left->val<right->val ? left : right;
			if(parent->left == NULL){
				parent->left = curNode;
			}else{
				parent->right = curNode;
			}
		}
	}
	return head;
}

void popStackSetMap(stack<Node*>& mStack, map<Node*, Node*>& mMap){
	Node* popNode = mStack.top();
	mStack.pop();
	if(mStack.empty()){
		mMap.insert(pair<Node*, Node*>(popNode, NULL));
	}else{
		mMap.insert(pair<Node*, Node*>(popNode, mStack.top()));
	}
} 

/*
*ǰ�������
*/
void preOrderRecur(struct Node* head){
	if(head == NULL){
		return;
	}
	cout<<head->val<<" ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}

void maxTree_main(){
	vector<int> arr;
	arr.push_back(3);arr.push_back(4);arr.push_back(5);arr.push_back(1);arr.push_back(2);
	
	cout<<"��������maxTree---ԭ����==3 4 5 1 2"<<endl;
	Node* head = getMaxTree(arr);
	preOrderRecur(head);
}


