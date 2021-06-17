/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_less_seven.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:00:51 by teppei            #+#    #+#             */
/*   Updated: 2021/06/17 23:38:37 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_set_ans_dfs(t_dlst *a, t_dlst *b, t_sort *t, long turn)
{
	long	cmd;

	if (turn >= t->max_turn)
		return ;
	if (b->next->value == -1 && ps_sorted(a))
		return (ps_ans_update(turn, t));
	cmd = -1;
	while (++cmd < CMD_NUM)
	{
		if (ps_skip_check(cmd, t) || turn >= t->max_turn)
			continue;
		if (ps_change_dlst(a, b, cmd, true))
			continue;
		t->pre = cmd;
		t->tmp[turn] = cmd;
		ps_set_ans_dfs(a, b, t, turn + 1);
		ps_change_dlst(a, b, cmd, false);
	}
	return ;
}

void	ps_less_seven(t_dlst *a, t_dlst *b, t_ps *ps)
{
	t_sort	t;
	int		i;

	t.max_turn = LIMIT_LESS7;
	i = -1;
	while (++i < LIMIT_LESS7)
	{
		t.tmp[i] = -1;
		t.ans[i] = -1;
	}
	t.pre = -1;
	ps_set_ans_dfs(a, b, &t, 0);
	(void)ps;
	ps_update_ans_dlst(ps, a, b, &t);
}
