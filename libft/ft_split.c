/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:58:38 by pory              #+#    #+#             */
/*   Updated: 2022/04/25 16:36:36 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
#include <stdlib.h>

static int	nb_of_strings(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
		{
			i++;
		}
		if (s[i] != c && s[i])
		{	
			nb++;
		}
		while (s[i] != c && s[i])
		{
			i++;
		}
	}
	return (nb);
}

static char	*get_str(char const *s, char c, int start, int len)
{
	char	*str;
	int		j;

	j = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[start] && s[start] != c)
	{
		str[j] = s[start];
		j++;
		start++;
	}
	str[j] = '\0';
	return (str);
}

static char	**get_tab(char **tab, char const *s, int nbstrs, char c)
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
		while (str[i] == c && str[i])
		{
			i++;
			k++;
		}
		while (str[i] != c && str[i])
			i++;
		tab[j++] = get_str(s, c, (i - (i - k)), (i - k));
		k = i;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nbstrs;

	nbstrs = nb_of_strings(s, c);
	tab = malloc(sizeof(char *) * (nbstrs + 1));
	if (!tab)
		return (NULL);
	return (get_tab(tab, s, nbstrs, c));
}

/*int main(void)
{
    ft_split("kjhk", '\0');
}*/
