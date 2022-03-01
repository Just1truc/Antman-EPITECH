/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** main decompression file
*/

#include "proto.h"

int get_y_id(char *inside, keys_t *qi, int i, int u)
{
    int y;
    for (y = 0; qi[u].binary_value[y] != '\0'; y++) {
        if (inside[i + y] != qi[u].binary_value[y])
            break;
    }
    return y;
}

int get_id(char *inside, keys_t *qi, int i, int b)
{
    int u;
    int y;
    for (u = 0; u < b - 1; u++) {
        y = get_y_id(inside, qi, i, u);
        if (qi[u].binary_value[y] == '\0')
            return u;
    }
}

int get_key_size(tot_t *to)
{
    to->b = 0;
    for (to->i = 1; to->i < to->inside[0] + 1;
    to->i += 1, to->b += 1) {
        to->key_size[to->b] = to->inside[to->i];
    }
    to->key_size[to->b] = '\0';
    return to->i;
}

void get_keys(tot_t *to)
{
    for (to->b = 0; to->i < to->max;) {
        to->qi[to->b].c = to->inside[to->i];
        to->i += 1;
        to->total = to->inside[to->i];
        to->max2 = to->inside[to->i] % 8 == 0 ?
        to->inside[to->i] / 8 : to->inside[to->i] / 8 + 1;
        to->qi[to->b].binary_value = malloc(sizeof(char)
        * (to->inside[to->i] + 1));
        to->i += 1;
        for (to->po = 0; to->po < to->max2; to->po += 1, to->i += 1) {
            to->qi[to->b].binary_value[to->po] = to->inside[to->i];
        }
        to->qi[to->b].binary_value[to->po] = to->inside[to->i];
        to->po += 1;
        to->i += 1;
        to->qi[to->b].binary_value[to->po] = '\0';
        to->qi[to->b].binary_value = my_ascii_to_binary(
        to->qi[to->b].binary_value, to->max2 + 1);
        to->b += 1;
    }
}

int decompress(int ac, char **ag)
{
    tot_t *to = malloc(sizeof(tot_t));
    to->size = get_file_size(ag[1]);
    to->inside = get_file_content(ag[1]);
    to->key_size = malloc(sizeof(char) * (to->inside[0] + 1));
    to->res = malloc(sizeof(char) * (to->size * 8));
    to->res[0] = '\0';
    to->key_size[0] = '\0';
    to->i = get_key_size(to);
    to->max = my_getnbr(to->key_size) + to->i;
    to->qi = malloc(sizeof(key_t) * to->max);
    get_keys(to);
    get_binary(to->i, to->inside, to->size, to->res);
    for (to->i = 0; to->res[to->i]; to->i += 1) {
        to->max = get_id(to->res, to->qi, to->i, to->b);
        write(1,  &to->qi[to->max].c, 1);
        to->i += my_strlen(to->qi[to->max].binary_value) - 1;
    }
    return 0;
}
