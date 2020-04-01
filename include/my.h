/*
** EPITECH PROJECT, 2020
** my
** File description:
** main
*/

#include <stdarg.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#ifndef MY_H_
#define MY_H_

typedef struct shell
{
    char **env;
    char **path;
    pid_t pid;
}shell_t;

int my_putstr(char *str);

void my_pid(shell_t *control, int a, char **env);

char *my_strcat(char *dest, char *src);

char *my_strstr(char *str, char *to_find);

void my_putchar(char c);

int my_put_nbr(int nb);

int my_strlen(char *str);

char *my_revstr(char *str);

char **my_str_to_word_array(char *str);

int shell(char **env);

shell_t *init_shell(shell_t *shell, char **env);

#endif /* !MY_H_ */
