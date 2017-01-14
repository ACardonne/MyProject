#include <iostream>
#include <stdio.h>
#include "../include/helloworld.h"
#include "../include/sudoku.h"
#include "../include/solveur.h"

using namespace std;
int main(void)
{
  test();
  //show(completefirstline(initSudoku()));
  //char Str[82] = "001268500002040001000100620007029006208000104500480300083004000400050700005637400";
  //char Str2[82] = "001208500002000001000100620007029006208000104500480300083004000400050700005637400";
  //int ** sud = creationManuelleSudoku(Str2);
  //printf("%d \n", Easy_canBeSolved(sud));
  Start_EasySudoku();
  //Easy_generationSudoku();

  // TODO : Revoir commentaires et non de fonctions
  // TODO : Fonction Start_EasySudoku()
  // TODO : faire une fonction finition d'évidage de sudoku. Prenant un sudoku brutalement évidé solvable aléatoirement, et évidant les valeurs redondantes. (check chaque case)
}
