/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** giantman
*/

#include "proto.h"

void get_base_zero(char *inside, int b, char *decrypt)
{
    int val;
    for (val = 0; val < 8 - b;
    my_special_strcat(decrypt,
    my_strlen(decrypt) + 1, "0", 1), val++);
}

void get_end_zeros(char *inside, int size, char *decrypt)
{
    int val;
    for (val = '0'; val < inside[size - 1];
    my_special_strcat(decrypt,
    my_strlen(decrypt) + 1, "0", 1), val++);
}

int get_conv(char *convert, int nbr)
{
    int b = 0;
    while (nbr > 0) {
        convert[b] = nbr % 2 + '0';
        b++;
        nbr /= 2;
    }
    convert[b] = '\0';
    return b;
}

char *my_ascii_to_binary(char *inside, int size)
{
    char *decrypt = malloc(sizeof(char) * (8 * size));
    int i;
    int nbr;
    char *convert = malloc(sizeof(char) * 9);
    int b;
    int val;
    decrypt[0] = '\0';
    for (i = 0; i < size - 1; i++) {
        nbr = inside[i] >= 0 ? inside[i] : 256 + inside[i];
        b = get_conv(convert, nbr);
        if (i + 1 == size - 1) {
            get_end_zeros(inside, size, decrypt);
        } else {
            get_base_zero(inside, b, decrypt);
        }
        my_special_strcat(decrypt,
        my_strlen(decrypt) + 1, my_revstr(convert),
        my_strlen(convert));
    }
    return decrypt;
}
