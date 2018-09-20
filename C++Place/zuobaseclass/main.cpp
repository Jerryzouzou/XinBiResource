#include <iostream>
#include "allh.h"

using namespace std;


int main(int argc, char** argv) {
	
	cout<<"------------Ã°ÅÝ·¨ÅÅÐò------------" <<endl;
	bubble_main();		//Ã°ÅÝ·¨ÅÅÐò 
	cout<<"------------Ñ¡ÔñÅÅÐò------------" <<endl;
	select_sort_main();	//Ñ¡Ôñ·¨ÅÅÐò 
	cout<<"------------²åÈë·¨ÅÅÐò------------" <<endl;
	insertion_sort_main();	//²åÈë·¨ÅÅÐò 
	cout<<"------------¹é²¢·¨ÅÅÐò------------" <<endl;
	merge_sort_main();		//¹é²¢·¨ÅÅÐò 
	cout<<"------------¿ìËÙÅÅÐò·¨------------" <<endl;
	quick_sort_main();		//¿ìËÙÅÅÐò·¨ 
	cout<<"------------Í°ÅÅÐò--0~200 ------------" <<endl;
	bucket_sort_main();		//Í°ÅÅÐò--0~200 
	cout<<"------------¶þ²æÊ÷±éÀú------------" <<endl;
	pre_in_pos_2tree_traversal_main();		//¶þ²æÊ÷±éÀú 
	
	return 0;
}
