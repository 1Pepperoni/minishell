/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 05:40:17 by pory              #+#    #+#             */
/*   Updated: 2022/04/07 03:25:37 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{	
	size_t	i;
	size_t	j;
	char	*s1;
	char	*s2;

	s1 = (char *)haystack;
	s2 = (char *)needle;
	i = 0;
	if (s2[0] == '\0')
		return (&s1[i]);
	while (s1[i] && i < len)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (i + j < len && s1[i + j] == s2[j])
			{
				j++;
				if (!(s2[j]))
					return (&s1[i]);
			}
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	printf("%s\n", ft_strnstr("aaabcabcd", "cd", 9));
	printf("%s\n", strnstr("aaabcabcd", "cd", 9));
}*/