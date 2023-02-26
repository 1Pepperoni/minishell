/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ory <ory@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:34:07 by pory              #+#    #+#             */
/*   Updated: 2023/02/24 16:56:10 by ory              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	how_many_spaces_add(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i] == '>' && str[i + 1] == '>')
			nb = nb + 2;
		else if (str[i] == '<' && str[i + 1] == '<')
			nb = nb + 2;
		else if (str[i] == '>')
			nb = nb + 2;
		else if (str[i] == '<')
			nb = nb + 2;
		i++;
	}
	return (nb);
}

int	check_unspaced_followed_pipe(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '|' && str[i + 1] == '|')
			return (1);
		i++;
	}
	return (0);
}

// int	check_spaced_redirections(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while(str[i])
// 	{
// 		if (str[i] == '>' && (str[i + 1] == ' ' || str[i + 1] == '\t') && str[i + 2] == '>') 
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	redirections_check(char *str)
// {
// 	if (check_unspaced_followed_pipe(str))
// 		return (1);
// }

char	*make_new_str(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * (how_many_spaces_add(str) + ft_strlen(str) + 1));
	while (str[i])
	{
		if (str[i] == '>' && str[i + 1] == '>')
		{
			new_str[j++] = ' ';
			new_str[j++] = '>';
			new_str[j++] = '>';
			new_str[j++] = ' ';
			i = i + 2;
			//j++;
		}
		if (str[i] == '<' && str[i + 1] == '<')
		{
			new_str[j++] = ' ';
			new_str[j++] = '<';
			new_str[j++] = '<';
			new_str[j++] = ' ';
			i = i + 2;
			//j++;
		}
		if (str[i] == '>')
		{
			new_str[j++] = ' ';
			new_str[j++] = '>';
			new_str[j++] = ' ';
			i++;
		}
		if (str[i] == '<')
		{
			new_str[j++] = ' ';
			new_str[j++] = '<';
			new_str[j++] = ' ';
			i++;
		}
		new_str[j] = str[i]; 
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

int	is_nb_pair(unsigned int	nb)
{
	if (nb % 2 == 1)
		return (0);
	else
		return (1);
}

void	check_impair_quotes(char *str)
{
	int	q_double;
	int	q_simple;
	int	i;

	q_double = 0;
	q_simple = 0;
	i = -1;
	while(str[++i])
	{
		if (str[i] == 39)
			q_simple++;
		else if (str[i] == '"')
			q_double++;
	}
	if (!(is_nb_pair(q_simple)))
	{
		printf("quotes error\n");
		exit (1);
	}
	if (!(is_nb_pair(q_double)))
	{
		printf("quotes error\n");
		exit (1);
	}
}

void	prompt(void)
{
	char	*input;
	char	*str;
	char	**tab;
	t_token_list	*token_list;
	int		i;
	t_token_list	*tmp;

	rl_initialize ();
	while ((input = readline("minishell> ")))
	{
		add_history(input);
		if (check_unspaced_followed_pipe(input))
		{
			free (input);
			exit (0);
		}
		//str = malloc(sizeof(char) * how_many_spaces_add(input));
		//printf("input = %s\n", input);
		check_impair_quotes(input);
		str = make_new_str(input);
		tab = ft_basic_split(str);
		i = 0;
		token_list = ft_token_lstnew(0, tab[i]);
		while(tab[++i])
		{
			tmp = ft_token_lstnew(0, tab[i]);
			ft_token_lstadd_back(&token_list, tmp);
			//printf("tab[%d] = %s\n", i, tab[i]);
		}
		while (token_list)
		{
			printf("--> %s\n", token_list->data);
			token_list = token_list->next;
		}
		printf("new = %s\n", str);
		free(input);
		free(str);
	}
}

int	main()
{
	prompt();
}