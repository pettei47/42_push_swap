/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dlst_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:08:37 by teppei            #+#    #+#             */
/*   Updated: 2021/06/20 15:13:19 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

long	ps_dlst_size(t_dlst *b)
{
	long	size;
	t_dlst	*tmp;

	size = 0;
	tmp = b->next;
	while (tmp->value != -1)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
