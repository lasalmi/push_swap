#include "../checker.h"

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

/* Pushes given node as the new tail node
GIVEN NODE MUST BE TAIL! */
void	ft_add_node_tail(t_node **tail, t_node *new_node)
{
	if ((*tail)->next)
	{
		ft_putstr_fd(2, "List error, given node was not tail!");
		exit (1);
	}
	new_node->next = NULL;
	new_node->prev = *tail;
	(*tail)->next = new_node;
	*tail = new_node;
}

/* Pushes given node as the new head node
GIVEN NODE MUST BE HEAD! */
void	ft_add_node_head(t_node **head, t_node *new_node)
{
	if ((*head)->prev)
	{
		ft_putstr_fd(2, "List error, given node was not head!");
		exit (1);
	}
	new_node->prev = NULL;
	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;
}
