#include <stdio.h>
void PrintRecursive(int start,int remain) {
	printf("���� %d	: �c�� %d����\n",start,remain -1);
}

//�ċA�֐��ŁA�ċA�I�ȑ̐��̍��v�������v�Z
///<int n == �ċA������l>
///<int remain == �c��J�E���g>
int RecursiveParameter(int start,int remain) {
	//�c��̃J�E���g��0�Ȃ�I��
	if (remain <= 0) {
		//�ŏI�o��
		return 0;
	}

	//�r���o��
	PrintRecursive(start, remain);

	//�O��l��2�{���A50�������l���A���̈����Ƃ���
	return start + (RecursiveParameter((start * 2) - 50,remain-1));
}


int main(void)
{
	int normalSalary = 1072; //��ʓI�Ȓ����̐�
	int recursiveSalary; //�ċA�I�Ȓ����̐�
	int recursiveSalaryStart = 100; //�ċA�I�Ȓ����̐��̏����l
	int workingTime = 8; //�J������

	//�ċA�I�ȑ̐��̍��v�������Z�o
	recursiveSalary = RecursiveParameter(recursiveSalaryStart,workingTime);

	//��ʓI�ȑ̐��̍��v�������Z�o
	normalSalary *= workingTime;

	printf("\n");
	printf("�ċA�I�̐��̍��v���� = %d\n\n",recursiveSalary);
	printf("��ʑ̐��̍��v���� = %d\n\n",normalSalary);

	//��҂��r���A�ċA�I�̐��������������m�F
	if (normalSalary < recursiveSalary) {
		printf("�ċA�I�Ȓ����̐��̕����ׂ�������!\n");
	}

	//�I��
	return 0;
}