/*
** EPITECH PROJECT, 2021
** my_get_number
** File description:
** my
*/

#include "proto.h"

int my_getnbr(char const *str)
{
    int sum = 0;
    for (int i = 0; str[i] >= '0' && str[i] <= '9';
    sum += sum * 10 + (str[i] - '0'), i++);
    return sum;
}
