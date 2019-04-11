/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get next line of a file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void first_chara(int fd, char *chara)
{
    static char *save_res = NULL;
    static int len = 0;
    char *res = malloc(10 + 1);

    if (len == 0) {
        len = read(fd, res, 10);
        save_res = res;
    }
    if (save_res[1] == '\0') {
        *chara = save_res[0];
        save_res++;
        len--;
        return;
    }
    if (len == 0)
        return;
    *chara = save_res[0];
    save_res++;
    len--;
}

char *get_next_line(int fd)
{
    char *res = malloc(10);
    char chara = 0;
    int i = 0;

    if (res == NULL)
        return NULL;
    first_chara(fd, &chara);
    if (fd == -1 || res == NULL || (res[0] == '\0' && chara == 0))
        return NULL;
    for (; chara != '\n' && chara != '\0'; i++) {
        res[i] = chara;
        first_chara(fd, &chara);
    }
    res[i] = '\0';
    return (res);
}
