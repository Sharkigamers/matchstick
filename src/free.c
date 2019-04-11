/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** free all
*/

#include "my.h"

void free_all(char **game_table)
{
    for (int j = 0; game_table[j] != NULL; j++)
        free(game_table[j]);
    free(game_table);
}
