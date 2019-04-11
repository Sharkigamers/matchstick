/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** disp_map
*/

#include "my.h"

int check_end(char **game_table, int player)
{
    int end = 0;

    for (int i = 0; game_table[i] != NULL; i++) {
        for (int j = 0; game_table[i][j] != '\0'; j++)
            game_table[i][j] == '|' ? end++ : 0;
    }
    if (end == 0 && player == 1) {
        my_printf("You lost, too bad...");
        return (2);
    }
    if (end == 0 && player == 0) {
        my_printf("I lost... snif... but I'll get you next time!!");
        return (1);
    }
    return (0);
}

int print_game(char **game_table, int player)
{
    int end = 0;

    for (int j = 0; game_table[j] != NULL; j++)
        my_printf("%s", game_table[j]);
    end = check_end(game_table, player);
    if (end == 1)
        return (1);
    else if (end == 2)
        return (2);
    else
        my_printf("\n");
    return (0);
}
