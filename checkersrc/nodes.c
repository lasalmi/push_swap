#include "checker.h"
#include "./libft/libft.h"

/* Allocates a new node and in case
of mallocfail exits */

t_node	*ft_createnode(void)
{
	t_node	*ret;

	ret = (t_node *)malloc(sizeof(t_node));
	if (!ret)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

/* Swaps the VALUES of two nodes */
void	ft_swapnode(t_node *node, t_node *node2)
{
	ft_swap(&node->value, &node2->value);
}
