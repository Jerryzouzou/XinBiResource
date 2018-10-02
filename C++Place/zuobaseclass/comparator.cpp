#include "allh.h"
using namespace std;

/*
* ����sort���������ݱȽ����������� 
*/

struct student {
    int id;
    int age;
    string name;
    student() : id(0), age(0) {}
    student(int i, int a, string s) : id(i), age(a), name(s) {}
};

/*
* ����Id�������� 
*/
static bool compareIdAsc(student* x, student* y) { 
    return (x->id < y->id); //sort by first element
}

/*
* ����Id������ 
*/
static bool compareIdDes(student* x, student* y) { 
    return (x->id > y->id); //sort by first element
}

/*
* ����Age�������� 
*/
static bool compareAgeAsc(student* x, student* y) { 
    return (x->age < y->age); //sort by first element
}

/*
* ����Age�������� 
*/
static bool compareAgeDes(student* x, student* y) { 
    return (x->age > y->age); //sort by first element
}

void print_studengs(student** students, int len){
	for(int i=0; i<len; i++){
		student* stuTmp = students[i];
		cout<<"Name:"<<stuTmp->name<<", age="<<stuTmp->age<<", id="<<stuTmp->id<<endl; 
	}
	cout<<"====================="<<endl;
}

void comparator_main(){
	//������vector����ֵ, ��ô�ȽϺ���ҲҪ�Ĳ���* 
	vector<student> data;
	data.push_back({1, 22, "xxx"});
	
	student* s1 = new student(1, 23, "stu_a");
	student* s2 = new student(3, 33, "stu_b");
	student* s3 = new student(2, 77, "stu_c");
	
	student* students[3] = {s1, s2, s3};
	
	cout<<"---------------ԭʼ����------------"<<endl;
	print_studengs(students, 3); 
	
	cout<<"----------����id���������----------"<<endl;
	sort(students, students+3, compareIdAsc);		//��ʼλ��Ԫ�ص�ַ������λ��Ԫ�ص�ַ+1;----���ǿ�ʼ����Ԫ�ػ�������  
	print_studengs(students, 3); 
	
	cout<<"----------����id���������---------"<<endl;
	sort(students, students+3, compareIdDes);
	print_studengs(students, 3); 
	
	cout<<"----------����age���������---------"<<endl;
	sort(students, students+3, compareAgeAsc);
	print_studengs(students, 3); 
	
	cout<<"----------����age���������--------"<<endl;
	sort(students, students+3, compareAgeDes);
	print_studengs(students, 3); 
	
}

/*
* ����Age�������� --��������� 
*/
struct cmp{
	bool operator()(student x, student y) { 		//һ��Ҫ����()() 
	    return (x.age > y.age); //sort by first element
	}
};

/*
*priority_queue  �Զ��������� 
*/
void priority_queue_comparator_main(){
	priority_queue<student, vector<student>, cmp> data_queue;
	data_queue.push({5, 22, "С��"});
	data_queue.push({1, 26, "С��"});
	data_queue.push({3, 18, "СѼ"});
	
	for(int i=0; i<3; i++){
		cout<<"id=="<<data_queue.top().id<<"--age=="<<data_queue.top().age<<"--name=="<<data_queue.top().name<<endl;
		data_queue.pop();
	} 
}








