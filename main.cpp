#include <windows.h>
#include <stdio.h>

int main(void){
  SetConsoleOutputCP(CP_UTF8);
  setvbuf(stdout, nullptr, _IOFBF, 1024);

  system("pause");
  return 0;
}
