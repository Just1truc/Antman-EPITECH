/*
** EPITECH PROJECT, 2022
** antman
** File description:
** check errors
*/

#include "proto.h"

int check_error(int ac, char **ag)
{
    int fd;
    struct stat f;
    char *buffer;
    int len;
    if (ac != 3)
        return 84;
    if (my_getnbr(ag[2]) < 1 || my_getnbr(ag[2]) > 3)
        return 84;
    if ((fd = open(ag[1], O_RDONLY)) == -1)
        return 84;
    else {
        stat(ag[1], &f);
        if ((buffer = malloc(sizeof(char) * (f.st_size + 1))) == NULL)
            return 84;
        if ((len = read(fd, buffer, f.st_size)) == -1)
            return 84;
        else {
            hufman_file(ag[1]);
        }
    }
}
