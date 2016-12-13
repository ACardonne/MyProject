#include <iostream>
#include "../include/sudoku.h"
#include <stdio.h>
#include <cstdlib>
#include <ctime>

int test(){
    std::cout << "Hello, world!\n";
    return 0;
}

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
  //rand()%(9)+1;       // génère un entier entre 1 et 9

  for (int j =0; j < 9 ; j++){
    int t = rand()%(9)+1;
    int flag = testligne(tab, t, 0);
    while(flag == 0){
      t = rand()%(9)+1;
      flag = testligne(tab, t, 0);
    }
    tab[0][j] = t;
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
// test pour commit







//






//
