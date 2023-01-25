#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <iostream>

int main() {
  char input[8] = "1970";

  char generation[3][8] = {
    "1970",
  "2019",
  "2022"
  };

  std::list <const char*> lst{
    "Tokyo","Kanda","Akihabara","Okachimachi","Ueno",
    "Uguisudani","Nippori","Tabata","Komagome",
    "Sugamo","Otsuka","Ikebukuro","Mejiro","Takadanobaba",
    "Shin-Okubo","Shinjuku","Yoyogi","Harajuku","Shibuya",
    "Ebisu","Meguro","Gotanda","Osaki","Shinagawa",
   "Tamachi","Hamamatsucho","Shimbashi","Yurakucho"
  };

  int size = lst.size();

  printf("1970、2019、2022、いずれかを入力してください。\n");
  scanf_s("%s", input, 8);

  //2019,または2022が入力されたら
  if (strcmp(input, generation[1]) == 0
    || strcmp(input, generation[2]) == 0) {
    for (std::list<const char*>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
      //西日暮里を挿入追加
      if (*itr == "Tabata") {
        itr = lst.insert(itr, "Nishi-Nippori");
        ++itr;
      }

      //2022の方が入力されていたら
      if (strcmp(input, generation[2]) == 0) {
        //高輪ゲートウェイを挿入追加
        if (*itr == "Tamachi") {
          itr = lst.insert(itr, "Takanawa Gateway");
          ++itr;
        }
      }
    }
  }

  //1970が入力されてなかったら
  else if (strcmp(input, generation[0]) != 0) {
    printf_s("\nERROR");
    return 0;
  }

  //リストを一覧表示
  printf("\n表示年代 : %s\n", input);
  for (auto it_f = lst.begin();
    it_f != lst.end();
    it_f++) {
    std::cout << *it_f << "\n";
  }

  system("pause");
  return 0;
}
