#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <iostream>

void DrawList(std::list <const char*> lst);

int main() {
  std::list <const char*> lst{
    "Tokyo","Kanda","Akihabara","Okachimachi","Ueno",
    "Uguisudani","Nippori","Tabata","Komagome",
    "Sugamo","Otsuka","Ikebukuro","Mejiro","Takadanobaba",
    "Shin-Okubo","Shinjuku","Yoyogi","Harajuku","Shibuya",
    "Ebisu","Meguro","Gotanda","Osaki","Shinagawa",
   "Tamachi","Hamamatsucho","Shimbashi","Yurakucho"
  };

  int size = lst.size();

  //1970時点のリストを一覧表示
  printf("表示年代 : 1970\n");
  DrawList(lst);

  //2019用のリストに修正
  for (std::list<const char*>::iterator itr = lst.begin();
    itr != lst.end(); ++itr) {
    //西日暮里を挿入追加
    if (*itr == "Tabata") {
      itr = lst.insert(itr, "Nishi-Nippori");
      ++itr;
    }
  }

  //2019時点のリストを一覧表示
  printf("\n表示年代 : 2019\n");
  DrawList(lst);

  //2022用のリストに修正
  for (std::list<const char*>::iterator itr = lst.begin();
    itr != lst.end(); ++itr) {
    //高輪ゲートウェイを挿入追加
    if (*itr == "Tamachi") {
      itr = lst.insert(itr, "Takanawa Gateway");
      ++itr;
    }
  }

  //2022時点のリストを一覧表示
  printf("\n表示年代 : 2022\n");
  DrawList(lst);

  system("pause");
  return 0;
}

void DrawList(std::list <const char*> lst) {
  for (auto it_f = lst.begin();
    it_f != lst.end();
    it_f++) {
    std::cout << *it_f << "\n";
  }
}
