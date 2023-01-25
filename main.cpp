#include <stdio.h> //printf_s使うため
#include <random> //乱数使うため
#include <Windows.h> //Sleep使うため
#include <functional> //std::function使うため

//マジックナンバーを減らすために、出力値に名前を付ける
typedef enum Number {
  EvenNum = 0,//丁、偶数
  OddNum = 1, //半、奇数
  ErrorNum = 999,// エラー
}Number;

//メイン
int main(int argc,const char *argv[]) {
  SetConsoleOutputCP(CP_UTF8);
  setvbuf(stdout, nullptr, _IOFBF, 1024);

  int waitTimer = 3; //タイマー[second]
  int ans = EvenNum; //プレイヤーの、丁か半かの予測

                     //関数オブジェクトを代入
  std::function<int(int)> fI = [](int ans) {
    char str[4] = "k"; //プレイヤーの入力文字配列

    const char ODD[] = "k"; //比較用文字配列
    const char EVEN[] = "g"; //比較用文字配列

    printf_s("【奇数か偶数か、予想を入力してください】\n");
    printf_s("【奇数】: k ,【偶数】: g ,\n");

    //文字をプレイヤーに入力させる
    scanf_s("%s", str, 4);

    //「奇数」または「きすう」と入力されたなら
    if (strcmp(str, ODD) == 0) {

      // ansを奇数に設定
      ans = OddNum;

      printf_s("【奇数の入力を確認】\n\n");
      return ans;
    }

    //「偶数」または「ぐうすう」と入力されたなら
    if (strcmp(str, EVEN) == 0) {

      // ansを偶数に設定
      ans = EvenNum;

      printf_s("【偶数の入力を確認】\n\n");
      return ans;
    }

    //それ以外は全部エラー入力扱いで設定
    //ans = ErrorNum;

    //printf_s("【想定外の入力を確認】\n\n"
    //  "%dが出力されました\n", ans);

    return ans;
  };
  std::function<int(int)> fR = [](int ans) {
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
  std::function<int(std::function<int(int)> func, int ans, int timer)> fT = [](std::function<int(int)> func, int ans, int timer) {
    //timerをsecondに変換しつつ、funcの起動を遅らせる。
    Sleep(timer * 1000);

    //Sleep終了直後に起動
    func(ans);

    return 0;
  };

  //予測を入力するフェーズ
  //読み取った入力から、ansに EvenNum か OddNum を代入
  ans = fI(ans);

  //エラーナンバーじゃないなら
  if (ans != ErrorNum) {
    printf_s("【結果は...】\n");

    //結果を出力するフェーズ
    //勿体ぶってからResultを起動
    fT(fR, ans, waitTimer);
  }

  system("pause");
  return 0;
}
