/*
** EPITECH PROJECT, 2021
** straight line
** File description:
** checks if points are in a stright line
*/

#include <math.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct vector_s {
    float x;
    float y;
} vector_t;

vector_t get_vector(int x1, int y1, int x2, int y2)
{
    vector_t vector;
    float mod;

    vector.x = (x2 - x1);
    vector.y = (y2 - y1);
    mod = sqrt(pow(vector.x, 2) + pow(vector.y , 2));
    vector.x = vector.x / mod;
    vector.y = vector.y / mod;
    return (vector);
}

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
    int i = 0;
    int j = 0;
    vector_t vector = get_vector(coordinates[j][0], coordinates[j][1], coordinates[j + 1][0], coordinates[j + 1][1]);
    vector_t new_vector;

    j++;
    while (j < coordinatesSize) {
        if (j + 1 >= coordinatesSize)
            return (true);    
        new_vector = get_vector(coordinates[j][0], coordinates[j][1], coordinates[j + 1][0], coordinates[j + 1][1]);
        if (new_vector.x != vector.x || new_vector.y != vector.y)
            return (false);
        vector.x = new_vector.x;
        vector.y = new_vector.y;
        j++;
    }
    return (true);

}