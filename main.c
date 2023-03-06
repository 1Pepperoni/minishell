/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:34:07 by pory              #+#    #+#             */
/*   Updated: 2023/03/06 21:58:14 by pory             ###   ########.fr       */
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
		if (str[i] == '>')
			nb = nb + 2;
		else if (str[i] == '<')
			nb = nb + 2;
		else if (str[i] == '|')
			nb = nb + 2;
		else if (str[i] == '$' && str[i + 1] == '?')
			nb = nb + 2;
		else if (str[i] == '$')
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

char	*make_new_str(char *str)
{
	char	*new_str;
	int		i;
	int		j;
	int		flag_quote_simple;
	int		flag_quote_double;

	i = 0;
	j = 0;
	flag_quote_simple = 0;
	flag_quote_double = 0;
	new_str = malloc(sizeof(char) * (how_many_spaces_add(str) + ft_strlen(str) + 1));
	while (str[i])
	{
		while (str[i])
		{
			if (str[i] == 39 && flag_quote_double == 0 && flag_quote_simple == 0)
				flag_quote_simple = 1;
			else if (str[i] == '"' && flag_quote_simple == 0 && flag_quote_double == 0)
				flag_quote_double = 1;
			else if (str[i] == 39 && flag_quote_simple == 1)
				flag_quote_simple = 0;
			else if (str[i] == '"' && flag_quote_double == 1)
				flag_quote_double = 0;
			if (str[i] == '>' && str[i + 1] == '>' && flag_quote_double == 0 && flag_quote_simple == 0)
			{
				new_str[j++] = ' ';
				new_str[j++] = '>';
				new_str[j++] = '>';
				new_str[j++] = ' ';
				i = i + 2;
				break ;
			}
			if (str[i] == '<' && str[i + 1] == '<' && flag_quote_double == 0 && flag_quote_simple == 0)
			{
				new_str[j++] = ' ';
				new_str[j++] = '<';
				new_str[j++] = '<';
				new_str[j++] = ' ';
				i = i + 2;
				break ;
			}
			if (str[i] == '<' && str[i + 1] == '>' && flag_quote_double == 0 && flag_quote_simple == 0)
			{
				new_str[j++] = ' ';
				new_str[j++] = '<';
				new_str[j++] = '>';
				new_str[j++] = ' ';
				i = i + 2;
				break ;
			}
			if (str[i] == '>' && flag_quote_double == 0 && flag_quote_simple == 0)
			{
				new_str[j++] = ' ';
				new_str[j++] = '>';
				new_str[j++] = ' ';
				i++;
				break ;
			}
			if (str[i] == '<' && flag_quote_double == 0 && flag_quote_simple == 0)
			{
				new_str[j++] = ' ';
				new_str[j++] = '<';
				new_str[j++] = ' ';
				i++;
				break ;
			}
			if (str[i] == '|' && flag_quote_double == 0 && flag_quote_simple == 0)
			{
				new_str[j++] = ' ';
				new_str[j++] = '|';
				new_str[j++] = ' ';
				i++;
				break ;
			}
			new_str[j] = str[i]; 
			i++;
			j++;
			break ;
		}
	}
	if (flag_quote_double == 1 || flag_quote_simple == 1)
	{
		free (new_str);
		return (NULL);
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

// int	check_impair_quotes(char *str)
// {
// 	int	q_double;
// 	int	q_simple;
// 	int	i;

// 	q_double = 0;
// 	q_simple = 0;
// 	i = -1;
// 	while(str[++i])
// 	{
// 		if (str[i] == 39)
// 			q_simple++;
// 		else if (str[i] == '"')
// 			q_double++;
// 	}
// 	if (!(is_nb_pair(q_simple)))
// 	{
// 		printf("minishell: syntax error near unexpected token `''\n");
// 		return (1);
// 		//system("leaks minishell");
// 		//exit (1);
// 	}
// 	if (!(is_nb_pair(q_double)))
// 	{
// 		printf("minishell: syntax error near unexpected token `%c'\n", '"');
// 		return (1);
// 		//system("leaks minishell");
// 		//exit (1);
// 	}
// 	return (0);
// }

void deleteTokenList(t_token_list *head) {
    t_token_list *current = head;
    t_token_list *next;

    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}

void	delete_list(t_token_list *token_list)
{
	t_token_list *tmp;

	tmp = token_list;
	while (token_list)
	{
		tmp = token_list->next;
		free (token_list);
		token_list = tmp;
	}
}

void	tokenizer(t_token_list *token_list)
{
	t_token_list	*tmp;

	tmp = token_list;
	while(tmp)
	{
		tmp->token = TOKEN_STRING;
		if (ft_strcmp(tmp->data, ">") == 0)
			tmp->token = TOKEN_SIMPLE_OUTPUT_REDIRECTION;
		else if (ft_strcmp(tmp->data, "<") == 0)
			tmp->token = TOKEN_SIMPLE_INPUT_REDIRECTION;
		else if (ft_strcmp(tmp->data, ">>") == 0)
			tmp->token = TOKEN_DOUBLE_OUTPUT_REDIRECTION;
		else if (ft_strcmp(tmp->data, "<<") == 0)
			tmp->token = TOKEN_DOUBLE_OUTPUT_REDIRECTION;
		else if (ft_strcmp(tmp->data, "|") == 0)
			tmp->token = TOKEN_PIPE;
		tmp = tmp->next;
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

	t_token_list	*tmp_for_print;

	rl_initialize ();
	while ((input = readline("minishell> ")))
	{
		add_history(input);
		if (check_unspaced_followed_pipe(input))
		{
			free (input);
			printf("minishell: syntax error near unexpected token `|'\n");
			continue ;
			//system("leaks minishell");
			//exit (0);
		}
		str = make_new_str(input);
		if (str == NULL)
		{
			printf("minishell: quotes error\n");
			continue ;
		}
		tab = ft_basic_split(str);
		i = 0;
		token_list = ft_token_lstnew(0, tab[i]);
		while(tab[++i])
		{
			tmp = ft_token_lstnew(0, tab[i]);
			ft_token_lstadd_back(&token_list, tmp);
			//printf("tab[%d] = %s\n", i, tab[i]);
		}
		tokenizer(token_list);
		if (check_unexpected_token(token_list))
			continue ;

		tmp_for_print = token_list;
		while (tmp_for_print)
		{
			printf("--> %s      token = %d\n", tmp_for_print->data, tmp_for_print->token);
			tmp_for_print = tmp_for_print->next;
		}
		
		printf("new = %s\n", str);
		free(input);
		free(str);
		//delete_list(token_list);
		//system("leaks minishell");
		//exit (0);
	}
}

int	main()
{
	prompt();
	system("leaks minishell");
}