/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmds_shorten.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 07:44:30 by teppei            #+#    #+#             */
/*   Updated: 2021/06/18 07:45:29 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_dlst_replace(t_dlst *cmds, long cmd)
{
	t_dlst	*tmp;

	tmp = cmds->next->next;
	free(cmds->next);
	cmds->next = NULL;
	cmds->value = cmd;
	cmds->next = tmp;
	tmp->prev = cmds;
}

void	ps_cmds_shorten(t_dlst *cmds)
{
	t_dlst	*tmp;

	tmp = cmds->next;
	while (tmp->value != -1)
	{
		if (tmp->value == RA && tmp->next->value == RB)
			ps_dlst_replace(tmp, RR);
		if (tmp->value == RB && tmp->next->value == RA)
			ps_dlst_replace(tmp, RR);
		if (tmp->value == RRA && tmp->next->value == RRB)
			ps_dlst_replace(tmp, RR);
		if (tmp->value == RRB && tmp->next->value == RRA)
			ps_dlst_replace(tmp, RRR);
		if (tmp->value == SA && tmp->next->value == SB)
			ps_dlst_replace(tmp, SS);
		if (tmp->value == SB && tmp->next->value == SA)
			ps_dlst_replace(tmp, SS);
		tmp = tmp->next;
	}
}
