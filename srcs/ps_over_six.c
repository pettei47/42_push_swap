/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_over_six.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 23:17:54 by teppei            #+#    #+#             */
/*   Updated: 2021/06/19 19:19:37 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_a_half(t_dlst *a, t_dlst *b, t_ps *ps)
{
	int	i;
	int	b_size;

	i = -1;
	b_size = 0;
	while (++i < ps->size && b_size < ps->size / 2)
	{
		if (a->next->value < (ps->size / 2))
		{
			pa_addans(b, a, ps, PB);
			b_size++;
		}
		else
			ra_addans(a, ps, RA);
	}
}

void	ps_over_six(t_dlst *a, t_dlst *b, t_ps *ps)
{
	int	size;

	ps_a_half(a, b, ps);
	while (ps->awant != ps->size)
	{
		b_settle_top(a, b, ps);
		size = -1;
		while (size == -1 || size > SORTSIZE)
		{
			size = dlst_size(b);
			b_quick_sort(a, b, ps, size);
		}
		if (size)
			allsort(a, b, ps, size);
		size = -1;
		while (size == -1 ||(0 < size && size <= SORTSIZE))
		{
			size = search_a_size(a, ps)
			allsort(a, b, ps, size);
		}
		if (size)
			a_quick_sort(a, b, ps, size);
	}
}
