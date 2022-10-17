#include <stdio.h>
#include <string.h>
#include <random>

void Input();
bool NowWait(float time);
int Return(char* str);

int main(void)
{
	char str[] = "きすう";
	int ans;

	printf_s("入力 = %s\n\n", str);

	ans = Return(str);

	printf_s("\nans = %d\n", ans);

	return 0;
}

bool NowWait(float time) {
	return true;
}

int Return(char* str) {
	const char ODD[] = "奇数";
	const char EVEN[] = "偶数";
	const char odd[] = "きすう";
	const char even[] = "ぐうすう";

	int ans = 0;

	if (strcmp(str, ODD) == 0
		|| strcmp(str, odd) == 0) {
		ans = 1;

		printf_s("【奇数の入力を確認】\n"
			"%dが出力されました\n", ans);
		return ans;
	}

	if (strcmp(str, EVEN) == 0
		|| strcmp(str, even) == 0) {
		ans = 2;

		printf_s("【偶数の入力を確認】\n"
			"%dが出力されました\n", ans);
		return ans;
	}

	ans = 999;

	printf_s("【想定外の入力を確認】\n"
		"%dが出力されました\n", ans);
	return ans;
}