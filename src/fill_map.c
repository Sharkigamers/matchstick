/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** fill the table
*/

#include "my.h"

void take_stick(char **game_table, int line, int matches)
{
    int j;
    int delete_stick = 0;

    for (j = 0; game_table[line][j] != '\0'; j++);
    for (j -= 2; j > 0; j--) {
        if (delete_stick < matches && game_table[line][j] == '|') {
            game_table[line][j] = ' ';
            delete_stick++;
        }
    }
}

int fill_line(char *buffer, int *line, char **game_table, int nb_line)
{
    my_printf("Line: ");
    buffer = NULL;
    if ((buffer = get_next_line(0)) == NULL)
        return (84);
    *line = my_atoi(buffer);
    if (check_line(game_table, *line, buffer, nb_line) == 1) {
        free(buffer);
        return (1);
    }
    free(buffer);
    buffer = NULL;
    return (0);
}

int fill_matches(char *buffer, int *matches, int max_choice)
{
    my_printf("Matches: ");
    buffer = NULL;
    if ((buffer = get_next_line(0)) == NULL)
        return (84);
    *matches = my_atoi(buffer);
    if (check_matches(max_choice, buffer, *matches) == 1) {
        free(buffer);
        return (1);
    }
    free(buffer);
    return (0);
}

int turn_player(char **game_table, int nb_line, int max_choice)
{
    char *buffer = NULL;
    int line = 0;
    int matches = 0;
    int gest = 0;

    if ((gest = fill_line(buffer, &line, game_table, nb_line)) == 1)
        return (1);
    if (gest == 84)
        return (84);
    if ((gest = fill_matches(buffer, &matches, max_choice)) == 1)
        return (1);
    if (gest == 84)
        return (84);
    if (check_enought_matches(game_table, matches, line) == 1)
        return (1);
    my_printf("Player removed %d match(es) from line %d\n", matches, line);
    take_stick(game_table, line, matches);
    return (0);
}
