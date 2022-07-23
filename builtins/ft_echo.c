/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:09:31 by ahinani           #+#    #+#             */
/*   Updated: 2022/07/20 19:16:36 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int  nb_args(char **args)
{
    int i;

    i = 0;
    while (args[i])
        i++;
    return (i);
}

int         ft_echo(char **args)
{
    int i;
    int n_opt;

    i = 1; //bach ybda mn dakchi li mura l echo
    n_opt = 0; //hna ghaykun ba9i mal9ach l flag   
    if (nb_args(args) > 1)
    {
        while (args[i] && !ft_strncmp(args[i], "-n", 2))
        {
            n_opt = 1; //hna l9a l flag -n
            i++;
        }
        while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1] && args[i][0])
				write(1, " ", 1);
			i++;
		}
    }
    if (n_opt == 0) //ila makan hta chi args ghay returni \n
        write(1, "\n", 1);
    return (0);
}

char    **splitted_echo(char *str)
{
    char **spl;
    spl = ft_split(str, ' ');
    return (spl);
}