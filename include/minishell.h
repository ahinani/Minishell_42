/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:06:04 by ahinani           #+#    #+#             */
/*   Updated: 2022/07/23 11:21:42 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define WHITE "\033[0;37m"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

typedef enum e_token
{
    WHITE_SPACE = ' ',
    NEW_LINE = '\n',
    QUOTE = '\'',
    DOUBLE_QUOTE = '\"',
    ESCAPE = '\\',
    ENV = '$',
    PIPE = '|',
    REDIR_IN = '>',
    REDIR_OUT = '<',  
}   s_token;

typedef struct s_data
{
	char		*command[8];
	char		*input;
	char		*file;
	int			cmd;
	int			pip;
	char		**sp_cmd;
	char		**env;
	char		*clr_cmd;
	int			fd_stdin;
	int			fd_stdout;
	int			state;
	int			sig;
	pid_t		pid_ch;
	int			pipefd[2];
}               t_data;

t_data	g_;

//builtins
int         ft_echo(char **args);
char    	**splitted_echo(char *str);
int     	ft_env(char **str);

//execution
int         is_builtin(char *cmd);
int         exec_builtin(char **args);
#endif
