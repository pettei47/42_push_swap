/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dlst_addback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:14:22 by teppei            #+#    #+#             */
/*   Updated: 2021/06/18 07:28:30 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_dlst_addback(t_ps *ps, t_dlst *dlst, long value)
{
	t_dlst	*new;
	t_dlst	*ptmp;

	if (!(new = (t_dlst *)malloc(sizeof(t_dlst))))
		exit(ps_puterror(ps->a, ps->b, ps, 1));
	new->value = value;
	ptmp = dlst->prev;
	ptmp->next = new;
	new->next = dlst;
	dlst->prev = new;
	new->prev = ptmp;
}
