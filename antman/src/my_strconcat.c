/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** my_strconcat
*/

#include "proto.h"

char *my_strcat(char *str1, char *str2, char *result)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int i;

    result = malloc(sizeof(char) * (len1 + len2 + 1));
    for (i = 0; i < len1; i++)
        result[i] = str1[i];
    for (i; i < len1 + len2; i++)
        result[i] = str2[i - len1];
    result[i] = '\0';
    return (result);
}
