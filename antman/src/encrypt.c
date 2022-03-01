/*
** EPITECH PROJECT, 2022
** antman
** File description:
** encrypt main
*/

#include "proto.h"

void get_final(char *final, char *result, int nbr)
{
    int i;
    int b;
    for (i = 8 - nbr, b = 0; result[i] != '\0';
    final[b] = result[i], b++, i++);
    final[b] = '\0';
}

void binary_ascii(char *str)
{
    int i;
    char c = 0;
    for (i = 0; i < 8; c += str[i], c = i + 1 == 8 ? c : c << 1, i++);
    write(1, &c, 1);
}

void write_over_ascii(char *final)
{
    int i;
    int y;
    char *b = malloc(sizeof(char) * 9);
    for (i = 0; i < 8; b[i] = final[i], i++);
    b[i] = '\0';
    for (y = 0; final[i] != '\0'; final[y] = final[i], i++, y++);
    final[y] = '\0';
}

char *get_results(char *ptr, chain_t *occ, nodes_t *nodeu, char *inside)
{
    char *result = malloc(sizeof(char) * (8 * (my_strlen(inside))));
    int i;
    int max = 0;
    int oui;
    for (i = 0; inside[i] != '\0'; i++) {
        ptr = find_node(ptr, nodeu, inside[i]);
        for (oui = 0; ptr[oui] != '\0'; oui++, max++) {
            result[max] = ptr[oui];
        }
    }
    result[max] = '\0';
    return result;
}

void hufman_file(char *file_name)
{
    char *inside = get_file_content(file_name);
    chain_t *occ = malloc(sizeof(chain_t) * my_strlen(inside));
    int len = get_chain(occ, inside);
    nodes_t *nodeu;
    low_t *lowests;
    char *ptr;
    char *result;
    char *final = malloc(sizeof(char) * 9);
    int i;
    int max = 0;
    build_tree(occ, len);
    for (i = 0; i < len && occ[i].in_list != 1; i++);
    build_binary_tree(occ[i].node, 0, "");
    nodeu = occ[i].node;
    ptr = display_key_sizes(nodeu);
    display_key_nodeu(nodeu);
    result = get_results(ptr, occ, nodeu, inside);
    encrypt_to_ascii(result);
    free(result);
}
