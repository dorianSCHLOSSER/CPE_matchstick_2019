/*
** EPITECH PROJECT, 2019
** my_error
** File description:
** return
*/

#include "../lib/my/my.h"

int check_element(char **str)
{
    for (int i = 0 ; str[i] != NULL ; i++) {
        for (int j = 0 ; str[i][j] ; j++) {
        if (str[i][j] == '|') return (1);
        }
    }
    return (0);
}

int check_m_line(count_t *count)
{
    if (count->m_line == -666 || count->m_line < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (count->m_line == 0 || count->m_line > count->line) {
        my_putstr("Error: this line is out of range\n");
        return (1);
    }
    return (0);
}

int check_nbr_element(count_t *count, char **str)
{
    int result = 0;
    for (int j = 0 ; str[count->m_line][j] ; j++) {
    if (str[count->m_line][j] == '|') result += 1;
    }
    return (result);
}

int check_matchs(count_t *count, char **str)
{
    int check_ele = check_nbr_element(count, str);
    if (count->matchs == -666 || count->matchs < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (count->matchs == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    if (count->matchs > count->law) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(count->law);
        my_putstr(" matches per turn\n");
        return (1);
    }
    if (count->matchs > check_ele) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    return (0);
}