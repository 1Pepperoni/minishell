/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 03:46:02 by pory              #+#    #+#             */
/*   Updated: 2022/03/30 06:09:34 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{	
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	if (dstsize < ft_strlen(dst))
	{
		while (src[j])
			j++;
		return (dstsize + j);
	}
	while (dstsize > 0 && i < dstsize - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	while (src[j++])
		i++;
	return (i);
}
