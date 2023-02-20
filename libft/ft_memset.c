/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:46:36 by pory              #+#    #+#             */
/*   Updated: 2022/04/07 11:04:47 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
#include "libft.h"
//#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*str;

	str = (char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	return (str);
}

/*int main()
{
    char c[] = "ALOURy7t7b";

    ft_memset(c, 60, 2);
    printf("la chaine de charac est = %s\n", c);
}*/
