/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pory <pory@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:40:39 by pory              #+#    #+#             */
/*   Updated: 2022/04/25 15:38:29 by pory             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
//#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = malloc(sizeof(*new_element));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}

/*int main()
{
	t_list *a;
	t_list *c;
	t_list *t;
	int *b;
	int *z;
	int *y;
	
	int x = 10;
	int k = 8;
	int p = 150;
	b = &x;
	z = &k;
	y = &p;
	
	a = ft_lstnew(b);
	c = ft_lstnew(z);
	//t = ft_lstnew(y);
	
	a->next = c;
	//a->next->next = t;	

	printf("%d\n", *(int *)a->content);
	if (a->next)
		printf("%d\n", *(int *)a->next->content);
	
	//printf("%d\n", *(int *)a->next->next->content);

}*/