#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main(){
	vector<float> f = {1.2,2.3,3.4};
	int size = f.size();

	vector<float>::iterator it;
	it = f.begin();

	cout << *it << endl;

	it++;

	cout << *it << endl;

	it++;

	cout << *it << endl;

	return 0;
}