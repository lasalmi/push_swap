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

/* Swaps the places of two nodes */

void	ft_swapnode(t_node *node, t_node *node2)
{
	t_node	*temp;
	t_node	*temp2;

	if (node->prev)
		node->prev->next = node2;
	if (node->next)
		node->next->prev = node2;
	temp = node2->next;
	temp2 = node2->prev;
	node2->next = node->next;
	node2->prev = node->prev;
	if(temp)
		temp->prev = node;
	if(temp2)
		temp2->next = node;
	node->next = temp;
	node->prev = temp2;
}
