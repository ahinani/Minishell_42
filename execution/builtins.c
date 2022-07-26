/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:29:42 by ahinani           #+#    #+#             */
/*   Updated: 2022/07/23 17:23:07 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int is_builtin(char *cmd)
{
    if (ft_strcmp(cmd, "echo") == 0)
        return (1);
    else if (ft_strcmp(cmd, "env") == 0)
        return (1);
    else if (ft_strcmp(cmd, "pwd") == 0)
        return (1);
    else if (ft_strcmp(cmd, "exit") == 0)
        return (1);
    return (0);
}

int exec_builtin(char **args)
{
    int res;

    res = 0;
    if (ft_strcmp(args[0], "echo") == 0)
        res = ft_echo(args);
    else if (ft_strcmp(args[0], "env") == 0)
        res = ft_env(args);
    else if (ft_strcmp(args[0], "pwd") == 0)
        res = ft_pwd(args);
    else if (ft_strcmp(args[0], "exit") == 0)
        res = ft_exit(args);
    return(res);
}