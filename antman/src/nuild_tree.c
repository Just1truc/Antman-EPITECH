/*
** EPITECH PROJECT, 2022
** antman
** File description:
** build hufman tree
*/

#include "proto.h"

void build_binary_tree(nodes_t *node, int depth, char *binary)
{
    char c1[] = "1";
    char c0[] = "0";
    char *ptr;
    int i;
    if (node->right != NULL && node->left != NULL) {
        build_binary_tree(node->right, depth + 1, my_strcat(binary, c1, ptr));
        build_binary_tree(node->left, depth + 1, my_strcat(binary, c0, ptr));
    } else {
        node->binary_value = malloc(sizeof(char) * (depth + 1));
        for (i = 0; binary[i] != '\0'; node->binary_value[i] = binary[i], i++);
        node->binary_value[i] = '\0';
    }
}

void build_tree(chain_t *occ, int len)
{
    low_t *low;
    int node_nbr = len;
    int i;

    while (node_nbr > 1) {
        low = find_lowests(occ, len);
        create_inter_node(occ, low);
        node_nbr--;
        free(low);
    }
}

char *find_node(char *ptr, nodes_t *node, char to_find)
{
    if (node->right != NULL && node->left != NULL) {
        ptr = find_node(ptr, node->right, to_find);
        ptr = find_node(ptr, node->left, to_find);
        return ptr;
    } else {
        return node->c == to_find ? node->binary_value : ptr;
    }
}

int get_len_of_header(nodes_t *node, int oui)
{
    if (node->right != NULL && node->left != NULL) {
        oui = get_len_of_header(node->right, oui);
        oui = get_len_of_header(node->left, oui);
        return oui;
    } else {
        return oui + my_strlen(node->binary_value) / 8 + 3 +
        (my_strlen(node->binary_value) / 8 * 8 ==
        my_strlen(node->binary_value) ? 0 : 1);
    }
}

int my_strncat(char *str1, char *str2, int nbr)
{
    int i;
    int b;
    int max;
    for (i = 0; str1[i] != '\0'; i++);
    max = i;
    for (b = 0; str2[b] != '\0' && i < nbr; str1[i] = str2[b], i++, b++);
    str1[i] = '\0';
    return max;
}
