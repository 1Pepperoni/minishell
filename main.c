/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:34:07 by pory              #+#    #+#             */
/*   Updated: 2023/02/20 20:52:10 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(void)
{
	rl_initialize();
	char *input;

    while ((input = readline("minishell> ")))
	{
        add_history(input);
        printf("%s\n", input);
        free(input);
    }
}

int	main()
{
	prompt();
}