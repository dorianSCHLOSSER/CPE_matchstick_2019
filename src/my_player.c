/*
** EPITECH PROJECT, 2019
** my_engine
** File description:
** return
*/

#include "../lib/my/my.h"

int getline_buffer(void)
{
    char *buffer = NULL;
    size_t bufsize = 32;
    int size;

    if (getline(&buffer, &bufsize, stdin) == -1) return (-1);
    size = my_getnbr(buffer);
    free(buffer);
    return (size);
}

int player_user(count_t *count, char **str, int *i)
{
    my_putstr("Line: ");
    count->m_line = getline_buffer();
    if (count->m_line  == -1) return (-1);
    if (check_m_line(count) == 1) return (player_user(count, str, i));
    my_putstr("Matches: ");
    count->matchs = getline_buffer();
    if (count->matchs  == -1) return (-1);
    if (check_matchs(count, str) == 1) return (player_user(count, str, i));
    my_putstr("Player removed ");
    my_put_nbr(count->matchs);
    my_putstr(" match(es) from line ");
    my_put_nbr(count->m_line);
    my_putchar('\n');
    remove_element(count, str);
    *i += 1;
    return (0);
}

void remove_element(count_t *count, char **str)
{
    int i = count->matchs;
    int j = count->line * 2;

    while (i > 0) {
        while (str[count->m_line][j] == ' ' || \
        str[count->m_line][j] == '*') j--;
        if (str[count->m_line][j] == '|')
            str[count->m_line][j] = ' ';
        i -= 1;
    }
    my_put_array(str);
}