#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//GOLBAL VARAIBALES 
int GameOver=0;
int score=0;

//CONSTATNS
  #define ROWS 9
  #define COLS 9

//FUNCTIONS 
  void MakeGrid(char Grid[ROWS][COLS], char BombGrid[ROWS][COLS]); 
  void LoadGame();  
  void updateGrid(char Grid[ROWS][COLS], char BombGrid[ROWS][COLS], int x, int y);
  void DisplayOnce(char Grid[ROWS][COLS]);
  void SaveGame(Char Grid[ROWS][COLS], char BombGrid[ROWS][COLS], int Score);

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
  char BombGrid[ROWS][COLS];
  
    //callling the grid funciton to make the grid 
    MakeGrid(Grid, BombGrid);
 

  printf("Would you like to start the game 'Y'/'N'\n");
    scanf("%c", &startGame);
    printf("Score %d\n", score);
    DisplayOnce(Grid);

  while(startGame=='y'||startGame=='Y')
    {
      int x, y;
    printf("Please enter the tile you would like to check: x y\n");
      scanf("%d %d", &x, &y);

      updateGrid(Grid, BombGrid, x, y);
      printf("Score %d\n", score);
      printf("DEBUG-- %d\n", GameOver);
      if(GameOver==1)
      {
        printf("You have lost the game you score will now be displayed, \nscore: %d", score);
        return;
      }

      printf("would you like to continut playing 'y'/'n'\n");
        scanf(" %c", &startGame);
     }//END OF WHILE FOR GAME

  printf("DEBUG-- this is where the user score, and opthins to save will be.. \nScore: %d", score);

}//END OF LOAD GAME



void MakeGrid(char Grid[ROWS][COLS], char BombGrid[ROWS][COLS])
{ 
  for(int i=0; i<ROWS; i++)
    {
      for(int j=0; j<COLS; j++)
        {int T=j+1;
          int F=i+1;
          //this is filling the main gird
          Grid[i][j]='?';
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

  //SETTING UP BOMBS
  srand(time(NULL));
  for(int p=0; p<40; p++)
    {
      while(1)
      {
        int x=rand()%8+1;
        int y=rand()%8+1;
        if(Grid[x][y]=='?')
        {
          BombGrid[x][y]='x';
          break;
        }
      }
    }//END OF BOMBS 
}//END OF MAKE GRID


void updateGrid(char Grid[ROWS][COLS], char BombGrid[ROWS][COLS], int x, int y)
{
  int count=0;
  char bomb='0';

  if(BombGrid[x][y]=='x')
  {
    GameOver++;
    Grid[x][y]='x';
  }

else
  {
    score=score+1;
    for(int i=x-1; i<x+1; i++)
      {
        for(int j=y-1; j<y+1; j++)
          {
            if(BombGrid[i][j]=='x')
            {
              count++;
            }
          }
      }//END OF FOR CHECK

    switch(count) 
      {
        case 1:
        bomb='1';
          break;

        case 2:
        bomb='2';
          break;
        
        case 3:
        bomb='3';
          break;

        case 4: 
        bomb='4';
          break;

        case 5:
        bomb='5';
          break;

        case 6:
        bomb='6';
          break;
        
        case 7:
        bomb='7';
          break;

        case 8:
        bomb='8';
          break;

        default:

          break;
    }//END OF SWITHC 
    
    for(int i=1; i<ROWS; i++)
      {
        for(int j=0; j<COLS; j++)
          {
            Grid[x][y]=bomb;
            printf(" %c ", Grid[i][j]);
          }
        printf("\n");
      } 
  }
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


void SaveGame(char Grid[ROWS][COLS], char BombGrid[ROWS][COLS], int score)
{
  
}




