/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:08:12 by pory              #+#    #+#             */
/*   Updated: 2022/04/14 18:59:58 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && str1[i] == str2[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}
/*#include <string.h>
int	main(void)
{
	char	s1[] = "abef";
	char	s2[] = "abeiiiiii";
	unsigned int n = 3;

	printf("%di \n", ft_strncmp(s1, s2, n));

	printf("%d", strncmp(s1, s2, n));
}*/

// int main(void)
// {
// 	printf("%d\n", strncmp("a", "b", 1));
// 	printf("%d\n", ft_strncmp("a", "b", 1));
// }
