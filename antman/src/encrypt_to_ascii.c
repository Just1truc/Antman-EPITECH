/*
** EPITECH PROJECT, 2022
** antman
** File description:
** encrypt binary chain to ascii
*/

#include "proto.h"

void encrypt_zero_nbr(char *binary_chain, int max, int ptr)
{
    int i;
    char c;
    for (i = 0; i < ptr && binary_chain[max - ptr + i] == '0'; i++);
    c = i + '0';
    write(1, &c, 1);
}

void main_encryption(int c, int ptr, char *binary_chain, int i)
{
    char *encrypt = malloc(sizeof(char) * my_strlen(binary_chain));
    int b = 0;
    int max = my_strlen(binary_chain);
    for (i = 0; i < max; i++) {
        c += binary_chain[i] - '0';
        ptr++;
        if (ptr == 8 || i + 1 == max) {
            encrypt[b] = c;
            b++;
            c = 0;
            ptr = i + 1 == max ? ptr : 0;
        } else {
            c <<= 1;
        }
    }
    write(1, encrypt, b);
    encrypt_zero_nbr(binary_chain, max, ptr);
    free(encrypt);
}

void encrypt_to_ascii(char *binary_chain)
{
    char c = 0;
    int ptr = 0;
    int i = 0;
    main_encryption(c, ptr, binary_chain, i);
}
