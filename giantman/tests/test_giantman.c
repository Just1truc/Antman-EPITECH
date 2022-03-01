/*
** EPITECH PROJECT, 2022
** antman
** File description:
** test my program
*/

#include "proto.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(decompress , multiple , .init = redirect_all_std)
{
    char **dont_care;
    char test[] = "08z000e00101";

    test[0] = 0;
    test[3] = 1;
    test[4] = 1;
    test[7] = 1;
    test[8] = 0;
    test[10] = 1;
    dont_care = malloc(sizeof(char *) * 4);
    dont_care[0] = malloc(sizeof(char) * 8);
    dont_care[1] = malloc(sizeof(char) * 22);
    dont_care[2] = malloc(sizeof(char) * 8);
    my_strcpy(dont_care[0], "antman");
    my_strcpy(dont_care[1], "tests/test_file/compressed_file");
    my_strcpy(dont_care[2], "1");
    dont_care[3] = NULL;
    decompress(3, dont_care);
    cr_assert_stdout_neq_str(test);
}
