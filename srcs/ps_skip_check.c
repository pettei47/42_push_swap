/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_skip_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 22:38:58 by teppei            #+#    #+#             */
/*   Updated: 2021/06/17 22:39:48 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

bool	ps_skip_check(long command, t_sort *t)
{
	if (command == SA && (t->pre == SA || t->pre == SB || t->pre == SS))
		return (true);
	if (command == SB && (t->pre == SA || t->pre == SB || t->pre == SS))
		return (true);
	if (command == SS && (t->pre == SA || t->pre == SB || t->pre == SS))
		return (true);
	if (command == PA && (t->pre == PB))
		return (true);
	if (command == PB && (t->pre == PA))
		return (true);
	if (command == RA && (t->pre == RRA || t->pre == RRR))
		return (true);
	if (command == RB && (t->pre == RRB || t->pre == RRR))
		return (true);
	if (command == RR && (t->pre == RRA || t->pre == RRB || t->pre == RRR))
		return (true);
	if (command == RRA && (t->pre == RA || t->pre == RR))
		return (true);
	if (command == RRB && (t->pre == RB || t->pre == RR))
		return (true);
	if (command == RRR && (t->pre == RA || t->pre == RB || t->pre == RR))
		return (true);
	return (false);
}
