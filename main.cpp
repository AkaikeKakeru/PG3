#include <stdio.h>

//�ċA�֐��ŁA�ċA�I�ȑ̐��̍��v�������v�Z
///<int n == �ċA������l>
///<int remain == �c��J�E���g>
int Recursive(int n, int remain) {
	//�c��J�E���g�����炷
	remain--;

	//�r�����ʂ��v�����g���Ă���
	printf("������ = %d,�c�� = %d\n",
		n,remain);

	//�c��̃J�E���g��0�Ȃ�I��
	if (remain <= 0) {
		printf("\n");

		//�ŏI�o��
		return n;
	}

	//�O��̒l��2�{���A50�������l���A���̈����Ƃ���
	return Recursive((2*n)-50,remain);
}

int main(void)
{
	int normalSalary = 1072; //��ʓI�Ȓ����̐�

	int recursiveSalary = 100; //�ċA�I�Ȓ����̐��̏����l
	int result; //�v�Z����

	int workingTime = 9; //�J������

	//�ċA�I�ȑ̐��̍��v�������Z�o
	result = Recursive(recursiveSalary,workingTime);
	printf("�ċA�I�̐��̍��v���� = %d\n\n",result);

	//��ʓI�ȑ̐��̍��v�������Z�o
	normalSalary *= workingTime;
	printf("��ʑ̐��̍��v���� = %d\n\n",normalSalary);

	//��҂��r���A�ċA�I�̐��������������m�F
	if (normalSalary < result) {
		printf("�ċA�I�Ȓ����̐��̕����ׂ�������!\n");
	}

	//�I��
	return 0;
}