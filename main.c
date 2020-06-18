/*
** EPITECH PROJECT, 2019
** main
** File description:
** return
*/

#include "lib/my/my.h"

int all_ia(count_t *count, char **str, int *tab, int *i)
{
    my_ai(count, str, tab, i);
    my_ai_second(count, str, tab, i);
    print_ai(count, str, tab);
    remove_element(count, str);
}

int start_game(count_t *count, char **str, int *tab, int *i)
{
    while (check_element(str) == 1) {
        if ((*i % 2) == 0) {
            my_putchar('\n');
            my_putstr("Your turn: \n");
            if (player_user(count, str, i) == -1) return (-1);
        }
        else if ((*i % 2) == 1) {
            my_putchar('\n');
            my_putstr("AI's turn...\n");
            all_ia(count, str, tab, i);
        }
    }
}

int final(int *i)
{
    if ((*i % 2) == 1) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    else {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
}

int check_error_argv(count_t *count, int argc, char **argv)
{
    if (count->line <= 1 || count->line >= 100) return (84);
    for (int i = 0 ; argv[2][i] ; i++) {
        if (argv[2][i] < '0' || argv[2][i] > '9') return (84);
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 3) return (84);
    int i = 0;
    count_t count = {0};
    count.line = my_getnbr(argv[1]);
    count.law = my_getnbr(argv[2]);
    if (check_error_argv(&count, argc, argv) == 84) return (84);
    int *tab = malloc_tab(&count);
    char **str = draw_str(&count);
    my_put_array(str);
    if (start_game(&count, str, tab, &i) == -1) return (0);
    if (final(&i) == 1) return (1);
    return (2);
}