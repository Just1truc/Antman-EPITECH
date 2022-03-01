/*
** EPITECH PROJECT, 2022
** antman
** File description:
** find lowess in occ
*/

#include "proto.h"

nodes_t *get_occ_base2(chain_t *occ, int len, low_t *low)
{
    int i;

    for (i = 0; i < len; i++) {
        if (occ[i].in_list == 1 && low->id1 != i) {
            return occ[i].node;
        }
    }
}

int get_id2(chain_t *occ, int len, low_t *low)
{
    int i;

    for (i = 0; i < len; i++) {
        if (occ[i].in_list == 1 && low->id1 != i) {
            return i;
        }
    }
}

void find_low(chain_t *occ, low_t *low, int len, int step)
{
    int i;
    for (i = 0; i < len && occ[i].in_list == 0; i++);
    low->node1 = step == 0 ? occ[i].node : low->node1;
    low->id1 = step == 0 ? i : low->id1;
    low->node2 = get_occ_base2(occ, len, low);
    low->id2 = get_id2(occ, len, low);

    for (i = 0; i < len; i++) {
        if (occ[i].node->occ < (step == 0 ? low->node1->occ
        : low->node2->occ) && occ[i].in_list == 1) {
            low->node1 = step == 0 ? occ[i].node : low->node1;
            low->id1 = step == 0 ? i : low->id1;
            low->node2 = step == 1 && low->id1 != i ? occ[i].node : low->node2;
            low->id2 = step == 1 && low->id1 != i ? i : low->id2;
        }
    }
}

low_t *find_lowests(chain_t *occ, int len)
{
    low_t *lowests = malloc(sizeof(low_t));
    lowests->node1 = occ[0].node;
    lowests->node2 = occ[0].node;
    lowests->id1 = 0;
    lowests->id2 = 0;
    find_low(occ, lowests, len, 0);
    find_low(occ, lowests, len, 1);
    return lowests;
}

void create_inter_node(chain_t *occ, low_t *low)
{
    nodes_t *new_node = malloc(sizeof(nodes_t));
    new_node->right = low->node2;
    new_node->left = low->node1;
    new_node->occ = low->node1->occ + low->node2->occ;
    new_node->c = 69;
    occ[low->id1].node = new_node;
    occ[low->id1].in_list = 1;
    occ[low->id2].in_list = 0;
}
