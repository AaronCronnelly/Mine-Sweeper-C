#include<stdio.h>
#include<stdlib.h>
#include<time.h>

  //CONSTANTS
#define ROWS 8
#define COLS 8
      
  //FUNCTIONS
void DisplayGrid(char Grid[ROWS][COLS]);
void UpDateGrid(char Grid[ROWS][COLS], int i, int j);
void DisplayRules();
void RNDNumGen();
void PlayGame();

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
  int RNDNum2;//(rand()%8)       

  for(int i=0; i<ROWS; i++)
    {
      for(int j=0; j<COLS; j++)
        {
          Grid[i][j]='O';
        }
    }//END OF POPULATING GRID
  
  for(int i=0; i<10; i++)
    {RNDNum1=(rand()%8);
      RNDNum2=(rand()%8);
//printf("DEBUG--1 Row: %d,, Cols: %d\n", RNDNum1, RNDNum2);

      for(int j=0; j<ROWS; j++)
        {
          for(int p=0; p<COLS; p++)
            {
                Grid[RNDNum1][RNDNum2]='X';
            }
        }

    }//END OF MINES IN GRID

  for(int i=0; i<ROWS; i++)
    {
      for(int j = 0; j < COLS; j++)
      {
        printf(" %c ", Grid[i][j]);   
      }
        printf("\n");
    }//END OF PRINTING OF GRID
 
  
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
         printf(" %c ",Grid[i][j]);
         printf(" %c ",Grid[move1][move2]);
        }
      printf("\n");
    }
}//END OF UpDateGrid

void DisplayRules()
{
  printf("Rules\n");
  printf("1: Your aim is to clear all the tiles without mines\n");
  printf("2: You will be showen a grid, and then have to input the row, and then,\ncolume that you what to clear\n");
  printf("3: Once you claer one tile, you will be showen some numbers, these numbers,\nshow how many bombs are in a 8 square radius\n");
}//END OF DisplayRules

void PlayGame()
{   //testing 
   char Grid[ROWS][COLS];//DECLEARING THE ARRAY
    //VARIABLES
  char enter='n';
  int move1;
  int move2;
  int gameState=0; 
    //START GAME
  printf("Welcome to MineSweeper, Here are the rules\n");
  
      //ENTER GAME  
    printf("Enter game ('y')/('n')");
      scanf(" %c", &enter);
    while(enter !='n')
    {       

      
      
        //CALLING GRID
      DisplayGrid(Grid);
    
        //User makes move
      printf("Which square would you like to revel\n");
        scanf("%d %d", &move1, &move2);
      
      UpDateGrid(Grid, move1, move2);
        //Get out of game
      printf("Continue with game Yes('y')/No('n')\n");
        scanf(" %c", &enter);
      
          }//END OF WHILE
}//END OF PlayGame


