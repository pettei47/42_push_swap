/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_update_ans_dlst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 23:32:26 by teppei            #+#    #+#             */
/*   Updated: 2021/06/17 23:40:19 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_update_ans_dlst(t_ps *ps, t_dlst *a, t_dlst *b, t_sort *t)
{
	int	i;

	i = -1;
	while (++i < t->max_turn)
		ps_dlst_addback(ps, ps->cmds, t->ans[i]);
	i = -1;
	while (++i < t->max_turn)
		ps_change_dlst(a, b, t->ans[i], true);
}
