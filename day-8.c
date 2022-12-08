#include<stdio.h>
#include<stdbool.h>  

#define SIZE 99

char input[SIZE][SIZE];
int scenicScore[SIZE][SIZE];

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

int scenicScoreTop(int x, int y, char val){
    int score = 1;
    for(int i = y-1; i > 0; i--){
        int topVal = input[i][x];
        if(topVal < val) {
            score+=1;
        } else {
            break;
        }
    }

    return score;
}

int scenicScoreBottom(int x, int y, int val){
    int score = 1;
    for(int i = y+1; i < SIZE-1; i++){
        int bottomVal = input[i][x];
        if(bottomVal < val) {
            score+=1;
        } else {
            break;
        }
    }

    return score;
}

int scenicScoreLeft(int x, int y, int val){
    int score = 1;
    for(int i = x-1; i > 0; i--){
        int leftVal = input[y][i];
        if(leftVal < val) {
            score+=1;
        } else {
            break;
        }
    }

    return score;
}

int scenicScoreRight(int x, int y, int val){
    int score = 1;
    for(int i = x+1; i < SIZE-1; i++){
        int rightVal = input[y][i];
        if(rightVal < val) {
            score+=1;
        } else {
            break;
        }
    }

    return score;
}

int calculateSceniceScore(int x, int y, int val){
  printf("point x: %d, y: %d with val %d\n", x, y, val);
  printf("scenicScoreLeft: %d\n", scenicScoreLeft(x,y,val));
  printf("scenicScoreRight: %d\n", scenicScoreRight(x,y,val));
  printf("scenicScoreTop: %d\n", scenicScoreTop(x,y,val));
  printf("scenicScoreBottom: %d\n", scenicScoreBottom(x,y,val));
  printf("\n");
  return (scenicScoreLeft(x, y, val)*scenicScoreBottom(x,y,val)*scenicScoreRight(x,y,val)*scenicScoreTop(x,y,val));
}

bool isVisible(int x, int y, int val){
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
    while(scanf("%[^\n]%*c",input[i])==1){
        i++;
    }

    // input[y][x]
    // i = x-axis, j = y-axis
    int bestScenicScore = 0;

    for(int i = 1; i < SIZE-1; i++){
        for(int j = 1; j < SIZE-1; j++){
          int currScore = calculateSceniceScore(i,j,input[j][i]);
          if(currScore > bestScenicScore) bestScenicScore = currScore; 

            // on the edge
            /*if(i == 0 || i == SIZE-1 || j == 0 || j == SIZE-1) {
                visibleTrees++;
                continue;
            }*/


        }
    }

    printf("number of visible trees are: %d", visibleTrees);
    printf("Best scenic score is: %d\n", bestScenicScore);

    return 0;
}