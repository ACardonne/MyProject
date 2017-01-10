#include <iostream>
#include "../include/sudoku.h"
#include <stdio.h>
#include <cstdlib>
#include <ctime>

int **initSudoku()
{
// tableau 2D représentant le sudoku
  int** tableau2D = new int*[9];
  for (int i = 0; i < 9; i++)
  {
    tableau2D[i] = new int[9];
    for (int j = 0; j < 9; j++)
    {
      tableau2D[i][j] = 0;
    }
  }
  return tableau2D; // return tab adress
}

int show(int** tab){ // equivalent to int *tab[][]
  printf("\n");
  for (int i = 0; i < 9; ++i)
  {
    printf("     ");
    for (int j = 0; j < 9; j++)
    {
      printf("%d ", tab[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return 0;
}

int **completefirstline(int** tab){
  srand(time(NULL)); // initialisation de rand
  int testGrille =0;
  while(testGrille < 1000000){
    int testVal =0;
    for (int reset_ligne =0; reset_ligne < 9; reset_ligne++){
      for (int reset_colomne =0; reset_colomne < 9 ; reset_colomne++){
        tab[reset_ligne][reset_colomne] = 0;
      }
    }
    printf("%d\n", testGrille);

    //rand()%(9)+1;       // génère un entier entre 1 et 9
    testVal =0;
    for (int num_ligne =0; num_ligne < 9 && testVal < 80; num_ligne++){
      for (int num_colomne =0; num_colomne < 9 && testVal < 80; num_colomne++){
        testVal =0;
        int t = rand()%(9)+1;
        int flag = testligne(tab, t, num_ligne) + testcol(tab, t, num_colomne) + testcarre(tab, t, num_colomne , num_ligne);
        while(flag != 3 && testVal < 80){
          //printf("%d ",testVal);
          testVal++;
          t = rand()%(9)+1;
          flag = testligne(tab, t, num_ligne) + testcol(tab, t, num_colomne) + testcarre(tab, t, num_colomne , num_ligne);
        }
        if (testVal == 80){
          testGrille++;
        }
        else {
          tab[num_ligne][num_colomne] = t;
          if(num_ligne == 8 && num_colomne == 8){
            return tab;
          }
        }
      }
    }
  }
  return tab;
}

// prend en argument un sudoku, un nombre à tester et son num de ligne. Renvoie 1 si autorisé, 0 sinon.
int testligne(int** tab, int randNumb, int lnum){
  int res = 1;
  for(int j =0; j<9; j++){
    if(tab[lnum][j] == randNumb){
      res =0;
    }
  }
  return res;
}
int testcol(int** tab, int randNumb, int cnum){
  int res = 1;
  for(int j =0; j<9; j++){
    if(tab[j][cnum] == randNumb){
      res = 0;
    }
  }
  return res;
}
int testcarre(int** tab, int randNumb, int cnum, int lnum){
  int res = 1;
  int numLigneCarre = (lnum / 3) * 3 ;
  int numColomneCarre = (cnum / 3) *3 ;
  for(int i =0; i <3 ; i++){
    for(int j =0; j<3 ; j++){
      if(tab[numLigneCarre +i][numColomneCarre + j] == randNumb){
        res = 0;
      }
    }
  }
  return res;
}

int ** creationManuelleSudoku(char* Str){
  int** res = initSudoku();
  for(int num_ligne =0; num_ligne < 9; num_ligne++){
    for(int num_colomne=0; num_colomne <9; num_colomne++){
    res[num_ligne][num_colomne] = (char) Str[num_ligne*9+num_colomne] - 48;
    }
  }
  show(res);
  return res;
}







//
