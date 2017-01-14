#ifndef SUDOKU_H
#define  SUDOKU_H


int **initSudoku();
int ** duplicateSudoku(int ** tab);

int **completefirstline(int**);

int show(int**);

// prend en argument un sudoku, un nombre à tester et son num de ligne. Renvoie 1 si autorisé, 0 sinon.
int testligne(int**,int randNumb, int lnum);
int testcol(int** tab, int randNumb, int cnum);
int testcarre(int** tab, int randNumb, int cnum, int lnum);
int ** creationManuelleSudoku(char[82]);
int ** evidageGrilleSudoku(int ** tab);
int ** Easy_generationSudoku();
void Start_EasySudoku();
char* askPlayer(char * ligne_colomne_valeur);
int ** play(int ** sudoku, char* ligne_colomne_valeur);

// fonctions servant à nettoyer un buffer prises sur OpenClassroom
static void purger(void);
static void clean (char *chaine);

#endif
