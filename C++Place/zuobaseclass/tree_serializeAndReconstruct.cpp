#include "allh.h"
using namespace std;

/*
* ���������л��ͷ����л�---������ת��Ϊ�ַ������л�--��ͨ���ַ��������������
* �ݹ鷽ʽ��ǰ�������ʽ���л�������ӡʱ��Ϊ���л��ַ�����ֵ��Ϊ"v_"����ֵʱΪ"#_"
* �����л�ͬ��
* ������ȱ����������л����ö��п�����ȱ������Ȱ�ͷ�ڵ�ѹ����У�����ÿ��ѭ�����ȵ���ջ�������������жϣ�
* �ٷֱ�ѹ�����ң�Ȼ�������һ��ѭ�����������л������л� 
*/

struct Node{
	int value;
	Node* left;
	Node* right;
	Node(int a=0):value(a), left(NULL), right(NULL){};
};

static Node* reconPreOrder(queue<string>& qstr);

/*
* ǰ������ݹ鷽ʽ���л������� 
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
* �������л��ķ����л���Ҳ����ǰ������ݹ鷽ʽ�����л���һ������ô���л�����ô�����л� 
*/
static Node* reconByPreString(string preStr){
	vector<string> vstr = split(preStr, "_");
	queue<string> qstr;
	//�ö���������ڵ�ֵ�����к������ѵ� 
	for(int i=0; i<vstr.size()-1; i++){
		qstr.push(vstr[i]);
	} 
	
	return reconPreOrder(qstr);
}
/*
* �ݹ�ǰ������ķ����л� 
* Ҫ�����ô��ݻ�ָ�봫�ݣ���������������쳣 
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
* ������ȱ�����ʽ���л������� 
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
*ǰ��������ݹ鷽ʽ���ȴ�ӡ�ڵݹ����ұ� 
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
	cout<<"ԭʼ������ǰ�����---";
	preOrderRecur(head);
	cout<<endl;
	string res = serialByPre(head);
	cout<<"ǰ��������л�---"<<res<<endl;
	Node* head1 = reconByPreString(res);
	cout<<"�����л�������ǰ�����---";
	preOrderRecur(head1);
	cout<<endl;
	
	res = serialByLevel(head);
	cout<<"������ȱ������л�---"<<res<<endl;
	head1 = reconByLevelString(res);
	cout<<"�����л�������ǰ�����---";
	preOrderRecur(head1);
	cout<<endl;
}
