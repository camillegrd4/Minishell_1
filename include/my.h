/*
** EPITECH PROJECT, 2020
** my
** File description:
** main
*/

#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#ifndef MY_H_
#define MY_H_

typedef struct shell
{
    char **env;
    char *path_line;
    char **path_parsed;
    char *buf;
    char **buf_array;
    int coumpt;
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

char *my_strcat(char *str, char *buff);

char **my_str_to_word_array(char *str);

int count_path(char *line);

int shell(char **env);

shell_t *init_shell(shell_t *shell, char **env);

int check_args(int ac, char **env);

int my_strcmp(char *s1, char *s2);

int my_strncmp(char *s1, char *s2, int n);

int find_path_line(char **env);

char *get_path_line(char **env);

char **path_to_word_array(char *path_line);

char *my_strndup(char *src, int n);

int *my_strncpy(char *dest, char *src, int n);

char *check_command(void);

void not_found(char *cmd);

int check_builtin(shell_t *shell);

void not_found(char *cmd);

char *hanled_exec_path(char *path_parsed, char *entry);

int search_in_path(shell_t *shell);

int exec_command(shell_t *shell);

#endif /* !MY_H_ */
