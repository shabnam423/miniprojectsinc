#include <stdio.h>
// TIC TAC TOE
#define Red "\x1b[31m"
#define Green "\x1b[32m"
#define Blue "\x1b[34m"
#define Cyan "\x1b[36m"
#define Reset "\x1b[0m"

char board[3][3];
void init_board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '_';
            if (i == 2)
            {
                board[i][j] = ' ';
            }
        }
    }
}
void Show_board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("|%c", board[i][j]);
        }
        printf("|\n");
    }
}
void player(int currentPlayer)
{
    int row;
    int column;

    printf("%d player's turn\n", currentPlayer);
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter column: ");
    scanf("%d", &column);

    char symbol = (currentPlayer == 1) ? 'X' : 'O';

    if (board[row - 1][column - 1] == '_' || board[row - 1][column - 1] == ' ')
    {
        board[row - 1][column - 1] = symbol;
    }
    else if (board[row - 1][column - 1] == 'X' || board[row - 1][column - 1] == 'O' || row > 3 || column > 3 || row < 1 || column < 1)
    {
        printf("Invalid move\n %d player tries again.\n", currentPlayer);
        player(currentPlayer);
    }

    Show_board();
}
int check4win()
{

    // check horizontal
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
        {
            return 1;
        }
        else if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
        {
            return 2;
        }
    }
    // check vertical
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == 'X' && board[1][j] == 'X' && board[2][j] == 'X')
        {
            return 1;
        }
        else if (board[0][j] == 'O' && board[1][j] == 'O' && board[2][j] == 'O')
        {
            return 2;
        }
    }

    // check diagonal
    if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
    {
        return 1;
    }
    else if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
             (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
    {
        return 2;
    }
    return 0;
}

int main()
{
    init_board();
    Show_board();

    int currentPlayer = 1;


    while (check4win() != 1 && check4win() != 2)
    {
        player(currentPlayer);
        if (check4win() == 1 || check4win() == 2)
            break; 
       
       currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    if (check4win() == 1)
    {
        printf(Blue "Player 1 wins!" Reset);
    }
    else if (check4win() == 2)
    {
        printf(Red "Player 2 wins!" Reset);
    }
    else
    {
        printf(Green "Draw" Reset);
    }
    return 0;
}