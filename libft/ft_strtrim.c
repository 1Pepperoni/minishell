/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 02:02:51 by pory              #+#    #+#             */
/*   Updated: 2022/04/22 21:49:41 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
//#include <stdio.h>

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*result;

	if (!(s1) || !(set))
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	result = NULL;
	while (s1[i] && check_set(s1[i], set) == 1)
			i++;
	while (len > i && (check_set(s1[len - 1], set) == 1))
			len--;
	result = malloc(sizeof(char) * len - i + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, &s1[i], len - i + 1);
	return (result);
}

// int main()
// {
// 	char *s = "xcvALOURAvcx";
// 	char *set = "";
// 	char *strtrim;

// 	printf("Value before trime = %s\n", s);
// 	strtrim = ft_strtrim(s, set);
// 	printf("Value after trime = %s\n", strtrim);
// 	return (0);
// }
