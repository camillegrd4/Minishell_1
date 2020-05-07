/*
** EPITECH PROJECT, 2020
** old
** File description:
** old_path
*/

#include "my.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int find_old_line(char **env)
{
    int i = 0;

    while (env) {
        if (my_strncmp(env[i], "OLDPWD=", 7) == 0)
            return i;
        i += 1;
    }
    return -1;
}

int find_pwd_line(char **env)
{
    int i = 0;

    while (env) {
        if (my_strncmp(env[i], "PWD=", 4) == 0)
            return i;
        i += 1;
    }
    return -1;
}

char *get_old_path(char **env)
{
    int i = 0;
    int pos_old = find_old_line(env);
    char *result = malloc(sizeof(char) * my_strlen(env[pos_old]));

    while (env[pos_old][i]) {
        result[i] = env[pos_old][i];
        i += 1;
    }
    result[i + 1] = '\0';
    return result;
}

int write_old_path(char **env)
{
    env[find_old_line(env)] = my_strdup("OLDPWD=");
    env[find_old_line(env)] = my_strcat(env[find_old_line(env)], env[find_pwd_line(env)]+4);
}

int write_new_path(char **env)
{
    char path[PATH_MAX];

    getcwd(path, sizeof(path));
    env[find_pwd_line(env)] = my_strdup("PWD=");
    env[find_pwd_line(env)] = my_strcat(env[find_pwd_line(env)], path);
}

int go_old(char **env)
{
    char *old_path = get_old_path(env)+7;

    go_path(old_path, env);
}