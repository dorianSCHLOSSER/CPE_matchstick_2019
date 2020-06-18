/*
** EPITECH PROJECT, 2019
** my_map
** File description:
** return
*/

#include "../lib/my/my.h"

char **malloc_str(count_t *count)
{
    char **str = NULL;
    int i = 0;
    str = malloc(sizeof(char *) * (count->line + 3));
    for (i = 0 ; i < (count->line + 2) ; i++) {
        str[i] = malloc(sizeof(char) * (count->line * 2) + 2);
        for (int j = 0 ; j < (count->line * 2) + 2 ; j++) {
            if (i == 0 || i == count->line + 1) {
            str[i][j] = '*';
            str[i][(count->line * 2) + 1] = '\0';
            }
            else {
            str[i][0] = '*';
            str[i][j] = ' ';
            str[i][count->line * 2] = '*';
            str[i][(count->line * 2) + 1] = '\0';
            }
        }
    }
    str[i] = NULL;
    return (str);
}

char **draw_str(count_t *count)
{
    char **str = malloc_str(count);
    int start = count->line;
    int end = count->line;

    for (int i = 1 ; str[i + 1] != NULL ; i++) {
        for (int j = 0 ; str[i][j] ; j++)
            if (j >= start && j <= end) {
            str[i][j] = '|';
            }
        start -= 1;
        end += 1;
    }
    return (str);
}

int *malloc_tab(count_t *count)
{
    int *tab = NULL;

    tab = malloc(sizeof(int) * (count->line + 2));

    return (tab);
}