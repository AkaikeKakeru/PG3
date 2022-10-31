#include <stdio.h>
#include <string.h>
#include <random>

typedef int (*newType)(int ans);

enum Number {
	EvenNum = 0,
	OddNum = 1,
	ErrorNum = 999,
};

int InputPredict(int ans);
bool NowWait(float time);
int Return(int ans);

int main(void) {
	//char str[10] = "きすう";
	int input = 0;
	bool judge = false;
	int waitTimer = 3 * 50;
	int ans = EvenNum;

	newType pFunc = nullptr;

	pFunc = &InputPredict;

	pFunc(ans);
	if (ans != ErrorNum) {
		pFunc = &Return;
		pFunc(ans);
	}

	return 0;
}

int InputPredict(int ans) {
	char str[10] = "きすう";

	const char ODD[] = "奇数";
	const char EVEN[] = "偶数";
	const char odd[] = "きすう";
	const char even[] = "ぐうすう";

	printf_s("【奇数か偶数か、予想を入力してください】\n");
	scanf_s("%s", &str, 10);

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
	time--;

	if (time <= 0) {
		return true;
	}
	return false;
}

int Return(int ans) {
	//乱数シード生成器
	std::random_device seed_gen;
	//メルセンヌ・ツイスターの乱数エンジン
	std::mt19937_64 engine(seed_gen());
	//乱数範囲
	std::uniform_real_distribution < float > dist(1, 10);

	int rand = static_cast<int>(dist(engine));

	printf_s("【%dが選出されました】\n\n", rand);

	rand = rand % 2;

	if (ans == rand) {
		printf_s("【的中です】\n");
		return true;
	}
	printf_s("【ハズレです】\n");
	return false;
}