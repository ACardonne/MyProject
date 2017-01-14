#include <iostream>
#include "../include/sudoku.h"
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include "../include/solveur.h"
#include <string.h>


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
      if(tab[i][j] == 0){
        printf("- ");
      }
      else{
        printf("%d ", tab[i][j]);
      }
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
int ** duplicateSudoku(int ** tab){
  int** tableau2D = new int*[9];
  for (int i = 0; i < 9; i++)
  {
    tableau2D[i] = new int[9];
    for (int j = 0; j < 9; j++)
    {
      tableau2D[i][j] = tab[i][j];
    }
  }
  return tableau2D; // return tab adres
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

int ** evidageGrilleSudoku(int ** tab){
  int flag = 0;
  int num_ligne;
  int num_colomne;

  for(int i =0; i < 50; i++){ // retire 15 chiffres du sudoku
    flag = 0;
    while(flag == 0){
      num_ligne = rand()%(9);
      num_colomne = rand()%(9);
      if(tab[num_ligne][num_colomne]!=0){
        tab[num_ligne][num_colomne] = 0;
        flag = 1;
      }
    }
  }
  return tab;
}
// génère, affiche et renvoie une grille de sudoku brutalement solvable
int ** Easy_generationSudoku(){
  int ** res = completefirstline(initSudoku()); // génère un sudoku plein;
  int ** resToTest;
  int flag = 0;
  while(flag !=1){
   resToTest = evidageGrilleSudoku(duplicateSudoku(res));
   show(resToTest);
   if(Easy_canBeSolved(duplicateSudoku(resToTest))){
     flag = 1;
   }
  }
  show(resToTest);
  return resToTest;
}
void Start_EasySudoku(){
  int flag = 0;
  int ** sudoku = Easy_generationSudoku(); // génère et affiche un sudoku facile
  char ligne_colomne_valeur[3];
  while(flag == 0){
    play(sudoku, askPlayer(ligne_colomne_valeur));


    if (isComplete(sudoku)){
      flag = 1;
      printf("success");
    }
  }

  return;
}
char * askPlayer(char* ligne_colomne_valeur){
    printf("Saisissez 3 chiffres : ligne, colomne et valeur puis appuyez sur entrée \n");
    fgets(ligne_colomne_valeur, 4, stdin);
    //printf("Vous avez saisi : %s \n\n", ligne_colomne_valeur);
    clean(ligne_colomne_valeur);
    return ligne_colomne_valeur;
}
int** play(int** sudoku, char* ligne_colomne_valeur){
    int ligne = (char) ligne_colomne_valeur[0]-48;
    int colomne = (char) ligne_colomne_valeur[1]-48;
    int valeur = (char) ligne_colomne_valeur[2]-48;
    if(sudoku[ligne][colomne] == 0){
      sudoku[ligne][colomne] = valeur;
    }
    else{
      printf("La case [%d,%d] contient déjà un %d", ligne, colomne, sudoku[ligne][colomne]);
    }
    show(sudoku);
    return sudoku;
}
static void purger(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {}
}

static void clean (char *chaine)
{
    char *p = strchr(chaine, '\n');

    if (p)
    {
        *p = 0;
    }

    else
    {
        purger();
    }
}
//
