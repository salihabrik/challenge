#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

struct Card {
    char symbol;
    int isMatched;
    int isRevealed;
};

void initializeBoard(struct Card board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int symbolCount = 0;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j].symbol = symbols[symbolCount];
            board[i][j].isMatched = 0;
            board[i][j].isRevealed = 0;
            symbolCount++;
        }
    }
}

void shuffleBoard(struct Card board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    srand(time(NULL));

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            int randomRow = rand() % BOARD_SIZE;
            int randomCol = rand() % BOARD_SIZE;
            struct Card temp = board[i][j];
            board[i][j] = board[randomRow][randomCol];
            board[randomRow][randomCol] = temp;
        }
    }
}

void displayBoard(struct Card board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].isRevealed) {
                printf("%c ", board[i][j].symbol);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int main() {
    struct Card board[BOARD_SIZE][BOARD_SIZE];
    int score = 0;
    int moves = 0;

    initializeBoard(board);
    shuffleBoard(board);

    while (score < (BOARD_SIZE * BOARD_SIZE) / 2) {
        int row1, col1, row2, col2;

        printf("Enter coordinates of first card (row column): ");
        scanf("%d %d", &row1, &col1);

        if (row1 < 0 || row1 >= BOARD_SIZE || col1 < 0 || col1 >= BOARD_SIZE) {
            printf("Invalid coordinates! Please try again.\n");
            continue;
        }

        if (board[row1][col1].isMatched || board[row1][col1].isRevealed) {
            printf("Invalid coordinates! Please try again.\n");
            continue;
        }

        printf("Enter coordinates of second card (row column): ");
        scanf("%d %d", &row2, &col2);

        if (row2 < 0 || row2 >= BOARD_SIZE || col2 < 0 || col2 >= BOARD_SIZE) {
            printf("Invalid coordinates! Please try again.\n");
            continue;
        }

        if (board[row2][col2].isMatched || board[row2][col2].isRevealed) {
            printf("Invalid coordinates! Please try again.\n");
            continue;
        }

        if (board[row1][col1].symbol == board[row2][col2].symbol) {
            printf("Match found!\)
       