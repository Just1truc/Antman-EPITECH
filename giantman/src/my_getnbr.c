/*
** EPITECH PROJECT, 2021
** my_get_number
** File description:
** my
*/

int my_getnbr(char const *str)
{
    int it;
    int sign;
    int c;

    c = 0;
    sign = 1;
    it = 0;
    while (str[it] >= 48 && str[it] <= 57) {
        c = c * 10 + (str[it] - 48);
        it++;
    }
    return (c * sign);
}
