#include<stdio.h>
#include<stdbool.h>  

#define SIZE 99

char input[SIZE][SIZE];

bool isVisibleFromTop(int x, int y, char val){
    for(int i = 0; i < y; i++){
        if(input[x][i] >= val) {
            return false; // not visible
        }
    }
    return true; // visible
}

bool isVisibleFromBottom(int x, int y, char val){
    for(int i = SIZE-1; i > y; i--){
        if(input[x][i] >= val) {
            return false; // not visible
        }
    }
    return true; // visible
}

bool isVisibleFromRight(int x, int y, char val){
    for(int i = SIZE-1; i > x; i--){
        if(input[i][y] >= val) {
            return false; // not visible
        }
    }
    return true; // visible
}

bool isVisibleFromLeft(int x, int y, char val){
    for(int i = 0; i < x; i++){
        if(input[i][y] >= val) {
            return false; // not visible
        }
    }
    return true; // visible
}

bool isVisible(int x, int y, char val){
    /*if(x == 2 && y == 3) {
        if(isVisibleFromLeft(x, y, val)) printf("3 1 is visible from left\n");
        if(isVisibleFromBottom(x, y, val)) printf("2 3 is visible from bottom\n");
        if(isVisibleFromRight(x, y, val)) printf("3 1 is visible from right\n");
        if(isVisibleFromTop(x, y, val)) printf("3 1 is visible from top\n");
    }*/

    if(isVisibleFromLeft(x, y, val) || 
        isVisibleFromBottom(x,y,val) ||
        isVisibleFromRight(x,y,val) ||
        isVisibleFromTop(x,y,val)){
            return true;
        }
    return false;
}

int main(void) {
    int visibleTrees = 0;
    // %[^\n] scan until \n and save it in s (scanset)
    // %*c read and ignore \n

    int i = 0;
    while(scanf("%[^\n]%*c",&input[i])==1){
        // printf("input[%d] is: %s\n",i, input[i]);
        i++;
    }

    // i = x-axis, j = y-axis
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            // on the edge
            if(i == 0 || i == SIZE-1 || j == 0 || j == SIZE-1) {
                visibleTrees++;
                continue;
            }

            if(isVisible(i, j, input[i][j])){
                visibleTrees++;
                // printf("input[%d][%d] is visible with value %c\n", i, j, input[i][j]);
            }
        }
    }

    printf("number of visible trees are: %d", visibleTrees);

    return 0;
}