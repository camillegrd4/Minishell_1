/*
** EPITECH PROJECT, 2020
** shell
** File description:
** shell
*/

#include "my.h"
#include "get_next_line.h"

shell_t *init_shell(shell_t *shell, char **env)
{
    shell->env = env;
    shell->path_line = get_path_line(env);
    shell->path_parsed = path_to_word_array(shell->path_line);
    return shell;
}

int exec_command(shell_t *shell)
{
    char *cmd = NULL;

    if (shell == NULL || check_command(shell->buf_array) == 84)
        return 84;
    if (check_builtin(shell) == 1){
        cmd = my_strcat("/bin/", shell->buf_array[0]);
        execve(cmd, shell->buf_array, shell->env);
        //not_found(shell->buf_array[0]);
    }
    return 0;
}

int shell(char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));
    shell = init_shell(shell, env);
    
    while (1) {
        my_putstr("$>");
        shell->buf_array = my_str_to_word_array(get_next_line(0));
        exec_command(shell);
    }
    return 0;
}