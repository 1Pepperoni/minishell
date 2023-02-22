/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 05:17:49 by pory              #+#    #+#             */
/*   Updated: 2023/02/22 08:41:42 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static int	nb_of_strings(char const *s)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while ((s[i] == ' ' || s[i] == '\t') && s[i])
		{
			i++;
		}
		if ((s[i] != ' ' && s[i] != '\t') && s[i])
		{	
			nb++;
		}
		while ((s[i] != ' ' && s[i] != '\t') && s[i])
		{
			i++;
		}
	}
	printf("nb = %d\n", nb);
	return (nb);
}

static char	*get_str(char const *s, int start, int len)
{
	char	*str;
	int		j;

	j = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[start] && (s[start] != ' ' && s[start] != '\t'))
	{
		str[j] = s[start];
		j++;
		start++;
	}
	str[j] = '\0';
	return (str);
}

static char	**get_tab(char **tab, char const *s, int nbstrs)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	str = (char *)s;
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (str[i] && j < nbstrs)
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
		{
			i++;
			k++;
		}
		while ((str[i] != ' ' && str[i] != '\t') && str[i])
			i++;
		tab[j++] = get_str(s, (i - (i - k)), (i - k));
		k = i;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_basic_split(char const *s)
{
	char	**tab;
	int		nbstrs;

	nbstrs = nb_of_strings(s);
	tab = malloc(sizeof(char *) * (nbstrs + 1));
	if (!tab)
		return (NULL);
	return (get_tab(tab, s, nbstrs));
}