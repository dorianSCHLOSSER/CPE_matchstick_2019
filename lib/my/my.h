/*
** EPITECH PROJECT, 2019
** _MY_H_
** File description:
** return
*/

#ifndef _MY_H_
#define _MY_H_
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int my_getnbr(char const *str);
void my_put_array(char **str);
int my_putstr(char const *str);
void my_put_nbr(int nb);
void my_putchar(char c);
int my_strlen(char const *str);
int getline_buffer(void);
int check_element(char **str);
int check_first(char **str, int *tab);

typedef struct count_s
{
    int matchs;
    int line;
    int m_line;
    int law;
} count_t;

int player_user(count_t *count, char **str, int *i);
void remove_element(count_t *count, char **str);
int check_m_line(count_t *count);
int check_matchs(count_t *count, char **str);
char **malloc_str(count_t *count);
char **draw_str(count_t *count);
int check_nbr_element(count_t *count, char **str);
int *malloc_tab(count_t *count);
int my_ai(count_t *count, char **str, int *tab, int *i);
void print_ai(count_t *count, char **str, int *tab);
int check_tab(count_t *count, char **str, int *tab);
int my_ai_second(count_t *count, char **str, int *tab, int *i);
int all_ia(count_t *count, char **str, int *tab, int *i);

#endif
