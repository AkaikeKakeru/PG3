#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main(){
	vector<string> f = {"a","b","c"};
	int size = f.size();

	for (vector<string>::iterator it_f = f.begin();
		it_f != f.end();
		it_f++){

		cout << *it_f << endl;
	}

	return 0;
}