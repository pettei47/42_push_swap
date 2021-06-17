/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:45:12 by teppei            #+#    #+#             */
/*   Updated: 2021/06/17 23:36:37 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_trade(t_vid *a, t_vid *b)
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
	int	i;
	int	j;
	int	pivot;

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
			ps_trade(&n[i], &n[j]);
	}
	ps_trade(&n[pivot], &n[j]);
	return (j);
}

long	ps_part_id(t_vid n[], long left, long right)
{
	int	i;
	int	j;
	int	pivot;

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
			ps_trade(&n[i], &n[j]);
	}
	ps_trade(&n[pivot], &n[j]);
	return (j);
}

void	ps_presort(t_vid n[], long left, long right, long flag)
{
	int	pivot;

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
