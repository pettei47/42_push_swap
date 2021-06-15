/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:45:12 by teppei            #+#    #+#             */
/*   Updated: 2021/06/15 22:58:20 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_swap(t_vid *a, t_vid *b)
{
	long	tmp_id;
	long	tmp_val;

	tmp_id = a->id;
	tmp_val = a->value;
	a->id = b->id;
	a->value = b->value;
	b->id = tmp_id;
	b->value = tmp_val;
}

long	ps_part_value(t_vid n[], long left, long right)
{
	long	i;
	long	j;
	long	pivot;

	i = left;
	j = right + 1;
	pivot = left;
	while (i < j)
	{
		while (i < j && n[++i].value < n[pivot].value)
			;
		while (j && n[pivot].value < n[--j].value)
			;
		if (i < j)
			ps_swap(&n[i], &n[j]);
	}
	ps_swap(&n[pivot], &n[j]);
	return (j);
}

long	ps_part_id(t_vid n[], long left, long right)
{
	long	i;
	long	j;
	long	pivot;

	i = left;
	j = right + 1;
	pivot = left;
	while (i < j)
	{
		while (n[++i].id < n[pivot].id)
			;
		while (n[pivot].id < n[--j].id)
			;
		if (i < j)
			ps_swap(&n[i], &n[j]);
	}
	ps_swap(&n[pivot], &n[j]);
	return (j);
}

void	ps_presort(t_vid n[], long left, long right, long flag)
{
	long	pivot;

	if (left < right)
	{
		if (flag == SORT_VAL)
			pivot = ps_part_value(n, left, right);
		if (flag == SORT_ID)
			pivot = ps_part_id(n, left, right);
		ps_presort(n, left, pivot - 1, flag);
		ps_presort(n, pivot + 1, right, flag);
	}
}
