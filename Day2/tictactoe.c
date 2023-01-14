#include <stdio.h>
#include <stdbool.h>

bool check_winner(char board[3][3]);
bool is_board_full(char board[3][3]);
void print_board(char board[3][3]);
void get_user_input(int *row, int *col, char board[3][3]);

typedef enum
{
    X,
    O
} turn;

int main()
{
    // create a 3x3 array
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

    turn playerturn = X;

    while (!check_winner(board))
    {
        // clear the screen
        system("clear");

        // print the current turn
        printf("Turn: %c\n", playerturn == X ? 'X' : 'O');

        // print the board
        print_board(board);

        // get user input
        int row, col;
        get_user_input(&row, &col, board);

        // place the marker
        board[row][col] = playerturn == X ? 'X' : 'O';

        // change the turn
        playerturn = playerturn == X ? O : X;
        printf("\n");
    }

    return 0;
}

bool check_winner(char board[3][3])
{
    int row, col;
    // check for horizontal wins
    for (row = 0; row < 3; row++)
    {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != ' ')
        {
            printf("Player %c wins!\n", board[row][0]);
            return true;
        }
    }
    // check for vertical wins
    for (col = 0; col < 3; col++)
    {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != ' ')
        {
            printf("Player %c wins!\n", board[0][col]);
            return true;
        }
    }
    // check for diagonal wins
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        printf("Player %c wins!\n", board[0][0]);
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        printf("Player %c wins!\n", board[0][2]);
        return true;
    }
    // check for a tie
    if (is_board_full(board))
    {

        printf("It's a tie!\n");
        return true;
    }
    return false;
}

bool is_board_full(char board[3][3])
{
    int row, col;
    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
        {
            if (board[row][col] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void print_board(char board[3][3])
{
    int row, col;
    printf("\n A   B   C\n");
    // iterate through rows
    for (row = 0; row < 3; row++)
    {
        // iterate through columns
        for (col = 0; col < 3; col++)
        {
            printf(" %c ", board[row][col]);
            // print column separator
            if (col < 2)
                printf("|");
        }
        printf(" %d\n", row + 1);
        // print row separator
        if (row < 2)
            printf("---+---+---\n");
    }
    printf("\n");
}

void get_user_input(int *row, int *col, char board[3][3])
{
    char input[3];
    // Get user input
    printf("Enter the cell to place your marker (e.g. A1, B3, C2):\n");
    scanf("%s", input);

    // Extract the column and row from the input
    *col = input[0] - 'A';
    *row = input[1] - '1';

    // Check if the input is valid
    if (*col < 0 || *col > 2 || *row < 0 || *row > 2)
    {
        printf("Invalid input. Try again.\n");
        get_user_input(row, col, board);
    }

    // Check if the cell is already occupied
    if (board[*row][*col] != ' ')
    {
        printf("Cell is already occupied. Try again.\n");
        get_user_input(row, col, board);
    }
}