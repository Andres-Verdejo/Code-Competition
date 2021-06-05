/*
** EPITECH PROJECT, 2021
** find substring
** File description:
** finds a substring
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_letter(char c, char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int lengthOfLongestSubstring(char *s)
{
    int i = 0;
    int j = 0;
    char *substr = malloc(200);
    char *longest = malloc(200);

    substr[0] = '\0';
    if (s[0] != '\0') {
        longest[0] = s[0];
        longest[1] = '\0';
    }
    while (s[i] != '\0') {
        if (check_letter(s[i], substr) == 0) {
            for (j = 0; substr[j] != '\0'; j++);
            substr[j] = s[i];
            substr[j + 1] = '\0';
            j = 0;
        } else {
            if (strlen(substr) > strlen(longest))
                strcpy(longest, substr);
            substr[0] = '\0';
        }
        i++;
    }
    if (strlen(substr) > strlen(longest))
        strcpy(longest, substr);
    i = 0;
    while (longest[i] != '\0')
        i++;
    free(substr);
    free(longest);
    return (i);
}