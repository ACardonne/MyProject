#include <iostream>
#include "../include/helloworld.h"
#include "../include/sudoku.h"
#include "../include/solveur.h"

using namespace std;
int main(void)
{
  test();
  show(completefirstline(initSudoku()));
  //char Str[82] = "123456789123456789123456789123456789123456789123456789123456789123456789123456789";
  //creationManuelleSudoku(Str);
}
