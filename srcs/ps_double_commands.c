/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_double_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 23:09:32 by teppei            #+#    #+#             */
/*   Updated: 2021/06/17 23:14:52 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

bool	ps_rr(t_dlst *a, t_dlst *b)
{
	return (b->next->next->value == -1 || ps_rotate(a) || ps_rotate(b));
}

bool	ps_rrr(t_dlst *a, t_dlst *b)
{
	return (b->next->next->value == -1 \
	|| ps_reverse_rotate(a) || ps_reverse_rotate(b));
}

bool	ps_ss(t_dlst *a, t_dlst *b)
{
	return (b->next->next->value == -1 || ps_swap(a) || ps_swap(b));
}
