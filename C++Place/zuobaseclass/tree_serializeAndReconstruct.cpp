#include "allh.h"
using namespace std;

/*
* ���������л��ͷ����л�---������ת��Ϊ�ַ������л�--��ͨ���ַ��������������
* �ݹ鷽ʽ��ǰ�������ʽ���л�������ӡʱ��Ϊ���л��ַ�����ֵ��Ϊ"v_"����ֵʱΪ"#_"
* �����л�ͬ��
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
	cout<<endl;
	for(int i=0; i<vstr.size(); i++){
		qstr.push(vstr[i]);
		cout<<vstr[i];
	} 
	cout<<endl;
	return reconPreOrder(qstr);
}
/*
* �ݹ�ǰ������ķ����л� 
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
	cout<<"���л�---"<<res<<endl;
	Node* head1 = reconByPreString(res);
	preOrderRecur(head1);
	
}
