/*
** EPITECH PROJECT, 2022
** antman
** File description:
** display needed informations
*/

#include "proto.h"

void display_binary_concat(char *binary_value)
{
    char c = 0;
    int b = 0;
    int i;
    for (i = 0; i < my_strlen(binary_value); i++) {
        c += binary_value[i] - '0';
        b++;
        if (b == 8 || my_strlen(binary_value) == i + 1) {
            write(1, &c, 1);
            b = i + 1 == my_strlen(binary_value) ? b : 0;
            c = 0;
        } else {
            c <<= 1;
        }
    }
    for (i = 0; binary_value[my_strlen(
    binary_value) - b + i] == '0'; i++);
    c = i + '0';
    write(1, &c, 1);
}

void display_key_nodeu(nodes_t *node)
{
    char c;
    int i;
    int b = 0;
    if (node->right != NULL && node->left != NULL) {
        display_key_nodeu(node->right);
        display_key_nodeu(node->left);
    } else {
        write(1, &node->c, 1);
        c = my_strlen(node->binary_value);
        write(1, &c, 1);
        display_binary_concat(node->binary_value);
    }
}

char *display_key_sizes(nodes_t *nodeu)
{
    int oui = 0;
    char *ptr;
    char c;
    oui = get_len_of_header(nodeu, oui);
    ptr = my_conv(oui, 10);
    c = my_strlen(ptr);
    write(1, &c, 1);
    write(1, ptr, my_strlen(ptr));
    return ptr;
}
