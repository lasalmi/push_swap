#include "checker.h"
#include "./libft/libft.h"

t_node	*ft_createnode(void)
{
	t_node	*ret;

	ret = (t_node *)malloc(sizeof(t_node));
	if (!ret)
		ft_putstr_fd("Error\n", 2);
	return (ret);
}
