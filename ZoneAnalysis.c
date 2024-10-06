#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ZoneAnalysis.h"

int calculateArea(Zone *zone, int row, int column){

    printf("%d, %d\n", row, column);

    int area = 0;
    if((*zone).matrix[row][column] == '-'){

        (*zone).matrix[row][column] = 'P';
        area++;

        printf("%c\n", (*zone).matrix[row][column]);

        if(column + 1 < (*zone).width){

            area += calculateArea(zone, row, column + 1);

        }
        if(column - 1 >= 0){

            area += calculateArea(zone, row, column - 1);

        }
        if(row + 1 < (*zone).height){

            area += calculateArea(zone, row + 1, column);

        }
        if(row - 1 >= 0){

            area += calculateArea(zone, row - 1, column);

        }

        printf("%d\n", area);
        return area;

    }

}

int isShelter(Zone *zone, int row, int column){

    int area = 0;
    if((*zone).matrix[row][column] == 'P'){

        (*zone).matrix[row][column] = 'Q';
        area++;

        if(column + 1 < (*zone).width){

            area += isShelter(zone, row, column + 1);

        }
        if(column - 1 >= 0){

            area += isShelter(zone, row, column -1);

        }
        if(row + 1 < (*zone).height){

            area += isShelter(zone, row + 1, column);

        }
        if(row - 1 >= 0){

            area += isShelter(zone, row - 1, column);

        }

        return area;

    }

}

void analyseMatrix(Zone *zone, int capacity){

    int addedZones = 0;

    int *zones = (int*)calloc(2, sizeof(int));

    for(int i = 0; i < (*zone).height; i++){
		for(int j = 0; j < (*zone).width; j++){
			if((*zone).matrix[i][j] == '-'){
                if(addedZones >= capacity){
                    capacity *= 2;
                    int *newZones = (int*)realloc(zones, capacity * sizeof(int));
                    if(newZones == NULL){
                        printf("Error al asignar memoria.\n");
                        return;
                    }
                    zones = newZones;
                }

                zones[addedZones] = calculateArea(zone, i, j);
                addedZones++;
            }
		}
	}

    int max = findMax(zones, capacity);
    printf("%d", max);
    int amountZones = countShelters(zones, capacity, max);

}

void paintZone(Zone *zone, int row, int column, char initialValue, char newValue){

    if((*zone).matrix[row][column] == initialValue){
        (*zone).matrix[row][column] = newValue;

        if(column + 1 < (*zone).width){

            paintZone(zone, row, column + 1, initialValue, newValue);

        }
        if(column - 1 >= 0){

            paintZone(zone, row, column - 1, initialValue, newValue);

        }
        if(row + 1 < (*zone).height){

            paintZone(zone, row + 1, column, initialValue, newValue);

        }
        if(row - 1 >= 0){

            paintZone(zone, row - 1, column, initialValue, newValue);

        }
    }

}

void changeMatrix(Zone *zone, int max){

    for(int i; i < (*zone).height; i++){
        for(int j; j < (*zone).width; j++){
            if((*zone).matrix[i][j] == 'P'){
                if(isShelter(zone, i, j) == max){
                    paintZone(zone, i, j, 'Q', 'R');
                }
                else{
                    paintZone(zone, i, j, 'Q', '-');
                }
            }
        }
    }

}

int findMax(int *array, int capacity){

    int max = array[0];
    for(int i = 1; i < capacity; i++){
        if(array[i] > max){
            max = array[i];
        }
    }

    return max;

}

int countShelters(int *array, int capacity, int area){
    int count = 0;
    for(int i = 0; i < capacity; i++){

        if(array[i] == area){
            count++;
        }

    }

    return count;

}
