#include <stdio.h>
#include <string.h>
#include <random>

void Input();
bool NowWait(float time);
int Return(char* str);

int main(void)
{
	char str[] = "������";
	int ans;

	printf_s("���� = %s\n\n", str);

	ans = Return(str);

	printf_s("\nans = %d\n", ans);

	return 0;
}

bool NowWait(float time) {
	return true;
}

int Return(char* str) {
	const char ODD[] = "�";
	const char EVEN[] = "����";
	const char odd[] = "������";
	const char even[] = "��������";

	int ans = 0;

	if (strcmp(str, ODD) == 0
		|| strcmp(str, odd) == 0) {
		ans = 1;

		printf_s("�y��̓��͂��m�F�z\n"
			"%d���o�͂���܂���\n", ans);
		return ans;
	}

	if (strcmp(str, EVEN) == 0
		|| strcmp(str, even) == 0) {
		ans = 2;

		printf_s("�y�����̓��͂��m�F�z\n"
			"%d���o�͂���܂���\n", ans);
		return ans;
	}

	ans = 999;

	printf_s("�y�z��O�̓��͂��m�F�z\n"
		"%d���o�͂���܂���\n", ans);
	return ans;
}