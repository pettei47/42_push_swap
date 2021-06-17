/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ans_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 22:28:48 by teppei            #+#    #+#             */
/*   Updated: 2021/06/17 23:35:07 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_ans_update(long turn, t_sort *t)
{
	int	i;

	t->max_turn = turn;
	i = -1;
	while (++i < turn)
		t->ans[i] = t->tmp[i];
}
