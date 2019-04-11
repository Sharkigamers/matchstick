/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** main
*/

#include "my.h"

int bad_input(char **av)
{
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (av[1][i] > '9' || av[1][i] < '0')
            return (84);
    }
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] > '9' || av[2][i] < '0')
            return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 3) {
        write(2, "Missing argument. Please check rules.\n", 38);
        return (84);
    }
    if (ac > 3) {
        write(2, "Too much argument. Please check rules.\n", 39);
        return (84);
    }
    if (my_atoi(av[1]) <= 1 || my_atoi(av[1]) >= 100) {
        write(2, "Error with the size of the game table.\n", 39);
        return (84);
    }
    if (bad_input(av) == 84)
        return (84);
    return (matchstick(my_atoi(av[1]), my_atoi(av[2])));
}
