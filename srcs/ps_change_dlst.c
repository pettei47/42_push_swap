/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_change_dlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 22:48:24 by teppei            #+#    #+#             */
/*   Updated: 2021/06/17 23:15:09 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

long	ps_backtrack(long cmd)
{
	if (cmd == PA)
		return (PB);
	if (cmd == PB)
		return (PA);
	if (cmd == RA)
		return (RRA);
	if (cmd == RB)
		return (RRB);
	if (cmd == RR)
		return (RRR);
	if (cmd == RRA)
		return (RA);
	if (cmd == RRB)
		return (RB);
	if (cmd == RRR)
		return (RR);
	return (cmd);
}

bool	ps_change_dlst(t_dlst *a, t_dlst *b, long cmd, bool exec)
{
	if (!exec)
		cmd = ps_backtrack(cmd);
	if (cmd == SA)
		return (ps_swap(a));
	if (cmd == SB)
		return (ps_swap(b));
	if (cmd == SS)
		return (ps_ss(a, b));
	if (cmd == PA)
		return (ps_push(a, b));
	if (cmd == PB)
		return (ps_push(b, a));
	if (cmd == RA)
		return (ps_rotate(a));
	if (cmd == RB)
		return (ps_rotate(b));
	if (cmd == RR)
		return (ps_rr(a, b));
	if (cmd == RRA)
		return (ps_reverse_rotate(a));
	if (cmd == RRB)
		return (ps_reverse_rotate(b));
	if (cmd == RRR)
		return (ps_rrr(a, b));
	return (true);
}
