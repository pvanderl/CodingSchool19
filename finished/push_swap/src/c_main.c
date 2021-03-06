/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:27:53 by pvanderl          #+#    #+#             */
/*   Updated: 2019/07/11 14:19:33 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_s_c.h"

/*
**	function main
**
**	starting function for the checker program
*/

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		av = ft_strsplit(av[1], ' ');
		ac = tablen(av);
		start(ac, av, 1);
		tabfree(av);
	}
	else if (ac > 2)
		start(ac - 1, av + 1, 1);
	return (0);
}
