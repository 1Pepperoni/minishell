/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:15:46 by pory              #+#    #+#             */
/*   Updated: 2022/04/14 21:37:09 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	src[] = "bdsjkbfs";
	
	printf("%s\n", ft_strdup(src));
	printf("%s\n", strdup(src));
}*/
