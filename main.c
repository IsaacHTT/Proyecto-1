#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ZoneAnalysis.h"

int main(){

    Zone zona;

    zona.width = 4;
    zona.height = 5;

    zona.matrix = (char**)malloc(5*sizeof(char*));
    for(int i = 0; i < 5; i++){
        zona.matrix[i] = (char*)malloc(4*sizeof(char));
    }

    /*zona.matrix[0][0] = '-';
    zona.matrix[0][1] = 'X';
    zona.matrix[1][0] = '-';
    zona.matrix[1][1] = 'X';*/

    zona.matrix[0][0] = 'X';
    zona.matrix[0][1] = 'X';
    zona.matrix[0][2] = '-';
    zona.matrix[0][3] = 'X';
    zona.matrix[1][0] = 'X';
    zona.matrix[1][1] = '-';
    zona.matrix[1][2] = 'X';
    zona.matrix[1][3] = 'X';
    zona.matrix[2][0] = 'X';
    zona.matrix[2][1] = '-';
    zona.matrix[2][2] = '-';
    zona.matrix[2][3] = 'X';
    zona.matrix[3][0] = '-';
    zona.matrix[3][1] = 'X';
    zona.matrix[3][2] = '-';
    zona.matrix[3][3] = '-';
    zona.matrix[4][0] = '-';
    zona.matrix[4][1] = 'X';
    zona.matrix[4][2] = 'X';
    zona.matrix[4][3] = 'X';
    

    for(int i = 0; i < zona.height; i++){
        for(int j = 0; j < zona.width; j++){
            printf("%c", zona.matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    analyseMatrix(&zona, 2);

    for(int i = 0; i < zona.height; i++){
        for(int j = 0; j < zona.width; j++){
            printf("%c", zona.matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    changeMatrix(&zona, 5);

    for(int i = 0; i < zona.height; i++){
        for(int j = 0; j < zona.width; j++){
            printf("%c", zona.matrix[i][j]);
        }
        printf("\n");
    }





    return 0;

}