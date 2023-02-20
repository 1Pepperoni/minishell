/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:45:34 by pory              #+#    #+#             */
/*   Updated: 2022/04/14 21:35:58 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(sizeof(char) * (count * size));
	if (s == NULL)
		return (NULL);
	while (count < 4294967295 && size < 4294967295)
		return (ft_memset(s, '\0', count * size));
	return (NULL);
	free (s);
}
