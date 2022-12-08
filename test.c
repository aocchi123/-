#define X -1
#define MAXNODE 9 
#include <stdio.h>

int main(void) {
    int ar[][MAXNODE] = {
        {X, 2, X, 1, X, X, X, X, X},//0
        {2, X, 2, X, 3, X, X, X, X},//1
        {X, 2, X, X, X, 2, X, X, X},//2
        {1, X, X, X, 1, X, 2, X, X},//3
        {X, 3, X, 1, X, 3, X, 3, X},//4
        {X, X, 2, X, 3, X, X, X, 1},//5
        {X, X, X, 2, X, X, X, 1, X},//6
        {X, X, X, X, 3, X, 1, X, 2},//7
        {X, X, X, X, X, 1, X, 2, X},//8
    };
    printf("ans=%d\n",ar[1][5]);
    }   