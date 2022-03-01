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

typedef struct tot {
    int b;
    int po;
    int total;
    int max2;
    int size;
    char *inside;
    char *key_size;
    char *res;
    char *bail;
    char *ptr;
    keys_t *qi;
    int i;
    int max;
    int s;
} tot_t;

void my_strcpy(char *str1, const char *str2);
int decompress(int ac, char **ag);
char *get_file_content(char *file_name);
int get_file_size(char *file_name);
int my_strlen(char const *str);
void my_special_strcat(char *str1, int len1, char *str2, int len2);
char *my_revstr(char *str);
int my_getnbr(char const *str);
char *my_ascii_to_binary(char *inside, int size);
void get_binary(int begin, char *inside, int size, char *decrypt);

#endif /* PROTO_H_ */
