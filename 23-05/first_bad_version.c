/*
** EPITECH PROJECT, 2021
** main
** File description:
** main mr main
*/

#include <stdbool.h>

bool isBadVersion(int n);

int firstBadVersion(int n)
{
    for (int i = 1; i <= n; i++) {
        if (isBadVersion(i) == true)
            return (i);
    }
}