#include <stdio.h>

//再帰関数で、再帰的な体制の合計賃金を計算
///<int n == 再帰させる値>
///<int remain == 残りカウント>
int Recursive(int n, int remain) {
	//残りカウントを減らす
	remain--;

	//途中結果をプリントしておく
	printf("現賃金 = %d,残り = %d\n",
		n,remain);

	//残りのカウントが0なら終了
	if (remain <= 0) {
		printf("\n");

		//最終出力
		return n;
	}

	//前回の値を2倍し、50引いた値を、次の引数とする
	return Recursive((2*n)-50,remain);
}

int main(void)
{
	int normalSalary = 1072; //一般的な賃金体制

	int recursiveSalary = 100; //再帰的な賃金体制の初期値
	int result; //計算結果

	int workingTime = 9; //労働時間

	//再帰的な体制の合計賃金を算出
	result = Recursive(recursiveSalary,workingTime);
	printf("再帰的体制の合計賃金 = %d\n\n",result);

	//一般的な体制の合計賃金を算出
	normalSalary *= workingTime;
	printf("一般体制の合計賃金 = %d\n\n",normalSalary);

	//二者を比較し、再帰的体制が上回ったかを確認
	if (normalSalary < result) {
		printf("再帰的な賃金体制の方が儲かったよ!\n");
	}

	//終了
	return 0;
}