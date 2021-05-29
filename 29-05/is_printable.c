/*
** EPITECH PROJECT, 2021
** is printable
** File description:
** check if printable
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct grid_s {
    int **grid;
    int size;
    int *colSize;
} grid_t;

typedef struct rect_s {
    int left;
    int right;
    int top;
    int bottom;
} rect_t;

grid_t *get_grid(int **targetGrid, int targetGridSize, int* targetGridColSize)
{
    grid_t *grid = malloc(sizeof(grid_t));

    grid->grid = targetGrid;
    grid->colSize = targetGridColSize;
    grid->size = targetGridSize;
    return (grid);
}

int count_diff(grid_t *grid)
{
    int num = 0;
    int diff = 0;
    int i = 0;
    int j = 0;

    while (j < grid->size) {
        while (i < grid->colSize[j]) {
            if (num < grid->grid[j][i]) {
                diff++;
                num = grid->grid[j][i];
            }
            i++;
        }
        i = 0;
        j++;
    }
    printf("diff : %d\n", diff);
    return (diff);
}

int next_num(grid_t *grid, int num)
{
    int i = 0;
    int j = 0;

    while (j < grid->size) {
        while (i < grid->colSize[j]) {
            printf("is %d < %d\n", num, grid->grid[j][i]    );
            if (num < grid->grid[j][i]) {
                num = grid->grid[j][i];
                printf("next num : %d\n", num);
                return (num);
            }
            i++;
        }
        i = 0;
        j++;
    }
    printf("return -1\n");
    return (-1);
}

rect_t *update_rect(rect_t *rect, int j, int i)
{
    if (j <= rect->top)
        rect->top = j;
    if (j >= rect->bottom)
        rect->bottom = j;
    if (i <= rect->left)
        rect->left = i;
    if (i >= rect->right)
        rect->right = i;
    return (rect);
}

rect_t *first_rect(grid_t *grid, int num)
{
    int i = 0;
    int j = 0;
    rect_t *rect = malloc(sizeof(rect_t));

    while (j < grid->size) {
        while (i < grid->colSize[j]) {
            if (grid->grid[j][i] == num) {
                rect->bottom = j;
                rect->top = j;
                rect->left = i;
                rect->right = i;
                return (rect);
            }
            i++;
        }
        i = 0;
        j++;
    }
    return (rect);
}

rect_t *get_rekt(grid_t *grid, int num)
{
    int i = 0;
    int j = 0;
    rect_t *rect = first_rect(grid, num);

    while (j < grid->size) {
        while (i < grid->colSize[j]) {
                if (grid->grid[j][i] ==  num)
                    rect = update_rect(rect, j, i);
            i++;
        }
        i = 0;
        j++;
    }
    return (rect);
}

int check_rect(rect_t *rect, grid_t *grid, int num)
{
    int i = rect->left;
    int j = rect->top;

    printf("num: %d\n", num);
    printf("rect left = %d\nrect right = %d\nrect top = %d\nrect bottom = %d\n", rect->left, rect->right, rect->top, rect->bottom);
    while (j <= rect->bottom) {
        while (i <= rect->right) {
            printf("i = %d\nj = %d\n", i, j);
            printf("%d < %d = grid->grid[%d][%d]\n", grid->grid[j][i], num, j, i);
            if (grid->grid[j][i] < num)
                return (1);
            i++;
        }
        i = rect->left;
        j++;
    }
    return (0);
}

bool isPrintable(int **targetGrid, int targetGridSize, int* targetGridColSize)
{
    grid_t *grid = get_grid(targetGrid, targetGridSize, targetGridColSize);
    rect_t *rect = NULL;
    int different = count_diff(grid);
    int i = 0;
    int num = 0;

    while (num != -1) {
        num = next_num(grid, num);
        if (num == -1)
            return (true);
        rect = get_rekt(grid, num);
        if(check_rect(rect, grid, num) == 1)
            return (false);
        free(rect);
    }
    return (true);
}