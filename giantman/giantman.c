/*
** EPITECH PROJECT, 2021
** antman
** File description:
** simple_description
*/

#include "proto.h"

int check_error(int ac, char **ag)
{
    int *i;
    int fd;
    struct stat f;
    char *buffer;
    if (ac != 3)
        return 84;
    if (my_getnbr(ag[2]) < 1 || my_getnbr(ag[2]) > 3)
        return 84;
    if ((i = malloc(sizeof(int))) == NULL)
        return 84;
    if ((fd = open(ag[1], O_RDONLY)) == -1)
        return 84;
    else {
        stat(ag[1], &f);
        buffer = malloc(sizeof(char) * (f.st_size + 1));
        if (read(fd, buffer, f.st_size) == -1)
            return 84;
        else
            decompress(ac, ag);
    }
}

int main(int ac, char **ag)
{
    if (check_error(ac, ag) == 84)
        return 84;
    return 0;
}
