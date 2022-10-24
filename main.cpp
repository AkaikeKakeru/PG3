#include <stdio.h>

//再帰関数で、再帰的な体制の合計賃金を計算
///<int n == 再帰させる値>
///<int remain == 残りカウント>
int RecursiveParameter(int start,int remain) {
	//残りのカウントが0なら終了
	if (remain <= 0) {
		//最終出力
		return 0;
	}

	printf("賃金 %d	: 残り %d時間\n",start,remain -1);

	//前回値を2倍し、50引いた値を、次の引数とする
	return start + (RecursiveParameter((start * 2) - 50,remain-1));
}

int CallRecursive(int start,int remain) {
	
	int a = RecursiveParameter(start,remain);

	return start;
}

int main(void)
{
	int normalSalary = 1072; //一般的な賃金体制

	int recursiveSalary; //再帰的な賃金体制

	int recursiveSalaryStart = 100; //再帰的な賃金体制の初期値

	int workingTime = 8; //労働時間

	//再帰的な体制の合計賃金を算出
	recursiveSalary = RecursiveParameter(recursiveSalaryStart,workingTime);
	printf("再帰的体制の合計賃金 = %d\n\n",recursiveSalary);

	//一般的な体制の合計賃金を算出
	normalSalary *= workingTime;
	printf("一般体制の合計賃金 = %d\n\n",normalSalary);

	//二者を比較し、再帰的体制が上回ったかを確認
	if (normalSalary < recursiveSalary) {
		printf("再帰的な賃金体制の方が儲かったよ!\n");
	}

	//終了
	return 0;
}