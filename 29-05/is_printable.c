/*
** EPITECH PROJECT, 2021
** is printable
** File description:
** check if printable
*/

#include <stdio.h>
#include <stdbool.h>

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
    grid->size = targetGridSize;
    grid->colSize = targetGridColSize;
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
    return (diff);
}

int next_num(grid_t *grid, int num)
{
    int i = 0;
    int j = 0;

    while (j < grid->size) {
        while (i < grid->colSize[j]) {
            if (num < grid->grid[j][i]) {
                num = grid->grid[j][i];
                return (num);
            }
            i++;
        }
        i = 0;
        j++;
    }
    return (-1);
}

rect_t update_rect(rect_t rect, int j, int i)
{
    if (j <= rect.top)
        rect.top = j;
    if (j >= rect.bottom)
        rect.bottom = j;
    if (i <= rect.left)
        rect.left = i;
    if (i >= rect.right)
        rect.right = i;
    return (rect);
}

rect_t first_rect(grid_t *grid, int num)
{
    int i = 0;
    int j = 0;
    rect_t rect;

    while (j < grid->size) {
        while (i < grid->colSize[j]) {
            if (grid->grid[j][i]) {
                rect.bottom = j;
                rect.top = j;
                rect.left = i;
                rect.right = i;
                return (rect);
            }
            i++;
        }
        i = 0;
        j++;
    }
    return (rect);
}

rect_t get_rekt(grid_t *grid, int num)
{
    int i = 0;
    int j = 0;
    rect_t rect = first_rect(grid, num);

    while (j < grid->size) {
        while (i < grid->colSize[j]) {
                if (grid->grid[j][i] ==  num)
                    rect = update_rect(rect, j, i);
            i++;
        }
        i = 0;
        j++;
    }
}

int check_rect(rect_t rect, grid_t *grid, int num)
{
    int i = rect.left;
    int j = rect.top;

    while (j <= rect.right) {
        while (i <= rect.bottom) {
            if (grid->grid[j][i] < num)
                return (1);
            j++;
        }
        i = rect.left;
        j++;
    }
    return (0);
}

bool isPrintable(int **targetGrid, int targetGridSize, int* targetGridColSize)
{
    grid_t *grid = get_grid(targetGrid, targetGridSize, targetGridColSize);
    int different = count_diff(grid);
    int i = 0;
    int num = 0;

    while (num != -1) {
        num = next_num(grid, num);
        if(check_rect(get_rekt(grid, num), grid, num) == 1) {
            free(grid);
            return (false);
        }
    }
    free(grid);
    return (true);
}