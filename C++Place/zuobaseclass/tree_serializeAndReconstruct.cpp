#include "allh.h"
using namespace std;

/*
* 二叉树序列化和反序列化---二叉树转化为字符串序列化--和通过字符串构造出二叉树
* 递归方式：前序遍历方式序列化，将打印时改为序列化字符串有值是为"v_"，无值时为"#_"
* 反序列化同理。
*  
*/

struct Node{
	int value;
	Node* left;
	Node* right;
	Node(int a=0):value(a), left(NULL), right(NULL){};
};

static Node* reconPreOrder(queue<string> qstr);

/*
* 前序遍历递归方式序列化二叉树 
*/
static string serialByPre(Node* head){
	if(head == NULL){
		return "#_";
	}
	string res, stmp;
	int2str(head->value, stmp);
	/*res.append(stmp);
	res.append("_");
	res.append(serialByPre(head->left));
	res.append(serialByPre(head->right));*/
	res += stmp;
	res += "_";
	res += serialByPre(head->left);
	res += serialByPre(head->right);
	
	return res;
}

/*
* 上面序列化的反序列化，也是用前序遍历递归方式反序列化，一般是怎么序列化就怎么反序列化 
*/
static Node* reconByPreString(string preStr){
	vector<string> vstr = split(preStr, "_");
	queue<string> qstr;
	//用队列来保存节点值，队列好做消费掉 
	cout<<endl;
	for(int i=0; i<vstr.size(); i++){
		qstr.push(vstr[i]);
		cout<<vstr[i];
	} 
	cout<<endl;
	return reconPreOrder(qstr);
}
/*
* 递归前序遍历的反序列化 
*/
static Node* reconPreOrder(queue<string> qstr){
	string value = qstr.front();
	qstr.pop();
	cout<<"cin val "<<value<<endl;
	if(value == "#"){
		//cout<<"cin # "<<endl;
		return NULL;
	}
	int itmp = 0;
	str2int(itmp, value);
	Node* head = new Node(itmp);
	//cout<<"head-val--"<<itmp<<endl;
	head->left = reconPreOrder(qstr);
//	if(!head->left){
//		cout<<"head-left--null"<<endl;
//	}else{
//		cout<<"head-left--"<<head->left->value<<endl;	
//	}
	
	head->right = reconPreOrder(qstr);
//	if(!head->right){
//		cout<<"head-right--null"<<endl;
//	}else{
//		cout<<"head-right--"<<head->right->value<<endl;
//	}
	
	return head;
}

/*
*前序遍历，递归方式，先打印在递归左右边 
*/
static void preOrderRecur(struct Node* head){
	if(head == NULL){
		return;
	}
	cout<<head->value<<" ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}

void tree_serializeAndReconstruct_main(){
	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->left = new Node(4);
	head->left->right = new Node(5);
	cout<<"原始二叉树前序遍历---";
	preOrderRecur(head);
	cout<<endl;
	string res = serialByPre(head);
	cout<<"序列化---"<<res<<endl;
	Node* head1 = reconByPreString(res);
	preOrderRecur(head1);
	
}
