/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:52:00 by teppei            #+#    #+#             */
/*   Updated: 2021/06/14 16:54:38 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

bool	ps_option_handler(char c, t_ps *ps)
{
	if (c == 'v')
		ps->vflag = true;
	else if (c == 'c')
		ps->cflag = true;
	else if (ft_isdigit(c))
		return (true);
	else
		exit(ps_puterror(NULL, NULL, NULL, 1));
	return (false);
}

char	**ps_get_option(long *argc, char **argv, t_ps *ps)
{
	char	**strs;
	long	i;

	ps->vflag = false;
	ps->cflag = false;
	strs = argv + 1;
	while (*strs && **strs == '-')
	{
		i = 0;
		while ((*strs)[++i])
		{
			if (ps_option_handler((*strs)[i], ps))
				return (argv);
		}
		if (i == 1)
			exit(ps_puterror(NULL, NULL, NULL, 1));
		argv++;
		strs = argv + 1;
		(*argc)--;
	}
	return (argv);
}
