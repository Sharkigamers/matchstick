/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** dumb ai
*/

#include "my.h"

void dumb_ai(char **game_table, int nb_line)
{
    int j;

    for (j = 0; game_table[nb_line + 1][j] != '\0'; j++);
    for (; nb_line > 0; nb_line--) {
        for (int k = j - 2; game_table[nb_line][k] > 0; k--) {
            if (game_table[nb_line][k] == '|') {
                game_table[nb_line][k] = ' ';
                my_putstr("AI removed 1 match(es) from line ");
                my_put_nbr(nb_line);
                my_putchar('\n');
                return;
            }
        }
    }
}
