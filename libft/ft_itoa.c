/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:52:14 by pory              #+#    #+#             */
/*   Updated: 2022/04/25 18:16:59 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
//#include <stdio.h>

static int	len(int nb)
{
	int	len;
	int	a;

	a = 0;
	if (nb == -2147483648)
	{
		a = 1;
		nb = 2147483647;
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		a = 1;
	}
	len = 0;
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	len++;
	return (len + a);
}

static char	*ft_putnbr(int n, long end, char *str)
{
	long	lenght;
	long	nb;

	lenght = end - 1;
	nb = n;
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * (-1);
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[lenght] = (nb % 10) + '0';
		lenght--;
		nb = nb / 10;
	}
	str[end] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	end;

	end = len(n);
	str = malloc(sizeof(char) * (end + 1));
	if (!str)
		return (NULL);
	return (ft_putnbr(n, end, str));
}

/*int	main(void)
{
	printf("%s", ft_itoa(65421));
}*/
