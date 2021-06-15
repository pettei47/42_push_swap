/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:36:49 by teppei            #+#    #+#             */
/*   Updated: 2021/06/15 22:37:15 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ps_puterror(t_dlst *a, t_dlst *b, t_ps *ps, int ret)
{
	ps_free_ps(a, b, ps);
	ft_putstr_fd("Error\n", 2);
	return (ret);
}
