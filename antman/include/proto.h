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

void my_strcpy(char *str1, const char *str2);
int my_getnbr(char const *str);
int check_error(int ac, char **ag);
void hufman_file(char *file_name);
char *find_node(char *ptr, nodes_t *node, char to_find);
void build_tree(chain_t *occ, int len);
void build_binary_tree(nodes_t *node, int depth, char *binary);
int get_len_of_header(nodes_t *node, int oui);
void display_binary_concat(char *binary_value);
void display_key_nodeu(nodes_t *node);
char *display_key_sizes(nodes_t *nodeu);
low_t *find_lowests(chain_t *occ, int len);
void create_inter_node(chain_t *occ, low_t *low);
int get_chain(chain_t *occ, char *str);
char *get_file_content(char *file_name);
int my_strlen(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *str1, char *str2, char *result);
char *my_conv(int nbr, int nb);
void encrypt_to_ascii(char *binary_chain);

#endif /* PROTO_H_ */
