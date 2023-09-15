#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX_MOVES 9
#define BOARD_SIZE 3

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(const char board[BOARD_SIZE][BOARD_SIZE]);
void makeMove(char board[BOARD_SIZE][BOARD_SIZE], int move, char currentPlayer);
int isWin(const char board[BOARD_SIZE][BOARD_SIZE], const char aiPlayer);
int isDraw(const char board[BOARD_SIZE][BOARD_SIZE]);
int isValidMove(const char board[BOARD_SIZE][BOARD_SIZE], int move);
int isGameOver(const char board[BOARD_SIZE][BOARD_SIZE], char player);

// Minimax
int getPoints(const char board[BOARD_SIZE][BOARD_SIZE], char aiPlayer);
int getAiBestMove(char board[BOARD_SIZE][BOARD_SIZE], char currentPlayer);
int minimax(char board[BOARD_SIZE][BOARD_SIZE]);

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);

    char currentPlayer = 'X';
    char aiPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    int move;

    // Main menu
    system("cls");
    printf("XOXOXOXOXOXOXOXOXOXOX\n|||| Tic-Tac-Toe ||||\nXOXOXOXOXOXOXOXOXOXOX\n\n");
    printf("How to play: choose any empty spot on the board by its number (1-9).\n");
    printf("Game map:\n 1 | 2 | 3\n-----------\n 4 | 5 | 6\n-----------\n 7 | 8 | 9\n");
    printf("You ready? Press any key to start!!\n");
    getch();

    for (int currentMove = 0; currentMove < MAX_MOVES; currentMove++) {
        system("cls");
        printBoard(board);

        if (currentPlayer == aiPlayer) {
            // AI's turn
            printf("\nSelina is thinking...\n");
            move = getAiBestMove(board, aiPlayer);
        } else {
            // Human's turn
            do {
                printf("\n[%c] > ", currentPlayer);
                scanf_s("%d", &move);
            } while (!isValidMove(board, move));
        }

        makeMove(board, move, currentPlayer);

        if (isWin(board, currentPlayer) == 1) {
            system("cls");
            printf("Player %c wins!\n\n", currentPlayer);
            printBoard(board);
            break;
        } else if (isDraw(board) == 1) {
            system("cls");
            printf("It's a draw!\n\n");
            printBoard(board);
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

int isWin(const char board[BOARD_SIZE][BOARD_SIZE], const char currentPlayer) {
    // Horizontal
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ( (board[i][0] == board[i][1] && board[i][1] == board[i][2]) && (board[i][0] == currentPlayer) ) {
            return 1;
        }

    }

    // Vertical
    for (int j = 0; j < BOARD_SIZE; j++) {
        if ( (board[0][j] == board[1][j] && board[1][j] == board[2][j]) && (board[0][j] == currentPlayer) ) {
            return 1;
        }
    }

    // Diagonal
    if ( (board[0][0] == board[1][1] && board[0][0] == board[2][2]) && (board[0][0] == currentPlayer) ) {
        return 1;
    }

    if ( (board[2][0] == board[1][1] && board[1][1] == board[0][2]) && (board[2][0] == currentPlayer) ) {
        return 1;
    }

    return 0;
}

int isDraw(const char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int line = 0; line < BOARD_SIZE; line++) {
        if (board[line][0] == '_' || board[line][1] == '_' || board[line][2] == '_') {
            return 0;
        }
    }
    return 1;
}

int isValidMove(const char board[BOARD_SIZE][BOARD_SIZE], int move) {
    if (move >= 1 && move <= 9) {
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        if (board[row][col] == '_') {
            return 1;
        }
    }
    return 0;
}

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '_';
        }
    }
}

void printBoard(const char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < BOARD_SIZE - 1) printf("-----------\n");
    }
}

void makeMove(char board[BOARD_SIZE][BOARD_SIZE], int move, char currentPlayer) {
    if (move >= 1 && move <= 9) {
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        board[row][col] = currentPlayer;
    }
}

int isGameOver(const char board[BOARD_SIZE][BOARD_SIZE], char player) {
    return ( (isWin(board, player)) || (isDraw(board)) || (isWin(board, (player == 'X') ? 'O' : 'X')) );
}

// Minimax
int getPoints(const char board[BOARD_SIZE][BOARD_SIZE], char aiPlayer) {
    if (isWin(board, aiPlayer)) {
        return 1; // AI player wins
    } else if (isWin(board, (aiPlayer == 'X') ? 'O' : 'X')) {
        return -1; // Opponent wins
    } else if (isDraw(board)) {
        return 0; // It's a draw
    } else {
        return 0; // The game is still ongoing (no immediate result)
    }
}

int getAiBestMove(char board[BOARD_SIZE][BOARD_SIZE], char currentPlayer) {
    int bestMove = -1;
    int bestScore = -2;

    for (int move = 1; move <= 9; move++) {
        if (isValidMove(board, move)) {
            makeMove(board, move, currentPlayer);
            int score = minimax(board);
            makeMove(board, move, '_'); // Undo move
            if (score > bestScore) {
                bestScore = score;
                bestMove = move;
            }
        }
    }
    return bestMove;
}

int minimax(char board[BOARD_SIZE][BOARD_SIZE]) {
    return 1;
}
