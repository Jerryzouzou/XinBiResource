#include "allh.h"
using namespace std;

/*
* 利用sort函数，根据比较器各种排序 
*/

struct student {
    int id;
    int age;
    string name;
    student() : id(0), age(0) {}
    student(int i, int a, string s) : id(i), age(a), name(s) {}
};

/*
* 根据Id升序排序 
*/
static bool compareIdAsc(student* x, student* y) { 
    return (x->id < y->id); //sort by first element
}

/*
* 根据Id升序降序 
*/
static bool compareIdDes(student* x, student* y) { 
    return (x->id > y->id); //sort by first element
}

/*
* 根据Age升序排序 
*/
static bool compareAgeAsc(student* x, student* y) { 
    return (x->age < y->age); //sort by first element
}

/*
* 根据Age升序降序 
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
	//可以用vector来存值, 那么比较函数也要改不带* 
	vector<student> data;
	data.push_back({1, 22, "xxx"});
	
	student* s1 = new student(1, 23, "stu_a");
	student* s2 = new student(3, 33, "stu_b");
	student* s3 = new student(2, 77, "stu_c");
	
	student* students[3] = {s1, s2, s3};
	
	cout<<"---------------原始数据------------"<<endl;
	print_studengs(students, 3); 
	
	cout<<"----------根据id升序后数据----------"<<endl;
	sort(students, students+3, compareIdAsc);		//开始位置元素地址，结束位置元素地址+1;----不是开始结束元素或者索引  
	print_studengs(students, 3); 
	
	cout<<"----------根据id降序后数据---------"<<endl;
	sort(students, students+3, compareIdDes);
	print_studengs(students, 3); 
	
	cout<<"----------根据age升序后数据---------"<<endl;
	sort(students, students+3, compareAgeAsc);
	print_studengs(students, 3); 
	
	cout<<"----------根据age降序后数据--------"<<endl;
	sort(students, students+3, compareAgeDes);
	print_studengs(students, 3); 
	
}








