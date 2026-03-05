#include <stdio.h>

/* ===================== PRINT BOARD ===================== */
void printBoard(char board[3][3])
{
  int i, j;
  
  printf("\n==========================\n");
  printf("||                      ||\n");
  printf("||        0 1 2         ||\n");
  for (i = 0; i < 3; i++)
    {
      printf("||      %d ", i);
      for (j = 0; j < 3; j++)
    	{
    	  printf("%c ", board[i][j]);
    	}
      printf("        ||\n");
    }
  printf("||                      ||\n");
  printf("==========================\n");
}

int checkIfFree(char board[3][3], int row, int column)
{
  if (board[row][column] == '.')
    return 1;
  else
    return 0;
}

void turnRed(char board[3][3], int* moveCounter)
{
  int row, column;
  int free;
  
  printf("\n~~~     RED'S TURN     ~~~\n");
  printf("Enter row: ");
  scanf("%d", &row);
  printf("Enter column: ");
  scanf("%d", &column);

  free = checkIfFree(board, row, column);
  /* 
    if the game is in the start phase, 
    mark invalid move if selected position is not free
  */
  if (*moveCounter <= 2)
  {
    if (free == 1)
    {
      *moveCounter += 1;
      printf("\nValid move.\n");
      printf("Red claims: (%d, %d)\n", row, column);
      printf("Move Counter: %d\n", *moveCounter);
      board[row][column] = 'R';
      printBoard(board);
    }
    
    else
    {
      printf("\n!! Invalid move. Try again. !!\n");
      turnRed(board, moveCounter);
    }
  }
  /* 
    if the game is in the start phase, 
    mark invalid move if selected position is not free
  */
  else
  {
    
  }
}

void turnBlue(char board[3][3], int* moveCounter)
{
  int row, column;
  int free;
  
  printf("\n~~~     BLUE'S TURN     ~~~\n");
  printf("Enter row: ");
  scanf("%d", &row);
  printf("Enter column: ");
  scanf("%d", &column);
  
  free = checkIfFree(board, row, column);
  /* 
    if the game is in the start phase, 
    mark invalid move if selected position is not free
  */
  if(*moveCounter <= 2)
  {
    if (free == 1)
    {
      *moveCounter += 1;
      printf("\nValid move.\n");
      printf("Blue claims: (%d, %d)\n", row, column);
      printf("Move Counter: %d\n", *moveCounter);
      board[row][column] = 'B';
      printBoard(board);
    }
    else
    {
      printf("\n!! Invalid move. Try again. !!\n");
      turnBlue(board, moveCounter);
    }
  }
  /* 
    if the game is in the start phase, 
    mark invalid move if selected position is not free
  */
  else 
  {
    
  }
  
}

int main()
{
  char board[3][3] = {
    {'.', '.', '.'},
    {'.', '.', '.'},
    {'.', '.', '.'}
  };
  int moveCounter = 0;

  printf("=============================================================\n");
  printf("                         START GAME                          \n");
  printf("=============================================================\n");
  
  printf("\nLegend:\n");
  printf("R = Red\n");
  printf("B = Blue\n");
  printf(". = Free\n");
  
  printf("\nRed goes first.\n");
  
  printBoard(board);

  printf("\nMove Counter: %d\n", moveCounter);
  printf("Game Phase: START\n");

  turnRed(board, &moveCounter);
  turnBlue(board, &moveCounter);
  
  printf("\nStart phase complete.\n");
  printf("Game Phase: NORMAL\n");

  printf("\n");
  printf("=============================================================\n");
  printf("                           END GAME                          \n");
  printf("=============================================================\n");
}
