#include<stdio.h>
#include<stdlib.h>
#include<time.h>

  //CONSTANTS
#define ROWS 8
#define COLS 8

  //FUNCTIONS
void DisplayGrid(char Grid[ROWS][COLS]);
void UpDateGrid(char Grid[ROWS][COLS], int move1, int move2);
void DisplayRules();
void PlayGame();
void MoveMent();

  //MAIN
int main()
{
  DisplayRules();
  PlayGame();
  return 0;
}//END OF MAIN

void DisplayGrid(char Grid[ROWS][COLS])
{
  srand(time(NULL));
  int RNDNum1;
  int RNDNum2;

  for(int i=0; i<ROWS; i++)
    {
      for(int j=0; j<COLS; j++)
        {
          Grid[i][j]='0';
        }
    }//END OF POPULATING GRID

  for(int i=0; i<10; i++)
    {
      RNDNum1=(rand()%8);
      RNDNum2=(rand()%8);

      for(int j=0; j<ROWS; j++)
        {
           for(int x=0; x<COLS; x++)
            {
              Grid[RNDNum1][RNDNum2]='X';
            }
        }
    }//END OF MINES

  for(int i=0; i<ROWS; i++)
    {
      for(int j=0; j<COLS; j++)
        {
          printf(" %c ", Grid[i][j]);
        }
      printf("\n");
    }
}//END OF DisplayGrid

void UpDateGrid(char Grid[ROWS][COLS], int move1, int move2)
{
  for(int i=0; i<ROWS; i++)
    {
      for(int j=0; j<COLS; j++)
        {
          Grid[i][j]='O';
          Grid[move1][move2]=' ';
        }
    }
  for(int i=0; i<ROWS; i++)
    {
      for(int j=0; j<COLS; j++)
        {
          printf(" %c ", Grid[i][j]);
          printf(" %c ", Grid[move1][move2]);
        }
      printf("\n");
    }
}//END OF UpDateGrid

void DisplayRules()
{
  printf("Welcome to MineSweeper, her are the Rules\n");
  printf("1: Your aim is to clear all the tiles without mines\n");
  printf("2: You will be showen a grid, and then have to input the row, and then,\ncolume that you what to clear\n");
  printf("3: Once you claer one tile, you will be showen some numbers, these numbers,\nshow how many bombs are in a 8 square radius\n");
}//END OF DisplayRules

void PlayGame()
{
  char Grid[ROWS][COLS];

    //VARAIBLES
  char start='n';
  int move1;
  int move2;
  int GameState=0;

    //ENTER GAME
  printf("Enter game ('y')/('n')\n");
    scanf(" %c", &start);
  while(start != 'n')
    {/*NEED TO MAKE THE GIRD RUN ONCE AND THEN SAVE IT LIKE SO, 
    THEN NEED TO REPRINT THE GRID EACH GO, WITH THE NEW LOACTION GONE\,
    NEED TO ADD IF MINE IS HIT THE plyaer loses the game
    */
        //RUN FIRST ITERATION OF GIRD
      DisplayGrid(Grid);

      printf("which Square would you liek to revel");
        scanf("%d %d", &move1, &move2);
      
      UpDateGrid(Grid, move1, move2);

        //LEAVE GAME
      printf("Continue with game ('y')/('n')\n");
        scanf(" %c", &start);
       

      
    }//END OF WHILE


}//END OF PlayGame

void MoveMent()
{

}//END OF MoveMent






