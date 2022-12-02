#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum scene {
  homeScene,
  displayScene,
  insertScene,
  deleteScene,
}SCENE;

typedef struct cell {
  int val;
  struct cell *next;
}CELL;

CELL *GetInsertCellAddress(CELL *endCELL, int iteretor);
void Create(CELL *currentCell, int val);
void Index(CELL *endCell);
void Delete(CELL* currentCell);

int main(void) {
  int nowScene = homeScene;
  int inputValue;
  CELL head{};
  head.next = nullptr;

  while (1) {
    switch (nowScene){
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
      scanf_s("%d", &inputValue);

      Create(&head,inputValue);

      printf("要素がリストの最後尾に挿入されました"
        "\n"
        "--------------------------------\n"
        "0.初期画面に戻る\n");
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

CELL* GetInsertCellAddress(CELL *endCell, int iteretor) {
  for (int i = 0; i < iteretor; i++){
    if (endCell->next) {
      endCell = endCell->next;
    }
    else {
      break;
    }
  }
  return endCell;
}

void Create(CELL *currentCell, int val) {
  CELL *newCell;
  newCell = (CELL*)malloc(sizeof(CELL));
  newCell->val = val;
  newCell->next = nullptr;

  while (currentCell->next != nullptr) {
    currentCell = currentCell->next;
  }
  currentCell->next = newCell;
}

void Index(CELL *currentCell) {
  while (currentCell->next != nullptr) {
    currentCell = currentCell->next;

    printf("%d\n", currentCell->val);
  }
}

void Delete(CELL *head){
  CELL* prev;
  prev = head;
  while (head->next != nullptr){
    head = head->next;
    if (head->next != nullptr) {
      prev = head;
    }
   }
  head = prev;
  head->next = nullptr;
}
