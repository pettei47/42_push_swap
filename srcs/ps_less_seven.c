/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_less_seven.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:00:51 by teppei            #+#    #+#             */
/*   Updated: 2021/06/16 00:08:17 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_dfs(t_dlst *a, t_dlst *b, t_sort *t, long turn)
{
	(void)a;
	(void)b;
	(void)t;
	(void)turn;
	return ;
}

void	ps_less_seven(t_dlst *a, t_dlst *b, t_ps *ps)
{
	t_sort	t;
	long	i;

	t.max_turn = LIMIT_LESS7;
	i = -1;
	while (++i < LIMIT_LESS7)
	{
		t.tmp[i] = -1;
		t.ans[i] = -1;
	}
	t.pre = -1;
	ps_dfs(a, b, &t, 0);
	(void)ps;
	//ps_ansjoin(ps, &t);
	//ps_dlst_update_ans(a, b, &t);
}
