#include <stdio.h>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main(){
	vector<float> f = {1.2,2.3,3.4};

	int size = f.size();

	for (int i = 0; i < size; i++){
		printf_s("%f\n",f[i]);
	}

	return 0;
}