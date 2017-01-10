#include <iostream>
#include "../include/solveur.h"
#include "../include/sudoku.h"
#include <stdio.h>
#include <cstdlib>
#include <ctime>

int test(){
    std::cout << "Hello, world!\n";
    return 0;
}

int checkUneValeur(int** tab, int num_ligne, int num_colomne, int valATester){ // renvoie 1 si seule valeur possible, 0 sinon
  int flag =0;
  for(int numTest = 1; numTest < 10; numTest++){
    if(numTest != valATester && (testligne(tab, numTest, num_ligne) + testcol(tab, numTest, num_colomne) + testcarre(tab, numTest, num_colomne , num_ligne)) ==3){
      return 0; // car la valeur à tester n'est pas la seule possible
    }
    else if(numTest == valATester && (testligne(tab, valATester, num_ligne) + testcol(tab, valATester, num_colomne) + testcarre(tab, valATester, num_colomne , num_ligne)) !=3){
      return 0; // la valeur testée n'est pas possible
    }
  }
  return 1;
}
int checkUneCase(int** tab, int num_ligne, int num_col){/*
  for(int valATester ==1; valATester < 10; valATester++){
    if(checkUneValeur(int** tab, int num_ligne, int num_col, int valATester) == 1){
      //si la valeur est bien la seule possible on remplie la case.
      tab[num_ligne][num_colomne] =valATester;
      return 1;
    }
  }*/
  return 0; // si aucune valeur n'était l'unique possible sur la case.
}

int checkSudoku(int** tab){ //essaye de remplir chaque case du sudoku et renvoie un à la première valeur remplie ou 0 si aucune valeur n'est possible.
/*
  for(num_ligne = 0; num_ligne < 9; num_ligne++){
    for(num_colomne = 0; num_colomne < 9; num_colomne ++){
      checkUneCase(tab, num_ligne, num_colomne);
      return 1;
    }
  }*/
  return 0; // sudoku bloqué. Soit le sudoku n'est pas simplement solvable, soit il est impossible à solver.
}

void solveStepByStep(int** tab){/*
  for(int step =0; step < 75; step ++){
    checkSudoku(tab);
    printf("___ \n Step : %d \n", step);
    show(tab);
    getVal();
  }*/
  return;
}











//
