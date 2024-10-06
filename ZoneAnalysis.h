typedef struct
{

    char **matrix;
    int width;
    int height;
    

} Zone;



//char** makeMatrix();

int calculateArea(Zone *zone, int row, int column);
void analyseMatrix(Zone *zone, int capacity);
void changeMatrix(Zone *zone, int max);
void paintZone(Zone *zone, int row, int column, char initialValue, char newValue);
int isShelter(Zone *zone, int row, int column);
int findMax(int *array, int capacity);
int countShelters(int *array, int capacity, int area);