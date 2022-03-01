/*
** EPITECH PROJECT, 2021
** project name
** File description:
** simple description
*/

#ifndef PROTO_H_
    #define PROTO_H_
    #include <stddef.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <grp.h>
    #include <pwd.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #include <time.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>

typedef struct keys {
    char c;
    char *binary_value;
} keys_t;

typedef struct nodes {
    char c;
    int occ;
    struct nodes *right;
    struct nodes *left;
    char *binary_value;
} nodes_t;

typedef struct chain {
    nodes_t *node;
    int in_list;
} chain_t;

typedef struct low {
    nodes_t *node1;
    int id1;
    nodes_t *node2;
    int id2;
} low_t;

#endif /* PROTO_H_ */
