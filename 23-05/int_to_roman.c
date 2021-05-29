/*
** EPITECH PROJECT, 2021
** int to roman
** File description:
** integer into roman number
*/

#include <string.h>

int which_letter(char c)
{
    if (c == 'I')
        return (1);
    if (c == 'V')
        return (5);
    if (c == 'X')
        return (10);
    if (c == 'L')
        return (50);
    if (c == 'C')
        return (100);
    if (c == 'D')
        return (500);
    if (c == 'M')
        return (1000);
}

int romanToInt(char *str)
{
    int num = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i + 1] != '\0' && which_letter(str[i]) < which_letter(str[i + 1]))
            num -= which_letter(str[i]);
        else
            num += which_letter(str[i]);
    return (num);
}
