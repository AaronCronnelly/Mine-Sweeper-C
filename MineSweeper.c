#include<stdio.h>

//CONSTATNS
  #define ROWS 9
  #define COLS 9

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
  for(int i=0; i<ROWS; i++)
    {
      for(int j=0; j<COLS; j++)
        {int T=j+1;
          int F=i+1;
          //this is filling the main gird
          Grid[i][j]='0';
          //this is filling the top row of grid
          Grid[0][0]='0';
          Grid[0][1]='1';
          Grid[0][2]='2';
          Grid[0][3]='3';
          Grid[0][4]='4';
          Grid[0][5]='5';
          Grid[0][6]='6';
          Grid[0][7]='7';
          Grid[0][8]='8';
          //this is filling the first cols of grid 
          Grid[1][0]='1';
          Grid[2][0]='2';
          Grid[3][0]='3';
          Grid[4][0]='4';
          Grid[5][0]='5';
          Grid[6][0]='6';
          Grid[7][0]='7';
          Grid[8][0]='8';
        }
    }//MAKING GIRD
  for(int i=0; i<ROWS; i++)
    {
      for(int j=0; j<COLS; j++)
        {
          printf(" %c ", Grid[i][j]);
        }
      printf("\n");
    }//DISPLAYIG GIRD
}//END OF MAKE GRID

