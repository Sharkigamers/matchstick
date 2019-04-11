/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** proto
*/

#ifndef MY_
#define MY_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct marienbad
{
    int nb_stick;
    int **tab;
} mb_t;

/* lib */

void my_printf(char *fmt, ...);
int my_atoi(char const *str);
char *get_next_line(int fd);
int my_putchar(char);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_power(int nb, int p);

/* gest error */

int check_line(char **game_table, int line, char *buffer, int nb_line);
int check_enought_matches(char **game_table, int matches, int line);
int check_matches(int max_choice, char *buffer, int matches);

/* free */

void free_all(char **game_table);

/* disp map */

int turn_player(char **game_table, int nb_line, int max_choice);
int print_game(char **game_table, int player);

/* stock map */

char **stock_map(int nb_line);

/* game */

int matchstick(int nb_line, int max_choice);

/* ai */

void dumb_ai(char **game_table, int nb_line);
void fill_map(mb_t *mb, char **game_table, int nb_line);

#endif
