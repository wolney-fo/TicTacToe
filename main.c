#include <stdio.h>
#include <stdlib.h>

int verifyWin();

int main()
{
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    char turn = 'X';
    int move;

    do {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printBoard(board);

        printf("\n (%c) > ", turn);
        scanf_s("%d", &move);

        switch (move) {
            case 1:
                board[0][0] = turn;
                break;
            case 2:
                board[0][1] = turn;
                break;
            case 3:
                board[0][2] = turn;
                break;
            case 4:
                board[1][0] = turn;
                break;
            case 5:
                board[1][1] = turn;
                break;
            case 6:
                board[1][2] = turn;
                break;
            case 7:
                board[2][0] = turn;
                break;
            case 8:
                board[2][1] = turn;
                break;
            case 9:
                board[2][2] = turn;
                break;
            default:
                printf("\n\nInvalid position!!");
        }

        turn = (turn == 'X') ? 'O' : 'X';

    } while (verifyWin(board) == 0);

    printf("\n\nFinished game!!!\n");
    printBoard(board);

    return 0;
}

int verifyWin(char currentBoard[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (currentBoard[i][0] == currentBoard[i][1] && currentBoard[i][1] == currentBoard[i][2]) {
            return 1;
        }

    }

    for (int j = 0; j < 3; j++) {
        if (currentBoard[0][j] == currentBoard[1][j] && currentBoard[1][j] == currentBoard[2][j]) {
            return 1;
        }
    }

    if (currentBoard[0][0] == currentBoard[1][1] && currentBoard[0][0] == currentBoard[2][2]) {
        return 1;
    }

    if (currentBoard[2][0] == currentBoard[1][1] && currentBoard[1][1] == currentBoard[0][2]) {
        return 1;
    }

    return 0;
}

void printBoard(char currentBoard[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", currentBoard[i][0], currentBoard[i][1], currentBoard[i][2]);
        if (i < 2) {
            printf("-----------");
            printf("\n");
        }
    }
}
