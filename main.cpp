#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
  int val;
  struct cell *prev;
  struct cell *next;
}CELL;

CELL *GetInsertCellAddress(CELL *endCELL, int iteretor);
void Create(CELL *currentCell, int val);
void Index(CELL *endCell);

int main(void) {
 // SetConsoleOutputCP(CP_UTF8);
//  setvbuf(stdout, nullptr, _IOFBF, 1024);

  int iterator;
  int inputValue;
  CELL *insertCell;

  CELL head{};
  head.next = nullptr;
  head.prev = nullptr;

  while (1) {

    printf_s("‰½”Ô–Ú‚ÌƒZƒ‹‚ÌŒã‚ë‚É‘}“ü‚µ‚Ü‚·‚©\n");
    scanf_s("%d", &iterator);

    printf_s("‘}“ü‚·‚é’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
    scanf_s("%d", &inputValue);

    insertCell = GetInsertCellAddress(&head,iterator);
    Create(insertCell,inputValue);

    Index(&head);
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
  CELL *newCell = nullptr;
  newCell = (CELL*)malloc(sizeof(CELL));
  newCell->val = val;
  newCell->prev = currentCell;
  newCell->next = currentCell->next;

  if (currentCell->next) {
    CELL* nextCell = currentCell->next;
    nextCell->prev = newCell;
  }
  currentCell->next = newCell;
}

void Index(CELL *endCell) {
  int no = 1;
  while (endCell->next != nullptr) {
    endCell = endCell->next;
    printf("%d", no);
    printf("%p", endCell->prev);
    printf("%5d", endCell->val);
    printf("(%p)", endCell);
    printf("%p\n", endCell->next);
    no++;
  }
}
