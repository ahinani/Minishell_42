/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:52:38 by ahinani           #+#    #+#             */
/*   Updated: 2022/07/24 17:07:47 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_exit(char **str)
{
	int	i;

	i = -1;
	if (!g_.pip)
		printf("exit\n");
	if(str[1])
	{	
		if (str[2])
		{
			printf(RED"minishell: exit: %s: too many arguments\n"WHITE, str[1]);
			exit(1);
		}
		if (str[1][0] == '-' || str[1][0] == '+')
			i++;
		while (str[1][++i])
		{
			if (str[1][i] < '0' || str[1][i] > '9')
			{
				printf(RED"minishell: exit: %s: numeric argument required\n"WHITE, str[1]);
				exit(1);
			}
		}
		exit(ft_atoi(str[1]));
	}
	exit(0);
	return (0);
}
