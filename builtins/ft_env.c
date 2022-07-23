/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:02:43 by ahinani           #+#    #+#             */
/*   Updated: 2022/07/23 12:56:41 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int     ft_env(char **str)
{
    int i;
    if (str[1])
    {
        printf(RED"minishell: env: %s No such file or directory\n"WHITE, str[1]);
        return (1);
    }
    i = 0;
    if (!g_.env)
        return (1);
    while (g_.env[i])
    {
        if (ft_strchr(g_.env[i], '='))
            printf("%s\n", g_.env[i]);
        i++;
    }
    return (0);
}