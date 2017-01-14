#include <iostream>
#include "../include/solveur.h"
#include "../include/sudoku.h"
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>

int test(){
    std::cout << "Hello, world!\n";
    return 0;
}

// vérifie si une valeur est la seule valeur possible sur une case d'un sudoku.
int checkUneValeur(int** tab, int num_ligne, int num_colomne, int valATester){ // renvoie 1 si seule valeur possible, 0 sinon
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

// vérifie si une case possède une solution unique, et change la valeur de la case si c'est le cas
int checkUneCase(int** tab, int num_ligne, int num_col){
  if(tab[num_ligne][num_col] != 0){ // Cas où case déjà remplie
    return 0;
  }
  for(int valATester = 1; valATester < 10; valATester++){
    if(checkUneValeur(tab, num_ligne, num_col, valATester) == 1){
      //si la valeur est bien la seule possible on remplie la case.
      tab[num_ligne][num_col] = valATester;
      return 1;
    }
  }
  return 0; // si aucune valeur n'était l'unique possible sur la case.
}

int checkSudoku(int** tab){ //essaye de remplir chaque case du sudoku et renvoie un à la première valeur remplie ou 0 si aucune valeur n'est possible.
  for(int num_ligne = 0; num_ligne < 9; num_ligne++){
    for(int num_colomne = 0; num_colomne < 9; num_colomne ++){
      if(checkUneCase(tab, num_ligne, num_colomne) == 1){
        return 1;
      }
    }
  }
  return 0; // sudoku bloqué. Soit le sudoku n'est pas simplement solvable, soit il est impossible à solver.
}

// résoud étape par étape le sudoku par le solveur brutal
void Easy_solveStepByStep(int** tab){
  for(int step =0; step < 75; step ++){
    checkSudoku(tab);
    printf("___ \n Step : %d \n", step);
    show(tab);
    printf("Appuyez sur Enter pour poursuivre");
    std::getchar(); // bloque le programme en attendant que l'utilisateur appyuie sur entrée
  }
  return;
}
//renvoie un si résolution du sudoku possible par le solveur brutal, 0 sinon
int Easy_canBeSolved(int** tab){
  for(int step =0; step < 75; step ++){
    checkSudoku(tab);
  }
  return isComplete(tab);
}
// renvoie 0 si le sudoku contient un 0 dans une case, 1 sinon
int isComplete(int** tab){
  for(int num_ligne = 0; num_ligne < 9; num_ligne++){
    for(int num_colomne = 0; num_colomne < 9; num_colomne ++){
      if(tab[num_ligne][num_colomne] == 0){
        return 0;
      }
    }
  }
  return 1;
}











//
