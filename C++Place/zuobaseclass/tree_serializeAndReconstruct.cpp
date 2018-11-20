#include "allh.h"
using namespace std;

/*
* 二叉树序列化和反序列化---二叉树转化为字符串序列化--和通过字符串构造出二叉树
* 递归方式：前序遍历方式序列化，将打印时改为序列化字符串有值是为"v_"，无值时为"#_"
* 反序列化同理。
* 宽度优先遍历按层序列化：用队列宽度优先遍历，先把头节点压入队列，后面每次循环都先弹出栈顶做上面条件判断，
* 再分别压入左右，然后进行下一次循环，进行序列化或反序列化 
*/

struct Node{
	int value;
	Node* left;
	Node* right;
	Node(int a=0):value(a), left(NULL), right(NULL){};
};

static Node* reconPreOrder(queue<string>& qstr);

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
	for(int i=0; i<vstr.size()-1; i++){
		qstr.push(vstr[i]);
	} 
	
	return reconPreOrder(qstr);
}
/*
* 递归前序遍历的反序列化 
* 要用引用传递或按指针传递，否则队列消耗有异常 
*/
static Node* reconPreOrder(queue<string>& qstr){
	string value = qstr.front();
	qstr.pop();
	//cout<<"cin val "<<value<<endl;
	if(value == "#"){
		return NULL;
	}
	int itmp = 0;
	str2int(itmp, value);
	Node* head = new Node(itmp);
	head->left = reconPreOrder(qstr);
	head->right = reconPreOrder(qstr);
	
	return head;
}

/*
* 宽度优先遍历方式序列化二叉树 
*/
static string serialByLevel(Node* head){
	if(head == NULL){
		return "#_";
	}
	string res, stmp;
	int2str(head->value, stmp);
	res += stmp;
	res += "_";
	queue<Node*> mqueue;
	mqueue.push(head);
	while(!mqueue.empty()){
		head = mqueue.front();
		mqueue.pop();
		if(head->left != NULL){
			int2str(head->left->value, stmp);
			res += stmp;
			res += "_";
			mqueue.push(head->left);
		}else{
			res += "#_";
		}
		if(head->right != NULL){
			int2str(head->right->value, stmp);
			res += stmp;
			res += "_";
			mqueue.push(head->right);
		}else{
			res += "#_";
		}
	}
	return res;
}

static Node* generateNodeByString(string val){
	if(val == "#"){
		return NULL;
	}
	int itmp = 0;
	str2int(itmp, val);
	return new Node(itmp);
}

static Node* reconByLevelString(string levelStr){
	vector<string> vstr = split(levelStr, "_");
	int index = 0;
	Node* head = generateNodeByString(vstr[index++]);
	queue<Node*> mqueue;
	if(head != NULL){
		mqueue.push(head);
	}
	Node* cur = NULL;
	while(!mqueue.empty()){
		cur = mqueue.front();
		mqueue.pop();
		cur->left = generateNodeByString(vstr[index++]);
		cur->right = generateNodeByString(vstr[index++]);
		if(cur->left != NULL){
			mqueue.push(cur->left);
		}
		if(cur->right != NULL){
			mqueue.push(cur->right);
		}
	}
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
	cout<<"前序遍历序列化---"<<res<<endl;
	Node* head1 = reconByPreString(res);
	cout<<"反序列化二叉树前序遍历---";
	preOrderRecur(head1);
	cout<<endl;
	
	res = serialByLevel(head);
	cout<<"宽度优先遍历序列化---"<<res<<endl;
	head1 = reconByLevelString(res);
	cout<<"反序列化二叉树前序遍历---";
	preOrderRecur(head1);
	cout<<endl;
}
