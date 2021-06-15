/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:05:57 by teppei            #+#    #+#             */
/*   Updated: 2021/06/16 00:06:17 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

bool	ps_sorted(t_dlst *a)
{
	t_dlst	*dl;

	dl = a;
	while (dl->next->value != -1)
	{
		if (dl->value > dl->next->value)
			return (false);
		dl = dl->next;
	}
	printf("already sorted\n");
	return (true);
}
