#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//GOLBAL VARAIBALES 
int GameOver=0;
int score=0;
int score2=0;
int currentPlayer=1;
int players=0;
int totalMine=10;
int totalTile=0;

//CONSTATNS
#define ROWS 9
#define COLS 9


//FUNCTIONS 
void MakeGrid(char Grid[ROWS][COLS], char BombGrid[ROWS][COLS]); 
void startGame();  
void updateGrid(char Grid[ROWS][COLS], char BombGrid[ROWS][COLS], int x, int y);
void DisplayOnce(char Grid[ROWS][COLS]);
void Rules();


int main()
{
  printf("Welcome to MineSweeper, By Aaron Cronnelly\n");
  Rules(); 
  startGame();
}//END OF MAIN 

void Rules()
{
  printf("Here are the rules of the game, You will be asked to load a previose game, if you have, \n\n");
  printf("previose game then you can just say 'N' to that question and you will be able to start a, \n\n");
  printf("game. You will then be show a board and asked to input the laociton you would like to cheack,\n\n");
  printf("then that laocation will be reveled, and you will have eiter hit a mine of be show a number, \n\n");
  printf("this number represents the amount of mines that are around that laociton.\n\n");
  printf("keep going unitl you have either hit a mine or have cleard all the mines\n\n");
}

void startGame()
{   
  //VARAIBALES
  char startGame;
  char Grid[ROWS][COLS];
  char BombGrid[ROWS][COLS];

  //callling the grid funciton to make the grid 
  MakeGrid(Grid, BombGrid);
  printf("Players, Note Max is 2:\n");
    scanf(" %d", &players);
    printf("\n");
  printf("Would you like to start the game 'Y'/'N'\n");
    scanf(" %c", &startGame);
  printf("Score %d\n", score);
    DisplayOnce(Grid);

  while(startGame=='y'||startGame=='Y')
    {
      int x, y;

      
    printf("Player %d please enter the tile you would like to check: x y\n", currentPlayer);
      scanf("%d %d", &x, &y);
        printf("\n");
      updateGrid(Grid, BombGrid, x, y);
      if(players==1)
      {
      printf("Score %d\n", score);
      }
      else {
        printf("P1: Score is: %d, P2: Score is: %d\n", score, score2);
      }
      if(GameOver==1)
      {
        if(players==1)
        {
        printf("You have lost the game you score will now be displayed, \nscore: %d", score);
        return;
        }
        else 
        {
          printf("Player %d, you have lost the game scores are shown P1: %d, P2: %d\n", currentPlayer, score, score2); 
          return;
        }
      }


      printf("would you like to continut playing 'y'/'n'\n");
        scanf(" %c", &startGame);    
     }//END OF WHILE FOR GAME
  
  if(players==1)
  {
     printf("The game is over, Your Score is: %d\n", score);
  }
else {
   printf("The game is over. P1 Score: %d, P2 Score: %d\n", score, score2);
}

 }//END OF LOAD GAME

void MakeGrid(char Grid[ROWS][COLS], char BombGrid[ROWS][COLS])
{ 
  for(int i=0; i<ROWS; i++)
    {
      for(int j=0; j<COLS; j++)
        {int T=j+1;
          int F=i+1;
          //MAIN GRID
          Grid[i][j]='?';
          //TOP ROW
          Grid[0][0]='0';
          Grid[0][1]='1';
          Grid[0][2]='2';
          Grid[0][3]='3';
          Grid[0][4]='4';
          Grid[0][5]='5';
          Grid[0][6]='6';
          Grid[0][7]='7';
          Grid[0][8]='8';
          //FIRST COLUME
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
  for(int p=0; p<totalMine; p++)
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
    if(players==1)
    {
    GameOver++;
    Grid[x][y]='x';
    }
    else 
    {
      GameOver++;
      if (currentPlayer==1) 
      {
        score=score-1; 
      }
      else 
      {
        score2=score2-1;
      }
    }
  }

else
  {totalTile++;
    if(currentPlayer==1)
    {
    score=score+1;
    }
    if(currentPlayer==2)
    {
      score2=score2+1;
    }
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

  if(players==2)
    {
      if(currentPlayer==1)
      {
        currentPlayer=2;
      }
      else 
      {
        currentPlayer=1;
      }
    }

    for(int i=1; i<ROWS; i++)
      {
        for(int j=0; j<COLS; j++)
          {
            Grid[x][y]=bomb;
            printf(" %c ", Grid[i][j]);
          }
        printf("\n");
      } 
  }//END OF ELSE  

  if(totalTile==totalMine)
  {
    printf("Congratuations you have cleard the board and have one the game, Score: %d\n", score);
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




