#include "ft_ls.h"

t_global	*generate_global(void)
{
	t_global *g;

	if (!(g = (t_global *)malloc(sizeof(t_global))) ||
		!(g->options = (char *)malloc(sizeof(char) * 27))
		print(destroy_global(g));
}
