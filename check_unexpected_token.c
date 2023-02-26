/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unexpected_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:59:13 by pory              #+#    #+#             */
/*   Updated: 2023/02/26 23:06:47 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// que faire dans le cas echo "hello" <> test | cat test

int	ft_is_same_str(char *str1, char *str2)
{
	int	len1;
	int	len2;
	int	i;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 != len2)
		return (0);
	i = 0;
	while(i < len1)
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

int	unexpected_token_1(t_token_list *token_list)
{
	int	i;
	char	*str;
	char *tmp;
	t_token_list *tmp_list;

	tmp = NULL;
	i = 0;
	int j = 0;
	tmp_list = token_list;
	printf("--> %d\n", ft_strncmp(token_list->data, ">", 2));
	if (ft_is_same_str(tmp_list->data, ">") && ft_is_same_str(tmp_list->next->data, "<"))
		{
			printf("bbbbbbb\n");
			tmp_list = tmp_list->next;
			while (ft_is_same_str(tmp_list->next->data, "<") && ++i)
			{
				printf("i1 = %d\n", i);
				tmp_list = tmp_list->next;
			}
			while (j++ < i && j <= 3)
			{
				printf("i = %d\n", i);
				if (str == NULL)
					str = ft_strjoin(str, "<");
				else
				{
					tmp = ft_strdup(str);
					free(str);
					str = ft_strjoin(tmp, "<");
					free(tmp);
				}
				printf("str = %s\n", str);
			}
			printf("----minishell: syntax error near unexpected token `%s'\n", str);
			free (str);
			return (1) ;
		}
	return (0);
}

int	unexpected_token_2(t_token_list *token_list)
{
	char	*str;

	if (ft_is_same_str(token_list->data, ">") && ft_is_same_str(token_list->next->data, "<") && ft_is_same_str(token_list->next->next->data, ">"))
	{
		str = ft_strjoin(str, "<>");
		printf("minishell: syntax error near unexpected token `%s'\n", str);
		free (str);
		return (1) ;
	}
	if (ft_is_same_str(token_list->data, "<") && ft_is_same_str(token_list->next->data, ">"))
	{
		str = ft_strjoin(str, "<>");
		printf("minishell: syntax error near unexpected token `%s'\n", str);
		free (str);
		return (1) ;
	}
	if (ft_is_same_str(token_list->data, ">>") && ft_is_same_str(token_list->next->data, "<") && ft_is_same_str(token_list->next->next->data, ">"))
	{
		str = ft_strjoin(str, "<>");
		printf("minishell: syntax error near unexpected token `%s'\n", str);
		free (str);
		return (1) ;
	}
	if (ft_is_same_str(token_list->data, "<<") && ft_is_same_str(token_list->next->data, "<") && ft_is_same_str(token_list->next->next->data, ">"))
	{
		str = ft_strjoin(str, "<>");
		printf("minishell: syntax error near unexpected token `%s'\n", str);
		free (str);
		return (1) ;
	}
	return (0);
}

void	check_unexpected_token(t_token_list *token_list)
{
	// int	i;
	// char	*str;
	// char *tmp = NULL;
	t_token_list	*tmp_lst;

	// i = 0;
	// int j = 0;
	tmp_lst = token_list;
	while (tmp_lst)
	{
		if (unexpected_token_1(tmp_lst))
			break ;
		if (unexpected_token_2(tmp_lst))
			break ;
		
		tmp_lst = tmp_lst->next;
	}
}