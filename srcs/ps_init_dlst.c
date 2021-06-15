/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_dlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:41:16 by teppei            #+#    #+#             */
/*   Updated: 2021/06/15 23:19:44 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlst	*ps_init_dlst(t_ps *ps)
{
	t_dlst	*dl;

	dl = (t_dlst *)malloc(sizeof(t_dlst));
	if (!dl)
		exit(ps_puterror(NULL, NULL, ps, 1));
	dl->value = -1;
	dl->next = dl;
	dl->prev = dl;
	return (dl);
}
