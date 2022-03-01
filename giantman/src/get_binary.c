/*
** EPITECH PROJECT, 2022
** antman
** File description:
** get binary from ascii_char
*/

#include "proto.h"

int write_basic_zeros(char *inside, int dec, char *decrypt, int b)
{
    int val;
    for (val = 0; val < 8 - b; decrypt[dec] = '0', val++, dec++);
    return dec;
}

int write_final_zeros(char *inside, int size, char *decrypt, int dec)
{
    int val;
    for (val = '0'; val < inside[size - 1]; decrypt[dec] = '0', val++, dec++);
    return dec;
}

int get_convertion(char *convert, int nbr)
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

void get_binary(int begin, char *inside, int size, char *decrypt)
{
    int i;
    int nbr;
    char *convert = malloc(sizeof(char) * 9);
    int b;
    int val;
    int dec = 0;
    decrypt[0] = '\0';
    for (i = begin; i < size - 1; i++) {
        nbr = inside[i] >= 0 ? inside[i] : 256 + inside[i];
        convert[0] = '\0';
        b = get_convertion(convert, nbr);
        if (i + 1 == size - 1) {
            dec = write_final_zeros(inside, size, decrypt, dec);
        } else {
            dec = write_basic_zeros(inside, dec, decrypt, b);
        }
        for (val = b - 1; val >= 0 && b != 0;
        decrypt[dec] = convert[val], val--, dec++);
    }
    decrypt[dec] = '\0';
}
