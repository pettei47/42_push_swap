/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmds_shorten.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:21:28 by teppei            #+#    #+#             */
/*   Updated: 2021/06/21 14:21:30 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlst	*ps_dlst_delone(t_dlst *dlst)
{
	t_dlst	*prev1;
	t_dlst	*next1;

	prev1 = dlst->prev;
	next1 = dlst->next;
	free(dlst);
	prev1->next = next1;
	next1->prev = prev1;
	return (next1);
}

void	ps_cmds_remove_redo(t_dlst *cmds)
{
	t_dlst	*tmp;
	bool	delete;

	tmp = cmds->next;
	while (tmp->value != -1)
	{
		delete = false;
		if (tmp->value == PA && tmp->next->value == PB)
			delete = true;
		if (tmp->value == PB && tmp->next->value == PA)
			delete = true;
		if (del)
		{
			tmp = ps_dlst_delone(tmp);
			tmp = ps_dlst_delone(tmp);
			tmp = tmp->prev->prev;
		}
		tmp = tmp->next;
	}
}

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
	ps_cmds_remove_redo(cmds);
}
