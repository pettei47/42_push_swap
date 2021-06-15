/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dlst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:39:59 by teppei            #+#    #+#             */
/*   Updated: 2021/06/15 22:40:30 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_dlst_clear(t_dlst *a)
{
	t_dlst	*tmp;

	a->prev->next = NULL;
	while (a)
	{
		tmp = a->next;
		a->prev = NULL;
		free(a);
		a = tmp;
	}
}
