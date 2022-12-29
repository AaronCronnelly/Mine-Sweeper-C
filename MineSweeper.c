#include<stdio.h>

//CONSTATNS
  #define ROWS 10
  #define COLS 10

//FUNCTIONS 
  void MakeGrid(char Grid[ROWS][COLS]);
  void LoadGame();  

int main()
{
  LoadGame();
}//END OF MAIN 

void LoadGame()
{
  char Grid[ROWS][COLS];
  MakeGrid(Grid);
}//END OF LOAD GAME



void MakeGrid(char Grid[ROWS][COLS])
{
  for(int i=0; i<8; i++)
    {
      for(int j=0; j<8; j++)
        {
          Grid[i][j]='O';
        }
      printf("\n");
    }

}//END OF MAKE GRID

