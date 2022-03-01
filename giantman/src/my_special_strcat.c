/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#include "proto.h"

void my_special_strcat(char *str1, int len1, char *str2, int len2)
{
    int i;

    for (i = len1 - 1; i < len1 + len2; str1[i] = str2[i - len1 + 1], i++);
}
