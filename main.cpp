#include <stdio.h>
template <typename Type>
Type Min(Type a, Type b) {
	if (a < b) {
		return a;
	}

	return b;
}

template <>
char Min<char>(char a, char b) {
	return 0;
}

int main(void)
{
	int a = 12;
	int b = 34;
	float c = 5.6f;
	float d = 7.8f;
	double e = 90.00001f;
	double f = 23.00004f;
	char g = '5';
	char h = '8';

	printf("%d\n", Min<int>(a, b));
	printf("%1.2f\n", Min<float>(c, d));
	printf("%1.5f\n", Min<double>(e, f));
	printf("”šˆÈŠO‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñ\n", Min<char>(g,h));
	
	return 0;
}