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
	char str[10] = "������";
	int input = 0;
	bool judge = false;
	int waitTimer = 3 * 50;

	printf_s("�y����������A�\�z����͂��Ă��������z\n");
	scanf_s("%s",&str,10);

	input = InputPredict(str);

	judge = Return(input);

	return 0;
}

int InputPredict(char* str) {
	const char ODD[] = "�";
	const char EVEN[] = "����";
	const char odd[] = "������";
	const char even[] = "��������";

	int ans = EvenNum;

	if (strcmp(str, ODD) == 0
		|| strcmp(str, odd) == 0) {
		ans = OddNum;

		printf_s("�y��̓��͂��m�F�z\n\n");
		return ans;
	}

	if (strcmp(str, EVEN) == 0
		|| strcmp(str, even) == 0) {
		ans = EvenNum;

		printf_s("�y�����̓��͂��m�F�z\n\n");
		return ans;
	}

	ans = ErrorNum;

	printf_s("�y�z��O�̓��͂��m�F�z\n\n"
		"%d���o�͂���܂���\n", ans);
	return ans;
}

bool NowWait(float time) {


	return true;
}

bool Return(int input) {
	//�����V�[�h������
	std::random_device seed_gen;
	//�����Z���k�E�c�C�X�^�[�̗����G���W��
	std::mt19937_64 engine(seed_gen());
	//�����͈�
	std::uniform_real_distribution < float > dist(1, 10);

	int ans = static_cast<int>(dist(engine));

	printf_s("�y%d���I�o����܂����z\n\n", ans);

	ans = ans % 2;

	if (input == ans) {
		printf_s("�y�I���ł��z\n");
		return true;
	}

		printf_s("�y�n�Y���ł��z\n");
		return false;
}