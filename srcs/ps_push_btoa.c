/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_btoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:25:17 by teppei            #+#    #+#             */
/*   Updated: 2021/06/21 14:57:44 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_rotate_awant(t_dlst *a, t_ps *ps)
{
	while (a->next->value == ps->awant)
	{
		ps_rotate_addans(a, ps, RA);
		ps->awant++;
	}
}

void	ps_push_btoa(t_dlst *a, t_dlst *b, t_ps *ps)
{
	int		i;
	t_dlst	*tmp;

	tmp = b->next;
	i = 0;
	while (tmp->value != -1)
	{
		ps_push_addans(a, b, ps, PA);
		tmp = tmp->next;
	}
	if (!ps_sorted(a, 0))
		ps_rotate_awant(a, ps);
}
