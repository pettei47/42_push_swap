/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_set_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:12:30 by teppei            #+#    #+#             */
/*   Updated: 2021/06/15 23:21:04 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlst	*ps_set_a(t_ps *ps)
{
	t_dlst	*dlst;
	long	i;

	dlst = ps_init_dlst(ps);
	i = -1;
	while (++i < ps->size)
		ps_dlst_addback(ps, dlst, ps->n[i].value);
	return (dlst);
}
