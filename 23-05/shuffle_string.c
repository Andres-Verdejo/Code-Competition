/*
** EPITECH PROJECT, 2021
** shuffle string
** File description:
** shuffles a string
*/

#include <stdlib.h>

char *restoreString(char *s, int *indices, int indicesSize)
{
    int j = 0;
    char *str = malloc(indicesSize + 1);

    for (int i = 0; i < indicesSize; i++)
        str[indices[i]] = s[i];
    str[indicesSize] = '\0';
    return (str);
}