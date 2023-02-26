/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:32:40 by pory              #+#    #+#             */
/*   Updated: 2023/02/26 21:10:59 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef enum s_token_type
{
	TOKEN_COMMAND,
	TOKEN_COMMAND_OPTION,
	TOKEN_STRING,
	TOKEN_SIMPLE_INPUT_REDIRECTION,
	TOKEN_SIMPLE_OUTPUT_REDIRECTION,
	TOKEN_DOUBLE_INPUT_REDIRECTION,
	TOKEN_DOUBLE_OUTPUT_REDIRECTION,
	TOKEN_ENV_VARIABLES,
	TOKEN_LAST_OUTPUT_STATUS,
	TOKEN_PIPE,
}				t_token_type;

typedef struct s_token_list
{
	t_token_type		token;
	char				*data;
	struct s_token_list	*previous;
	struct s_token_list	*next;
}					t_token_list;

// typedef struct s_token_lst_elem
// {
// 	t_token_type		token;
// 	char				*data;
// 	struct s_token_lst_elem	*previous;
// 	struct s_token_lst_elem	*next;
// }					t_token_lst_elem;

t_token_list	*ft_token_lstnew(t_token_type token_type, char *str);
void			ft_token_lstadd_back(t_token_list **lst, t_token_list *new);
t_token_list	*ft_token_lstlast(t_token_list *lst);

void	check_unexpected_token(t_token_list *token_list);
int		unexpected_token1(t_token_list *token_list);
int		unexpected_token2(t_token_list *token_list);

#endif