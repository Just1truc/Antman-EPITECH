/*
** EPITECH PROJECT, 2022
** antman
** File description:
** get list of occurency
*/

#include "proto.h"

void init_list_element(chain_t *occ, int i, int b, char *str)
{
    occ[b].node = malloc(sizeof(nodes_t));
    occ[b].node->c = str[i];
    occ[b].node->occ = 1;
    occ[b].in_list = 1;
    occ[b].node->right = NULL;
    occ[b].node->left = NULL;
}

int get_y_node(chain_t *occ, int b, char *str, int i)
{
    int y;
    for (y = 0; y < b; y++) {
        if (occ[y].node->c == str[i]) {
            occ[y].node->occ++;
            break;
        }
    }
    return y;
}

int get_chain(chain_t *occ, char *str)
{
    int i;
    int y;
    int b = 1;
    init_list_element(occ, 0, 0, str);

    for (i = 1; str[i] != '\0'; i++) {
        y = get_y_node(occ, b, str, i);
        if (y == b) {
            init_list_element(occ, i, b, str);
            b++;
        }
    }
    return b;
}

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
