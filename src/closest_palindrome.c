/*
** EPITECH PROJECT, 2021
**  closest palindrome
** File description:
** finds the closest integer palindrome
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *strrev(char *str)
{
    char *p1, *p2;

    if (! str || ! *str)
        return (str);
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return (str);
}

int check_palindrome(char *n)
{
    char *nr = malloc(100);

    strcpy(nr, n);
    strrev(nr);
    printf("nr = %s\nn = %s\n", nr, n);
    if (strcmp(nr, n) == 0)
        return (1);
    return (0);
}

char *plus(char *str, int i)
{
    int num = atoi(str);
    char *number = malloc(100);

    num += i;
    sprintf(number, "%d", num);
    return (number);
}

char *minus(char *str, int i)
{
    int num = atoi(str);
    char *number = malloc(100);

    num -= i;
    sprintf(number, "%d", num);
    return (number);
}

char *nearestPalindromic(char *n)
{
    int i = 1;

    while (check_palindrome(minus(n, i)) != 1 && check_palindrome(plus(n, i)) != 1)
        i++;
    if (check_palindrome(minus(n, i)) == 1)
        return (minus(n, i));
    if (check_palindrome(plus(n, i)) == 1)
        return (plus(n, i));
    return (0);
}