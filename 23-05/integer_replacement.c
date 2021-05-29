/*
** EPITECH PROJECT, 2021
**  integer replacement
** File description:
** replaces integers
*/

int integerReplacement(int n)
{
    int moves = 0;

    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            if (((n - 1) / 2) % 2 == 0)
                n -= 1;
            else
                n += 1;
        moves++;
    }
    return (moves);
}