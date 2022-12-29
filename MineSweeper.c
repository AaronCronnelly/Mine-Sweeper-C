#include<stdio.h>

//CONSTATNS
  #define ROWS 8
  #define COLS 8

//FUNCTIONS 
  void MakeGrid(int Grid[ROWS][COLS]);
  void LoadGame();  

int main()
{
  LoadGame();
}//END OF MAIN 

void LoadGame()
{
  int Grid[ROWS][COLS];
  MakeGrid(Grid);
}//END OF LOAD GAME



void MakeGrid(int Grid[ROWS][COLS])
{ 
  for(int i=0; i<ROWS; i++)
    {
      for(int j=0; j<COLS; j++)
        {
          //this is filling the main gird
          Grid[i][j]=0;
          //this is filling the top row of grid
          Grid[0][j]=j+1;
          //this is filling the first cols of grid 
          Grid[i][0]=i+1;
        }
    }//MAKING GIRD
  for(int i=0; i<ROWS; i++)
    {
      for(int j=0; j<COLS; j++)
        {
          printf(" %d ", Grid[i][j]);
        }
      printf("\n");
    }//DISPLAYIG GIRD
}//END OF MAKE GRID

