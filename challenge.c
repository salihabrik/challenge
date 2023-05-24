#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS (ROWS * COLS / 2)


typedef struct {
    int value;
    int isMatched;
    int isRevealed;
} Card;


void displayBoard(Card board[][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j].isRevealed) {
                printf("%2d ", board[i][j].value);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void generateCards(Card cards[]) {
    for (int i = 0; i < TOTAL_CARDS; i++) {
        cards[i].value = i + 1;
        cards[i].isMatched = 0;
        cards[i].isRevealed = 0;
    }
    
    for (int i = 0; i < TOTAL_CARDS; i++) {
        int randomIndex = rand() % TOTAL_CARDS;
        swap(&cards[i].value, &cards[randomIndex].value);
    }
}


int isGameComplete(Card board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (!board[i][j].isMatched) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));

    Card cards[TOTAL_CARDS];
    generateCards(cards);

    Card board[ROWS][COLS];

    
    int cardIndex = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = cards[cardIndex++];
        }
    }

    int score = 0;
    displayBoard(board);

    while (!isGameComplete(board)) {
        int row1, col1, row2, col2;

        printf("\nEnter the coordinates of the first card: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the coordinates of the second card: ");
        scanf("%d %d", &row2, &col2);

        if (row1 < 0 || row1 >= ROWS || col1 < 0 || col1 >= COLS || row2 < 0 || row2 >= ROWS || col2 < 0 || col2 >= COLS
 printf("Invalid coordinates! Please try again.\n");
            continue;
        }

        if (board[row1][col1].isMatched || board[row2][col2].isMatched || board[row1][col1].isRevealed || board[row2][col2].isRevealed) {
            printf("Invalid selection! Please choose different cards.\n");
            continue;
        }

        board[row1][col1].isRevealed = 1;
        board[row2][col2].isReve
                board[row2][col2].isRevealed = 1;
        displayBoard(board);

        if (board[row1][col1].value == board[row2][col2].value) {
            printf("\nMatch found!\n");
            board[row1][col1].isMatched = 1;
            board[row2][col2].isMatched = 1;
            score++;
        } else {
            printf("\nNo match!\n");
            sleep(2);
            board[row1][col1].isRevealed = 0;
            board[row2][col2].isRevealed = 0;
        }

        displayBoard(board);
    }

    printf("\nCongratulations! You completed the game with a score of %d.\n", score);

    return 0;
}
