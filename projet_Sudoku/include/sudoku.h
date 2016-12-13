#ifndef SUDOKU_H
#define  SUDOKU_H

int test();

int **initSudoku();

int **completefirstline(int**);

int show(int**);

// prend en argument un sudoku, un nombre à tester et son num de ligne. Renvoie 1 si autorisé, 0 sinon.
int testligne(int**,int randNumb, int lnum);
int testcol(int** tab, int randNumb, int cnum);
int testcarre(int** tab, int randNumb, int cnum, int lnum);

#endif
