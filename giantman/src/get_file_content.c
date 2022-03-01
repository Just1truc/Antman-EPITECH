/*
** EPITECH PROJECT, 2022
** antman
** File description:
** giantman
*/

#include "proto.h"

int get_file_size(char *file_name)
{
    struct stat f;
    stat(file_name, &f);
    return (f.st_size);
}

char *get_file_content(char *file_name)
{
    int i;
    char *buffer;
    struct stat f;
    int len;
    int fd = open(file_name, O_RDONLY);
    stat(file_name, &f);
    buffer = malloc(sizeof(char) * (f.st_size + 1));
    len = read(fd, buffer, f.st_size);
    buffer[len] = '\0';
    return buffer;
}
