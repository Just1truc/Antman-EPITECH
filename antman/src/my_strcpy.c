/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** mdr
*/

#include "proto.h"

void my_strcpy(char *str1, const char *str2)
{
    int i;
    for (i = 0; str2[i]; str1[i] = str2[i], i++);
    str1[i] = '\0';
}
