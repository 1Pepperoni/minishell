/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:38:01 by pory              #+#    #+#             */
/*   Updated: 2023/03/10 23:33:50 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//les fonctions sont a modifier pour les processus enfants, if pid enfant etc

void	signal_ctrl_c(int sig)
{
	(void)sig;
	printf("\e[2K");
	printf("minishell> ");
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	signal_ctrl_backslash(int sig)
{
	(void)sig;
	printf("\e[2K");
	printf("minishell> ");
}

void	signal_handler(void)
{
	signal(SIGINT, signal_ctrl_c);
	signal(SIGQUIT, signal_ctrl_backslash);
}