/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_over_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 23:17:54 by teppei            #+#    #+#             */
/*   Updated: 2021/06/21 14:42:38 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_b_separate(t_dlst *a, t_dlst *b, t_ps *ps, long size)
{
	long	i;
	long	pivot;
	long	b_size;
	long	a_addsize;

	i = -1;
	b_size = size;
	a_addsize = 0;
	pivot = ps->awant + (size - 1) / 2;
	while (++i < size)
	{
		if (b->next->value - 1 > pivot && b_size-- && ++a_addsize)
			ps_push_addans(a, b, ps, PA);
		else
			ps_rotate_addans(b, ps, RB);
	}
}

void	ps_a_separate(t_dlst *a, t_dlst *b, t_ps *ps, long size)
{
	long	i;

	i = -1;
	while (++i < size)
		ps_push_addans(b, a, ps, PB);
}

long	ps_search_sep_size(t_dlst *a, t_ps *ps)
{
	long	size;
	long	max;
	t_dlst	*tmp;

	size = 0;
	max = -ARG_LIMIT - 10;
	tmp = a->next;
	while (max - ps->awant + 1 != size && tmp->value != 1)
	{
		size++;
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (size);
}

void	ps_a_half(t_dlst *a, t_dlst *b, t_ps *ps)
{
	int	i;
	int	b_size;

	i = -1;
	b_size = 0;
	while (++i < ps->size && b_size <= ps->size / 2)
	{
		if (a->next->value <= (ps->size / 2))
		{
			ps_push_addans(b, a, ps, PB);
			b_size++;
		}
		else
			ps_rotate_addans(a, ps, RA);
	}
}

void	ps_over_three(t_dlst *a, t_dlst *b, t_ps *ps)
{
	int	size;
	//int i;

	//i = 0;
	ps_a_half(a, b, ps);
	while (ps->awant <= ps->size)
	{
		size = -1;
		while (size == -1 || size > SORTSIZE)
		{
			size = ps_dlst_size(b);
			if (size > SORTSIZE)
				ps_b_separate(a, b, ps, size);
				//ps_print_dlst(a, "after sep b");
				//ps_print_dlst(b, "after sep b");
		}
		if (size)
			ps_under_three(b, ps, 1, 'b');
		size = ps_dlst_size(a);
		if (size <= SORTSIZE)
			ps_under_three(a, ps, 0, 'a');
		ps_push_btoa(a, b, ps);
		if (size > SORTSIZE)
			size = ps_search_sep_size(a, ps);
		//ps_print_dlst(a, "after btoa");
		//ps_print_dlst(b, "after btoa");
		//printf("sep_a size %d\n", size);
		//printf("ps->awant  %ld\n", ps->awant);
		if (size)
			ps_a_separate(a, b, ps, size);
		//ps_print_dlst(a, "after sep a");
		//ps_print_dlst(b, "after sep a");
		//if (i++ > 4)
		//	break;
	}
}
