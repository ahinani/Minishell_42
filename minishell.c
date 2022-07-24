/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:36:35 by ahinani           #+#    #+#             */
/*   Updated: 2022/07/24 17:09:32 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int main(int ac, char **av, char **args)
{
    char    *cmd_buf;
    (void)av;
    g_.env =args;
    if (ac > 1)
        printf(RED"The program works without params!\n"WHITE);
    else
    {
        while (1)
        {
            cmd_buf = readline(BLUE"minshell $ "WHITE);
            add_history(cmd_buf);
            if (ft_strlen(cmd_buf) > 0)
            {
                if (!ft_strncmp(cmd_buf, "echo", 4))
                    ft_echo(splitted_echo(cmd_buf));
                else if (!ft_strncmp(cmd_buf, "env", 3))
                    ft_env(ft_split(cmd_buf, ' '));
                else if (!ft_strncmp(cmd_buf, "pwd", 3))
                    ft_pwd(ft_split(cmd_buf, ' '));
                else if(!ft_strncmp(cmd_buf, "exit", 4))
                    ft_exit(ft_split(cmd_buf, ' '));
            }
        }
    }
    return (0);
}