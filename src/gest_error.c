/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** gest error
*/

#include "my.h"

int check_line(char **game_table, int line, char *buffer, int nb_line)
{
    int sigpipe = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if ((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '\n') {
            my_printf("Error: invalid input (positive number expected)\n");
            return (1);
        }
    }
    if (line < 1 || line > nb_line) {
        my_printf("Error: this line is out of range\n");
        return (1);
    }
    for (int j = 0; game_table[line][j] != '\0'; j++) {
        if (game_table[line][j] == '|')
            sigpipe++;
    }
    if (sigpipe > 0)
        return (0);
    else
        return (1);
}

int check_enought_matches(char **game_table, int matches, int line)
{
    int sigpipe = 0;

    for (int j = 0; game_table[line][j] != '\0'; j++) {
        if (game_table[line][j] == '|')
            sigpipe++;
    }
    if (matches > sigpipe) {
        my_printf("Error: not enough matches on this line\n");
        return (1);
    }
    return (0);
}

int check_matches(int max_choice, char *buffer, int matches)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if ((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '\n') {
            my_printf("Error: invalid input (positive number expected)\n");
            return (1);
        }
    }
    if (matches == 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (1);
    }
    if (matches > max_choice) {
        my_printf("Error: you cannot remove more than %d", max_choice);
        my_printf(" matches per turn\n");
        return (1);
    }
    return (0);
}
