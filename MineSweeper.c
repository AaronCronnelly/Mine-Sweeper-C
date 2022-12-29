#include<stdio.h>

//CONSTATNS
  #define ROWS 9
  #define COLS 9

//FUNCTIONS 
  void MakeGrid(char Grid[ROWS][COLS]);
  void LoadGame();  
  void updateGrid(char Grid[ROWS][COLS], int x, int y);
  void DisplayOnce(char Grid[ROWS][COLS]);


int main()
{
  LoadGame();
}//END OF MAIN 

void LoadGame()
{//need to make it so make grid is only called once
  //then it is passed to an update grid funciton 
  //the update gride funtion is run each time the user entes a value to claer 

    //VARAIBALES
  char startGame;
  char Grid[ROWS][COLS];
  
    //callling the grid funciton to make the grid 
    MakeGrid(Grid);
 

  printf("Would you like to start the game 'Y'/'N'\n");
    scanf("%c", &startGame);
    DisplayOnce(Grid);

  while(startGame=='y'||startGame=='Y')
    {
      int x, y;
    printf("Please enter the tile you would like to check: x y\n");
      scanf("%d %d", &x, &y);

      updateGrid(Grid, x, y);

      printf("would you like to continut playing 'y'/'n'\n");
        scanf(" %c", &startGame);
    }//END OF WHILE FOR GAME

  printf("DEBUG-- this is where the user score, and opthins to save will be\n");

}//END OF LOAD GAME



void MakeGrid(char Grid[ROWS][COLS])
{ 
  for(int i=0; i<ROWS; i++)
    {
      for(int j=0; j<COLS; j++)
        {int T=j+1;
          int F=i+1;
          //this is filling the main gird
          Grid[i][j]=' ';
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
  
}//END OF MAKE GRID


void updateGrid(char Grid[ROWS][COLS], int x, int y)
{
  for(int i=0; i<ROWS; i++)
    {
      for(int j=0; j<COLS; j++)
        {
          Grid[x][y]='u';
          printf(" %c ", Grid[i][j]);
        }
      printf("\n");
    }//DISPLAYIG GIRD
}//END OF updateGrid

void DisplayOnce(char Grid[ROWS][COLS])
{
  for(int i=0; i<ROWS; i++)
    {
      for(int j=0; j<COLS; j++)
        {
          printf(" %c ", Grid[i][j]);
        }
      printf("\n");
    }//DISPLAYIG GIRD
}//END OF DisplayOnce







