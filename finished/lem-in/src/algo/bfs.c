/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:25:41 by dabeloos          #+#    #+#             */
/*   Updated: 2019/11/29 10:25:43 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			bfs_recursive(t_room *current, int weight)
{
	unsigned int	top;
	unsigned int	d;
	t_tube			*t;

	if (!current)
		return ;
	if (current == g_lemin->end)
		return (update_path(weight));
	if (current->visited == 1 ||
		(current->isset && current->weight <= weight))
		return ;
	current->weight = weight;
	current->isset = 1;
	current->visited = TRUE;
	path_append(g_lemin->working_path, current);
	top = current->a_tubes.array.n_items;
	d = 0;
	while (d < top)
	{
		t = *(t_tube**)ft_array_get((t_array*)&current->a_tubes, d);
		bfs_recursive(tube_navigate(t, current), weight + t->cost);
		d++;
	}
	path_remove_last(g_lemin->working_path);
	current->visited = FALSE;
}

void				bfs(void)
{
	bfs_recursive(g_lemin->start, 0);
	if (!(g_lemin->best_path))
		lemin_error(LEMIN_ERR_INSUFFICIENT_DATA);
}
