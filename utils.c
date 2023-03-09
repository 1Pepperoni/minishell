/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 05:09:58 by pory              #+#    #+#             */
/*   Updated: 2023/03/09 20:52:52 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_token_list	*ft_token_lstnew(t_token_type token_type, char *str)
{
	t_token_list	*new_element;

	new_element = malloc(sizeof(*new_element));
	if (!new_element)
		return (NULL);
	new_element->token = token_type;
	// new_element->data = ft_strjoin(new_element->data, str);
	new_element->data = str;
	new_element->previous = NULL;
	new_element->next = NULL;
	return (new_element);
}

void	ft_token_lstadd_back(t_token_list **lst, t_token_list *new)
{
	t_token_list	*tmp;

	if (*lst)
	{
		tmp = ft_token_lstlast(*lst);
		tmp->next = new;
		tmp->previous = tmp;
	}
	else
		(*lst) = new;
}

t_token_list	*ft_token_lstlast(t_token_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}