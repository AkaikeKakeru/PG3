#include <stdio.h>

//“ñ‚Â‚Ìˆø”‚©‚çA¬‚³‚¢‚Ù‚¤‚ğo—Í
template <typename Type>
Type Min(Type a, Type b) {
	if (a < b) {
		return a;
	}

	return b;
}

//charŒ^‚¾‚Á‚½‚ç
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
	double e = 90.1;
	double f = 23.4;
	char g = 'n';
	char h = 'm';

	printf("%d\n", Min<int>(a, b));
	printf("%1.2f\n", Min<float>(c, d));
	printf("%1.5f\n", Min<double>(e, f));
	if (Min<char>(g, h) == 0) {
		printf("”šˆÈŠO‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñ\n");
	}

	return 0;
}