#ifndef SOLVEUR_H
#define  SOLVEUR_H

int test();
int checkUneValeur(int** tab, int num_ligne, int num_col, int valATester);
int checkUneCase(int** tab, int num_ligne, int num_col);
int checkSudoku(int** tab);
void Easy_solveStepByStep(int** tab);
int Easy_canBeSolved(int** tab);
int isComplete(int** tab);
#endif
