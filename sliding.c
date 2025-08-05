#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int correctPos[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,0}
};

int currentPos[3][3] = {
    {0,0,0},
    {0,0,0},
    {0,0,0}
};

int used[9] = {0};  
int moves = 0;
int leastVal;

void initBoard(int (*arr)[3], int row, int col) { 
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            int num = rand() % 9;  
            if(used[num] == 0){
                arr[i][j] = num;  
                used[num] = 1;
            } else {
                j--; 
            }
        }
    }
}

void printBoard(int (*arr)[3], int row, int col) {
    printf("Current Board:\n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}

int calculateMostEfficientWay(int (*arr)[3], int row, int col) {
    int tempMoves = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j] != correctPos[i][j]){
                for(int k = 0; k < row; k++){
                    for(int l = 0; l < col; l++){
                        if(arr[i][j] == correctPos[k][l]){
                            if (tempMoves < moves){
                                moves = tempMoves;
                                tempMoves = 0;
                                leastVal = arr[i][j];
                                return 1;
                            }
                        }
                        tempMoves++;
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));

    int rows = sizeof(correctPos) / sizeof(correctPos[0]);
    int cols = sizeof(correctPos[0]) / sizeof(correctPos[0][0]);

    initBoard(currentPos, rows, cols);  
    printBoard(currentPos, rows, cols);

    printf("Want to calculate the most efficient way to solve the puzzle? (y/n): ");
    char choice;
    scanf(" %c", &choice);  // space before %c to consume newline

    if(tolower(choice) == 'y'){
        moves = 1000;  // set to a large number
        printf("Calculating...\n");
        int val = calculateMostEfficientWay(currentPos, rows, cols);
        if (val == 1){
            printf("The number %d takes %d amount of moves\n", leastVal, moves);
            getchar();
        } else {
            printf("No better move found.\n");
        }
        getchar();
    }

    return 0;
}
