#include <stdio.h>

//Ä‹AŠÖ”‚ÅŠKæ‚ğo—Í
int Recursive(int n) {
	if (n <= 1) {
		return (1);
	}
	return (n * Recursive(n - 1));
}

int main(void)
{
	int n = 10; //ŠKæ‚·‚é’l
	int result; //ŒvZŒ‹‰Ê

	result = Recursive(n);
	printf("%d‚ÌŠKæ = %d\n", n, result);

	return 0;
}