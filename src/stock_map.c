/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** stock the matchstick's game map
*/

#include "my.h"

void fill_table(int nb_stars, char **game_table, int line)
{
    int i;

    for (i = 0; i < (nb_stars + 2); i++)
        game_table[line][i] = '*';
    game_table[line][i] = '\n';
    game_table[line][i + 1] = '\0';
}

void fill_sigpipe(char **game_table, int *sigpipe, int *j, int i)
{
    for (int k = 0; k < *sigpipe; k++) {
        game_table[i][*j] = '|';
        (*j)++;
    }
    *sigpipe += 2;
}

void fill_in_table(char **game_table, int i, int *sigpipe, int nb_line)
{
    int j = 1;

    game_table[i][0] = '*';
    for (int k = 0; k != 2; k++) {
        for (int l = nb_line - i; l > 0; l--) {
            game_table[i][j] = ' ';
            j++;
        }
        if (k == 0)
            fill_sigpipe(game_table, sigpipe, &j, i);
    }
    game_table[i][j] = '*';
    game_table[i][j + 1] = '\n';
    game_table[i][j + 2] = '\0';
}

char **stock_map(int nb_line)
{
    int nb_stars = 1;
    int sigpipe = 1;
    char **game_table = malloc(sizeof(char *) * (nb_line + 3));
    int i;

    for (int k = 1; k < nb_line; k++)
        nb_stars += 2;
    for (int k = 0; k < (nb_line + 2); k++)
        game_table[k] = malloc(nb_stars + 4);
    game_table[(nb_line + 2)] = NULL;
    fill_table(nb_stars, game_table, 0);
    for (i = 1; i < (nb_line + 1); i++)
        fill_in_table(game_table, i, &sigpipe, nb_line);
    fill_table(nb_stars, game_table, (nb_line + 1));
    return (game_table);
}
