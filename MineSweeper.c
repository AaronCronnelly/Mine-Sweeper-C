#include<stdio.h>
#include<stdlib.h>
#include<time.h>

  //CONSTANTS
#define ROWS 8
#define COLS 8
      
  //FUNCTIONS
void DisplayGrid(char Grid[ROWS][COLS])
{
  for (int i = 0; i < ROWS; i++) 
      { 
        for(int j = 0; j < COLS; j++)
          {
              Grid[i][j]='O';
           }
      }//END OF POPULATION OF GRID

   for (int i = 0; i < ROWS; i++) 
      { 
        for(int j = 0; j < COLS; j++)
          {
            printf(" %c ", Grid[i][j]);
          }
        printf("\n");
      }//END OF PRINTING OF GRID
 }//END OF DisplayGrid

void DisplayRules()
{
  printf("Rules\n");
  printf("1: Your aim is to clear all the tiles without mines\n");
  printf("2: You will be showen a grid, and then have to input the row, and then,\ncolume that you what to clear\n");
  printf("3: Once you claer one tile, you will be showen some numbers, these numbers,\nshow how many bombs are in a 8 square radius\n");
}//END OF DisplayRules

void RNDNumGen()
{//Understanding of random gotten from https://www.youtube.com/watch?v=CJ37J_Cdd8Q
  srand(time(0));
  int RNDNum1 = (rand()%8);//FOR ROW
  int RNDNum2 = (rand()%8);//FOR COL
  //printf("DEBUG-- RND1: %d\n", RNDNum1);
  //printf("DEBUG-- RND2: %d\n", RNDNum2);
    
}//END OF RNDNumGen 

void PlayGame()
{   //testing 
  //RNDNumGen();
   char Grid[ROWS][COLS];//DECLEARING THE ARRAY
    //VARIABLES
  char enter='n';
  int move1;
  int move2;
    
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
       
        //Get out of game
      printf("Continue with game Yes('y')/No('n')\n");
        scanf(" %c", &enter);
          }//END OF WHILE
}//END OF PlayGame

  //MAIN 
int main()
{ 
  DisplayRules();
  PlayGame();
 return 0;
}//END OF MAIN 

  



