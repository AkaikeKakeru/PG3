#include <stdio.h>
#include <string.h>
#include <random>
#include <Windows.h>

typedef int (*newType)(int ans);

enum Number {
	EvenNum = 0,
	OddNum = 1,
	ErrorNum = 999,
};

int InputPredict(int ans);
void NowWait(newType pFunc, int ans ,int timer);
int Return(int ans);

int main(void) {
	int waitTimer = 3;
	int ans = EvenNum;

	newType pFunc = nullptr;

	pFunc = &InputPredict;

	ans = pFunc(ans);
	if (ans != ErrorNum) {
		printf_s("yŒ‹‰Ê‚Í...z\n");

		pFunc = &Return;
		NowWait(pFunc,ans,waitTimer);
	}

	return 0;
}

int InputPredict(int ans) {
	char str[10] = "‚«‚·‚¤";

	const char ODD[] = "Šï”";
	const char EVEN[] = "‹ô”";
	const char odd[] = "‚«‚·‚¤";
	const char even[] = "‚®‚¤‚·‚¤";

	printf_s("yŠï”‚©‹ô”‚©A—\‘z‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢z\n");
	scanf_s("%s", &str, 10);

	if (strcmp(str, ODD) == 0
		|| strcmp(str, odd) == 0) {
		ans = OddNum;

		printf_s("yŠï”‚Ì“ü—Í‚ğŠm”Fz\n\n");
		return ans;
	}

	if (strcmp(str, EVEN) == 0
		|| strcmp(str, even) == 0) {
		ans = EvenNum;

		printf_s("y‹ô”‚Ì“ü—Í‚ğŠm”Fz\n\n");
		return ans;
	}

	ans = ErrorNum;

	printf_s("y‘z’èŠO‚Ì“ü—Í‚ğŠm”Fz\n\n"
		"%d‚ªo—Í‚³‚ê‚Ü‚µ‚½\n", ans);
	return ans;
}

void NowWait(newType pFunc, int ans ,int timer) {
	Sleep(timer * 1000);

	pFunc(ans);
}

int Return(int ans) {
	//—”ƒV[ƒh¶¬Ší
	std::random_device seed_gen;
	//ƒƒ‹ƒZƒ“ƒkEƒcƒCƒXƒ^[‚Ì—”ƒGƒ“ƒWƒ“
	std::mt19937_64 engine(seed_gen());
	//—””ÍˆÍ
	std::uniform_real_distribution < float > dist(1, 10);

	int rand = static_cast<int>(dist(engine));

	printf_s("y%d‚ª‘Io‚³‚ê‚Ü‚µ‚½z\n\n", rand);

	rand = rand % 2;

	if (ans == rand) {
		printf_s("y“I’†‚Å‚·z\n");
		return true;
	}
	printf_s("yƒnƒYƒŒ‚Å‚·z\n");
	return false;
}