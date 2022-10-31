#include <stdio.h>
#include <string.h>
#include <random>

enum Number {
	EvenNum = 0,
	OddNum = 1,
	ErrorNum = 999,
};

int InputPredict(char* str);

bool NowWait(float time);
bool Return(int input);

int main(void)
{
	char str[10] = "きすう";
	int input = 0;
	bool judge = false;
	int waitTimer = 3 * 50;

	printf_s("【奇数か偶数か、予想を入力してください】\n");
	scanf_s("%s",&str,10);

	input = InputPredict(str);

	judge = Return(input);

	return 0;
}

int InputPredict(char* str) {
	const char ODD[] = "奇数";
	const char EVEN[] = "偶数";
	const char odd[] = "きすう";
	const char even[] = "ぐうすう";

	int ans = EvenNum;

	if (strcmp(str, ODD) == 0
		|| strcmp(str, odd) == 0) {
		ans = OddNum;

		printf_s("【奇数の入力を確認】\n\n");
		return ans;
	}

	if (strcmp(str, EVEN) == 0
		|| strcmp(str, even) == 0) {
		ans = EvenNum;

		printf_s("【偶数の入力を確認】\n\n");
		return ans;
	}

	ans = ErrorNum;

	printf_s("【想定外の入力を確認】\n\n"
		"%dが出力されました\n", ans);
	return ans;
}

bool NowWait(float time) {


	return true;
}

bool Return(int input) {
	//乱数シード生成器
	std::random_device seed_gen;
	//メルセンヌ・ツイスターの乱数エンジン
	std::mt19937_64 engine(seed_gen());
	//乱数範囲
	std::uniform_real_distribution < float > dist(1, 10);

	int ans = static_cast<int>(dist(engine));

	printf_s("【%dが選出されました】\n\n", ans);

	ans = ans % 2;

	if (input == ans) {
		printf_s("【的中です】\n");
		return true;
	}

		printf_s("【ハズレです】\n");
		return false;
}