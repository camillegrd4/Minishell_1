/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** return lenght of a string
*/

#include "my.h"

int	my_strlen(char *str)
{
    int	i = 0;

    if (str == NULL)
        return -1;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}
