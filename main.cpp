#include <stdio.h> //printf_s使うため
#include <random> //乱数使うため
#include <Windows.h> //Sleep使うため
#include <functional> //std::function使うため

//関数ポインタ用にtypedefで型を用意
typedef int (*function)(int ans);

//マジックナンバーを減らすために、出力値に名前を付ける
typedef enum Number {
	EvenNum = 0,//丁、偶数
	OddNum = 1, //半、奇数
	ErrorNum = 999,// エラー
}Number;

//処理のプロトタイプ
int InputPredict(int ans);
int ReturnResult(int ans);
void SetWaitTimer(function pFunc, int ans, int timer);

//メイン
int main(void) {
	int waitTimer = 3; //タイマー[second]
	int ans = EvenNum; //プレイヤーの、丁か半かの予測

	function pFunc = nullptr; //関数ポインタ

	std::function<int(int)> fInput = [=](int ans) {
		char str[10] = "きすう"; //プレイヤーの入力文字配列

		const char ODD[] = "奇数"; //比較用文字配列
		const char EVEN[] = "偶数"; //比較用文字配列
		const char odd[] = "きすう"; //比較用文字配列
		const char even[] = "ぐうすう"; //比較用文字配列

		printf_s("【奇数か偶数か、予想を入力してください】\n");

		//文字をプレイヤーに入力させる
		scanf_s("%s", &str, 10);

		//「奇数」または「きすう」と入力されたなら
		if (strcmp(str, ODD) == 0
			|| strcmp(str, odd) == 0) {

			// ansを奇数に設定
			ans = OddNum;

			printf_s("【奇数の入力を確認】\n\n");
			return ans;
		}

		//「偶数」または「ぐうすう」と入力されたなら
		if (strcmp(str, EVEN) == 0
			|| strcmp(str, even) == 0) {

			// ansを偶数に設定
			ans = EvenNum;

			printf_s("【偶数の入力を確認】\n\n");
			return ans;
		}

		//それ以外は全部エラー入力扱いで設定
		ans = ErrorNum;

		printf_s("【想定外の入力を確認】\n\n"
			"%dが出力されました\n", ans);

		return ans;
	};

	std::function<int(int)> fResult = [=](int ans) {
		//乱数シード生成器
		std::random_device seed_gen;
		//メルセンヌ・ツイスターの乱数エンジン
		std::mt19937_64 engine(seed_gen());
		//乱数範囲
		std::uniform_int_distribution < int > dist(1, 6);

		// 乱数を1つ選出
		int rand = static_cast<int>(dist(engine));

		printf_s("【%dが選出されました】\n\n", rand);

		// 奇数なら1、偶数なら0にする。
		rand = rand % 2;

		// ansと一致したなら
		if (ans == rand) {
			printf_s("【的中です】\n");
			return true;
		}

		// 一致しなかったら
		printf_s("【ハズレです】\n");
		return false;
	};

	auto fTimer = [&](function pFunc, int ans, int timer) {
		//timerをsecondに変換しつつ、pFuncの起動を遅らせる。
		Sleep(timer * 1000);

		//Sleep終了直後に起動
		pFunc(ans);
	};

	//予測を入力するフェーズ
	//読み取った入力から、ansに EvenNum か OddNum を代入
	ans = fInput(ans);

	//エラーナンバーじゃないなら
	if (ans != ErrorNum) {
		printf_s("【結果は...】\n");

		//結果を出力するフェーズ
		//勿体ぶってからfResultを起動
		fTimer(fResult(ans), ans, waitTimer);
	}

	//終了
	return 0;
}

//予測を入力するフェーズ
int InputPredict(int ans) {
	char str[10] = "きすう"; //プレイヤーの入力文字配列

	const char ODD[] = "奇数"; //比較用文字配列
	const char EVEN[] = "偶数"; //比較用文字配列
	const char odd[] = "きすう"; //比較用文字配列
	const char even[] = "ぐうすう"; //比較用文字配列

	printf_s("【奇数か偶数か、予想を入力してください】\n");

	//文字をプレイヤーに入力させる
	scanf_s("%s", &str, 10);

	//「奇数」または「きすう」と入力されたなら
	if (strcmp(str, ODD) == 0
		|| strcmp(str, odd) == 0) {

		// ansを奇数に設定
		ans = OddNum;

		printf_s("【奇数の入力を確認】\n\n");
		return ans;
	}

	//「偶数」または「ぐうすう」と入力されたなら
	if (strcmp(str, EVEN) == 0
		|| strcmp(str, even) == 0) {

		// ansを偶数に設定
		ans = EvenNum;

		printf_s("【偶数の入力を確認】\n\n");
		return ans;
	}

	//それ以外は全部エラー入力扱いで設定
	ans = ErrorNum;

	printf_s("【想定外の入力を確認】\n\n"
		"%dが出力されました\n", ans);

	return ans;
}

//タイマーをセット
void SetWaitTimer(function pFunc, int ans, int timer) {
	//timerをsecondに変換しつつ、pFuncの起動を遅らせる。
	Sleep(timer * 1000);

	//Sleep終了直後に起動
	pFunc(ans);
}

//結果を出力するフェーズ
int ReturnResult(int ans) {
	//乱数シード生成器
	std::random_device seed_gen;
	//メルセンヌ・ツイスターの乱数エンジン
	std::mt19937_64 engine(seed_gen());
	//乱数範囲
	std::uniform_int_distribution < int > dist(1, 6);

	// 乱数を1つ選出
	int rand = static_cast<int>(dist(engine));

	printf_s("【%dが選出されました】\n\n", rand);

	// 奇数なら1、偶数なら0にする。
	rand = rand % 2;

	// ansと一致したなら
	if (ans == rand) {
		printf_s("【的中です】\n");
		return true;
	}

	// 一致しなかったら
	printf_s("【ハズレです】\n");
	return false;
}