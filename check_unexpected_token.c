/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unexpected_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:59:13 by pory              #+#    #+#             */
/*   Updated: 2023/03/09 20:52:36 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_error_in_lst(t_token_list *token_list)
{
	t_token_list *tmp;

	tmp = token_list;
	if (tmp->token >= 5 && tmp->next->token >= 5)
	{
		//printf("minishell: syntax error unexpected token\n");
		return (1);
	}
	else
		return (0);
}

int	check_if_last_token_is_pipe_or_redir(t_token_list *token_list)
{
	t_token_list	*last_token;

	last_token = token_list;
	//printf("last = %s\n", last_token->data);
	while (last_token->next)
		last_token = last_token->next;
	printf("last = %d\n", last_token->token);
	if (last_token->token >= 5)
		return (1);
	return (0);
}

int	check_unexpected_token(t_token_list *token_list)
{
	t_token_list	*tmp_lst;

	tmp_lst = token_list;
	if (check_if_last_token_is_pipe_or_redir(tmp_lst))
		return (1);
	tmp_lst = token_list;
	while (tmp_lst)
	{
		if (token_error_in_lst(tmp_lst))
			return (1);
		tmp_lst = tmp_lst->next;
	}
	return (0);
}