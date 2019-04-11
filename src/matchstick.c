/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** reproduce the matchstick's game
*/

#include "my.h"

int lap(char **game_table, int nb_line, int max_choice, int player)
{
    int gest = 0;

    if (player == 0) {
        my_printf("Your turn:\n");
        while ((gest = turn_player(game_table, nb_line, max_choice)) == 1);
        player = 1;
        if (gest == 84)
            return (84);
    }
    else {
        my_printf("AI's turn...\n");
        dumb_ai(game_table, nb_line);
        player = 0;
    }
    return (player);
}

int matchstick(int nb_line, int max_choice)
{
    mb_t mb;
    char **game_table = stock_map(nb_line);
    int player = 0;
    int end = 0;

    fill_map(&mb, game_table, nb_line);
    while (42) {
        if ((end = print_game(game_table, player)) != 0) {
            return (end);
        }
        player = lap(game_table, nb_line, max_choice, player);
        if (player == 84) {
            free_all(game_table);
            return (0);
        }
    }
    free_all(game_table);
}
