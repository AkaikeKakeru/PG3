#include <stdio.h> //printf_s�g������
#include <random> //�����g������
#include <Windows.h> //Sleep�g������
#include <functional> //std::function�g������

//�֐��|�C���^�p��typedef�Ō^��p��
typedef int (*function)(int ans);

//�}�W�b�N�i���o�[�����炷���߂ɁA�o�͒l�ɖ��O��t����
typedef enum Number {
	EvenNum = 0,//���A����
	OddNum = 1, //���A�
	ErrorNum = 999,// �G���[
}Number;

//�����̃v���g�^�C�v
int InputPredict(int ans);
int ReturnResult(int ans);
void SetWaitTimer(function pFunc, int ans, int timer);

//���C��
int main(void) {
	int waitTimer = 3; //�^�C�}�[[second]
	int ans = EvenNum; //�v���C���[�́A���������̗\��

	function pFunc = nullptr; //�֐��|�C���^

	std::function<int(int)> fInput = [=](int ans) {
		char str[10] = "������"; //�v���C���[�̓��͕����z��

		const char ODD[] = "�"; //��r�p�����z��
		const char EVEN[] = "����"; //��r�p�����z��
		const char odd[] = "������"; //��r�p�����z��
		const char even[] = "��������"; //��r�p�����z��

		printf_s("�y����������A�\�z����͂��Ă��������z\n");

		//�������v���C���[�ɓ��͂�����
		scanf_s("%s", &str, 10);

		//�u��v�܂��́u�������v�Ɠ��͂��ꂽ�Ȃ�
		if (strcmp(str, ODD) == 0
			|| strcmp(str, odd) == 0) {

			// ans����ɐݒ�
			ans = OddNum;

			printf_s("�y��̓��͂��m�F�z\n\n");
			return ans;
		}

		//�u�����v�܂��́u���������v�Ɠ��͂��ꂽ�Ȃ�
		if (strcmp(str, EVEN) == 0
			|| strcmp(str, even) == 0) {

			// ans�������ɐݒ�
			ans = EvenNum;

			printf_s("�y�����̓��͂��m�F�z\n\n");
			return ans;
		}

		//����ȊO�͑S���G���[���͈����Őݒ�
		ans = ErrorNum;

		printf_s("�y�z��O�̓��͂��m�F�z\n\n"
			"%d���o�͂���܂���\n", ans);

		return ans;
	};

	std::function<int(int)> fResult = [=](int ans) {
		//�����V�[�h������
		std::random_device seed_gen;
		//�����Z���k�E�c�C�X�^�[�̗����G���W��
		std::mt19937_64 engine(seed_gen());
		//�����͈�
		std::uniform_int_distribution < int > dist(1, 6);

		// ������1�I�o
		int rand = static_cast<int>(dist(engine));

		printf_s("�y%d���I�o����܂����z\n\n", rand);

		// ��Ȃ�1�A�����Ȃ�0�ɂ���B
		rand = rand % 2;

		// ans�ƈ�v�����Ȃ�
		if (ans == rand) {
			printf_s("�y�I���ł��z\n");
			return true;
		}

		// ��v���Ȃ�������
		printf_s("�y�n�Y���ł��z\n");
		return false;
	};

	auto fTimer = [&](function pFunc, int ans, int timer) {
		//timer��second�ɕϊ����ApFunc�̋N����x�点��B
		Sleep(timer * 1000);

		//Sleep�I������ɋN��
		pFunc(ans);
	};

	//�\������͂���t�F�[�Y
	//�ǂݎ�������͂���Aans�� EvenNum �� OddNum ����
	ans = fInput(ans);

	//�G���[�i���o�[����Ȃ��Ȃ�
	if (ans != ErrorNum) {
		printf_s("�y���ʂ�...�z\n");

		//���ʂ��o�͂���t�F�[�Y
		//�ܑ̂Ԃ��Ă���fResult���N��
		fTimer(fResult(ans), ans, waitTimer);
	}

	//�I��
	return 0;
}

//�\������͂���t�F�[�Y
int InputPredict(int ans) {
	char str[10] = "������"; //�v���C���[�̓��͕����z��

	const char ODD[] = "�"; //��r�p�����z��
	const char EVEN[] = "����"; //��r�p�����z��
	const char odd[] = "������"; //��r�p�����z��
	const char even[] = "��������"; //��r�p�����z��

	printf_s("�y����������A�\�z����͂��Ă��������z\n");

	//�������v���C���[�ɓ��͂�����
	scanf_s("%s", &str, 10);

	//�u��v�܂��́u�������v�Ɠ��͂��ꂽ�Ȃ�
	if (strcmp(str, ODD) == 0
		|| strcmp(str, odd) == 0) {

		// ans����ɐݒ�
		ans = OddNum;

		printf_s("�y��̓��͂��m�F�z\n\n");
		return ans;
	}

	//�u�����v�܂��́u���������v�Ɠ��͂��ꂽ�Ȃ�
	if (strcmp(str, EVEN) == 0
		|| strcmp(str, even) == 0) {

		// ans�������ɐݒ�
		ans = EvenNum;

		printf_s("�y�����̓��͂��m�F�z\n\n");
		return ans;
	}

	//����ȊO�͑S���G���[���͈����Őݒ�
	ans = ErrorNum;

	printf_s("�y�z��O�̓��͂��m�F�z\n\n"
		"%d���o�͂���܂���\n", ans);

	return ans;
}

//�^�C�}�[���Z�b�g
void SetWaitTimer(function pFunc, int ans, int timer) {
	//timer��second�ɕϊ����ApFunc�̋N����x�点��B
	Sleep(timer * 1000);

	//Sleep�I������ɋN��
	pFunc(ans);
}

//���ʂ��o�͂���t�F�[�Y
int ReturnResult(int ans) {
	//�����V�[�h������
	std::random_device seed_gen;
	//�����Z���k�E�c�C�X�^�[�̗����G���W��
	std::mt19937_64 engine(seed_gen());
	//�����͈�
	std::uniform_int_distribution < int > dist(1, 6);

	// ������1�I�o
	int rand = static_cast<int>(dist(engine));

	printf_s("�y%d���I�o����܂����z\n\n", rand);

	// ��Ȃ�1�A�����Ȃ�0�ɂ���B
	rand = rand % 2;

	// ans�ƈ�v�����Ȃ�
	if (ans == rand) {
		printf_s("�y�I���ł��z\n");
		return true;
	}

	// ��v���Ȃ�������
	printf_s("�y�n�Y���ł��z\n");
	return false;
}