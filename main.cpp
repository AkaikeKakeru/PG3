#include <windows.h>
#include <stdio.h>

typedef struct cell {
  int val;
  struct cell *prev;
  struct cell *next;
}CELL;

CELL* GetInsertCellAddress(CELL* endCELL, int iteretor);

int main(void) {
  SetConsoleOutputCP(CP_UTF8);
  setvbuf(stdout, nullptr, _IOFBF, 1024);

  system("pause");
  return 0;
}

CELL* GetInsertCellAddress(CELL* endCELL, int iteretor) {
  for (int i = 0; i < iteretor; i++){
    if (endCELL->next) {
      endCELL = endCELL->next;
    }
    else {
      break;
    }
  }
  return endCELL;
}
