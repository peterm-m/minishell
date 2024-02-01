#include "ft_dlst.h"

int	ft_dlstsize(t_dlst *dlst)
{
	int		i;
	t_dlst	*aux;

	aux = dlst;
	i = 0;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}