#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

//int main(){
//	vector<string> f = {"a","b","c"};
//	int size = f.size();
//
//	for (vector<string>::iterator it_f = f.begin();
//		it_f != f.end();
//		it_f++){
//
//		cout << *it_f << endl;
//	}
//
//	return 0;
//}

//int main(){
//	list <int> lst{1,2,3,4,5};
//
//	int size = lst.size();
//
//	for (auto it_f = lst.begin();
//		it_f != lst.end();
//		it_f++){
//
//		cout << *it_f << "\n";
//	}
//
//	return 0;
//}

int main(){
	list <string> lst{
		"Tokyo","Kanda","Akihabara","Okachimachi","Ueno",
		"Uguisudani","Nippori","Nishi-Nippori","Tabata","Komagome",
		"Sugamo","Otsuka","Ikebukuro","Mejiro","Takadanobaba",
		"Shin-Okubo","Shinjuku","Yoyogi","Harajuku","Shibuya",
		"Ebisu","Meguro","Gotanda","Osaki","Shinagawa",
		"Takanawa Gateway","Tamachi","Hamamatsucho","Shimbashi","Yurakucho"
	};

	int size = lst.size();

	for (auto it_f = lst.begin();
		it_f != lst.end();
		it_f++){

		cout << *it_f << "\n";
	}

	return 0;
}