/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:37:59 by teppei            #+#    #+#             */
/*   Updated: 2021/06/15 22:38:22 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_free_ps(t_dlst *a, t_dlst *b, t_ps *ps)
{
	if (a)
		ps_dlst_clear(a);
	if (b)
		ps_dlst_clear(b);
	if (ps)
	{
		ps_dlst_clear(ps->ans);
		free(ps);
	}
}
