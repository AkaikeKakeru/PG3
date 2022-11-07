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

	//前回値を2倍し、50引いた値を、次の引数とする
	return start + (RecursiveParameter((start * 2) - 50,remain-1));
}

int main(void){
	///宣言
	int normalSalary = 1072; //一般的な賃金体制
	int recursiveSalary; //再帰的な賃金体制
	int recursiveSalaryStart = 100; //再帰的な賃金体制の初期値
	int workingTime = 8; //労働時間

	///更新
	//再帰的な体制の合計賃金を算出
	recursiveSalary = RecursiveParameter(recursiveSalaryStart,workingTime);

	//一般的な体制の合計賃金を算出
	normalSalary *= workingTime;

	///記述
	//workingTime回繰り返す
	for (int i = workingTime; i > 0; i--){
		int remain = i - 1; //残り労働時間
		static int nowSalary = recursiveSalaryStart;

		//途中経過
		printf("賃金 %d	: 残り %d時間\n",nowSalary,remain);

		//残り労働時間が0なら終了
		if (remain <= 0) {
			break;
		}

		//前回値を2倍し、50引いた値を、次の引数とする
		nowSalary = nowSalary * 2 - 50;
	}

	printf("\n");
	printf("再帰的体制の合計賃金 = %d\n\n",recursiveSalary);
	printf("一般体制の合計賃金 = %d\n\n",normalSalary);

	//二者を比較し、再帰的体制が上回ったかを確認
	if (normalSalary < recursiveSalary) {
		printf("再帰的な賃金体制の方が儲かったよ!\n");
	}

	//終了
	return 0;
}