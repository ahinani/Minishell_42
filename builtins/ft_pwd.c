/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:35:24 by ahinani           #+#    #+#             */
/*   Updated: 2022/07/23 16:48:40 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_pwd(char **str)
{
    char    path[1024];

	str++;
	if (str[0])
	{
		if (str[0][0] == '-' && ((str[0][1] != '\0' && str[0][1] != '-')
			|| (str[0][1] == '-' && str[0][2] != '\0')))
		{
			printf(RED"minishell: pwd: %s: invalid option\n"WHITE, str[0]);
			return (1);
		}
	}
	if (getcwd(path, sizeof(path)))
		printf("%s\n", path);
	else
	{
		printf(RED"Error\n"WHITE);
		return (1);
	}
	return (0);
}
