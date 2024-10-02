/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:16:16 by ebennamr          #+#    #+#             */
/*   Updated: 2022/10/23 14:44:10 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		size;

	if (!lst)
		return (0);
	size = 1;
	temp = lst;
	while (temp->next != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}
