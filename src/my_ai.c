/*
** EPITECH PROJECT, 2019
** my_map
** File description:
** return
*/

#include "../lib/my/my.h"

int check_tab(count_t *count, char **str, int *tab)
{
    int index = 0;

    for (int i = 1 ; str[i] != NULL ; i++) {
        for (int j = 0 ; str[i][j] ; j++)
            if (str[i][j] == '|') index += 1;
        tab[i] = index;
        index = 0;
    }
    for (int i = 0 ; i != (count->line + 2) ; i++) {
        if (tab[i] > 1) return (1);
    }
    return (2);
}

void print_ai(count_t *count, char **str, int *tab)
{
    my_putstr("AI removed ");
    my_put_nbr(count->matchs);
    my_putstr(" match(es) from line ");
    my_put_nbr(count->m_line);
    my_putchar('\n');
}

int check_first(char **str, int *tab)
{
    int index = 0;

    for (int i = 1 ; str[i] != NULL ; i++) {
        for (int j = 0 ; str[i][j] != '|' && str[i][j] ; j++)
            if (str[i][j] == '|') index += 1;
    }
    if (index % 2 == 0) return (1);
    if (index % 2 == 1) return (2);
}

int my_ai(count_t *count, char **str, int *tab, int *i)
{
    int j = 0;
    while (check_tab(count, str, tab) == 1) {
        if (tab[j] > count->law) {
            count->matchs = rand()% (count->law) + 1;
            count->m_line = j;
            *i += 1;
            return (0);
        }
        if (tab[j] <= count->law && tab[j] > 1) {
            count->matchs = 1;
            count->m_line = j;
            *i += 1;
            return (0);
        }
        j += 1;
    } return (0);
}

int my_ai_second(count_t *count, char **str, int *tab, int *i)
{
    int j = 0;
    while (check_tab(count, str, tab) == 2) {
        if (check_first(str, tab) == 1 && tab[j] == 2) {
            count->matchs = 2;
            count->m_line = j;
            *i += 1;
            return (0);
        }
        if (check_first(str, tab) == 2 && tab[j] == 2 || tab[j] == 1) {
            count->matchs = 1;
            count->m_line = j;
            *i += 1;
            return (0);
        }
        j += 1;
    } return (0);
}