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
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int rows = sizeof(correctPos) / sizeof(correctPos[0]);
    int cols = sizeof(correctPos[0]) / sizeof(correctPos[0][0]);

    initBoard(currentPos, rows, cols);  
    printBoard(currentPos, rows, cols);

    printf("Want to calculate the most efficient way to solve the puzzle? (y/n): ");
    char choice;
    scanf("%c", &choice);

    if(tolower(choice) == 'y'){
        printf("Calculating");
    }

    getchar();
    return 0;
}
