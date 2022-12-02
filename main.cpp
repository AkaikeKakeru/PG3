#include <windows.h>
#include <stdio.h>

typedef struct cell {
  int val;
  struct cell *prev;
  struct cell *next;
}CELL;

CELL *GetInsertCellAddress(CELL *endCELL, int iteretor);
void Create(CELL *currentCell, int val);

int main(void) {
  SetConsoleOutputCP(CP_UTF8);
  setvbuf(stdout, nullptr, _IOFBF, 1024);

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
  newCell->prev = currentCell;
  newCell->next = currentCell->next;

  if (currentCell->next) {
    CELL* nextCell = currentCell->next;
    nextCell->prev = newCell;
  }
  currentCell->next = newCell;
}
