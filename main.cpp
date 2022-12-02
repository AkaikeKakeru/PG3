#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

//シーンenum
typedef enum scene {
  homeScene,//ホーム
  displayScene,//表示
  insertScene,//挿入
  deleteScene,//削除
}SCENE;

//自己参照構造体
typedef struct cell {
  char str[64];//文字列
  struct cell* next;//次のセル
}CELL;

/*プロトタイプ*/
void Create(CELL* endCell, const char* buf);
void Index(CELL* endCell);
void Delete(CELL* currentCell);

int main(void) {
  /*変数*/
  //現シーン
  int nowScene = homeScene;

  //入力文字列
  char inputStr[256] = "nihonnkougakuin";

  //先頭セル
  CELL head{};
  head.next = nullptr;

  while (1) {
    switch (nowScene) {
    case homeScene:
      printf("[要素の操作]\n"
        "1.要素の表示\n"
        "2.最後尾に要素の挿入\n"
        "3.最後尾の要素の削除\n"
        "\n"
        "--------------------------------\n"
        "操作を選択してください\n");
      scanf_s("%d", &nowScene);
      printf("\n\n");
      break;

    case displayScene:
      printf("[要素の一覧表示]\n");
      Index(&head);
      printf("\n"
        "--------------------------------\n"
        "0.初期画面に戻る\n");
      scanf_s("%d", &nowScene);
      printf("\n\n");
      break;

    case insertScene:
      printf("[リスト要素の挿入]\n\n"
        "追加する要素の値を入力してください\n");
      scanf_s("%s", inputStr, 256);

      Create(&head, inputStr);

      printf("要素%sがリストの最後尾に挿入されました"
        "\n"
        "--------------------------------\n"
        "0.初期画面に戻る\n",inputStr);
      scanf_s("%d", &nowScene);
      printf("\n\n");
      break;

    case deleteScene:
      printf("[要素の削除]\n");
      Delete(&head);
      printf("最後尾の要素を削除しました\n"
        "\n"
        "--------------------------------\n"
        "0.初期画面に戻る\n");
      scanf_s("%d", &nowScene);
      printf("\n\n");
      break;

    default:
      nowScene = displayScene;
      break;
    }
  }

  system("pause");
  return 0;
}

//セル生成
void Create(CELL* endCell, const char* buf) {
  CELL* newCell;
  newCell = (CELL*)malloc(sizeof(CELL));

  strcpy_s(newCell->str, 8, buf);
  newCell->next = nullptr;

  while (endCell->next != nullptr) {
    endCell = endCell->next;
  }
  endCell->next = newCell;
}

//索引
void Index(CELL* currentCell) {
  int no = 0;
  printf("要素一覧:{\n");
  while (currentCell->next != nullptr) {
    currentCell = currentCell->next;

    printf("%d:%s",no, currentCell->str);
    no++;

    if (currentCell->next != nullptr) {
      printf(",\n");
    }
    else {
      printf("\n");
    }
  }
  printf("}\n"
  "要素数:%d",no);
}

//削除
void Delete(CELL* head) {
  CELL* prev;
  prev = head;
  while (head->next != nullptr) {
    head = head->next;
    if (head->next != nullptr) {
      prev = head;
    }
  }
  head = prev;
  head->next = nullptr;
}
