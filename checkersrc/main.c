/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:05:00 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/08 16:21:20 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"
#include <limits.h>

/* Error and exit */
void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
/* Checks that string is a number and only a number */

static int	ft_isnumber(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}
/* Checks that value is not already in the list for duplicate
input */

static void	ft_checkduplicate(int value, t_node *list)
{
	while (list)
	{
		if (value == list->value)
			ft_error();
		list = list->next;
	}
}
/* Checks strlen and int limits for int overflow protection, that it 
contains a valid number representation */

static int	ft_validate_input(char *str, t_node *list)
{
	char		*temp;
	long long	result;

	temp = str;
	if (ft_strlen(str) > 11 || !ft_isnumber(str))
		ft_error();
	result = ft_atoll(str);
	if (result < INT_MIN || result > INT_MAX)
		ft_error();
	ft_checkduplicate((int)result, list);
	return ((int)result);
}

/* Reads values from input. TODO: Replace
ft_atol with input validator, add node add */

void	ft_read_values(t_utils *utils, char **argv, int argc)
{
	t_node	*current;
	int		i;

	i = 0;
	utils->head_a = ft_createnode();
	current = utils->head_a;
	utils->tail_a = current;
	utils->input_count = argc;
	while (i < argc)
	{
		current->value = ft_validate_input(argv[i], utils->head_a);
		if (i == argc - 1)
			break ;
		current = ft_create_elem_stack_a(utils);
		i++;
	}
	utils->count_a = argc;
}

void	ft_dispatcher(t_utils *utils, int func_index)
{
	static const t_func	funcs[] = {ft_swap_a, ft_swap_b, ft_swap_both, \
	ft_push_a, ft_push_b, ft_rotate_a, ft_rotate_b, ft_rotate_both, \
	ft_rev_rotate_a, ft_rev_rotate_b, ft_rev_rotate_both};

	if (func_index < 0)
		ft_error();
	funcs[func_index](utils);
}

int	ft_get_instruction(char *line)
{
	const char	*table[] = {"sa", "sb", "ss", "pa", "pb", \
	"ra", "rb", "rr", "rra", "rrb", "rrr", NULL};
	int			i;

	i = 0;
	if (!line)
		return (-1);
	while (table[i])
	{
		if (!ft_strcmp(line, table[i]))
			return (i);
		i++;
	}
	return (-1);
}

void	ft_exec_instructions(t_utils *utils, t_instructions *instr)
{
	size_t	i;

	i = 0;
	while (i < instr->count)
	{
		ft_dispatcher(utils, instr->inst_array[i]);
		ft_printlist(*utils);
		i++;
	}
	free(instr->inst_array);
}

/* Initializes the instruction array if it doesnt exist, if
index goes over memthreshold allocates new memory and copies
the memory to the new alloocation */
void	ft_save_instruction(t_instructions *instr, char *line)
{
	static size_t	i;
	static size_t	alloc_size;
	int				*temp;

	if (!instr->inst_array)
	{
		instr->inst_array = (int *)malloc(sizeof(int) * 20);
		instr->memthreshold = 20 / 2;
	}
	instr->inst_array[i] = ft_get_instruction(line);
	if (instr->inst_array[i] < 0)
		ft_error();
	i++;
	instr->count = i;
	if (i > instr->memthreshold)
	{
		temp = (int *)malloc(sizeof(int) * instr->memthreshold * 4);
		if (!temp)
			ft_error();
		ft_memcpy(temp, instr->inst_array, (i * sizeof(int)));
		free(instr->inst_array);
		instr->memthreshold *= 2;
		instr->inst_array = temp;
	}
}

void	ft_read_input(t_utils *utils)
{
	int				ret;
	char			*line;
	int				func;
	t_instructions	instr;

	ret = 1;
	instr.inst_array = NULL;
	while (ret)
	{
		ret = get_next_line(0, &line);
		if (ret < 1)
			break ;
		ft_save_instruction(&instr, line);
//		func = ft_get_instruction(line);
//		ft_dispatcher(utils, func);
		ft_strdel(&line);
//		ft_printlist(*utils);
	}
	if (ret < 0)
		ft_error();
	ft_exec_instructions(utils, &instr);
}

int	ft_is_correct(t_utils *utils)
{
	size_t	i;
	int		compare;
	t_node	*current;

	current = utils->head_a;
	i = 0;
	compare = INT_MIN;
	if (utils->count_b)
		return (0);
	while (current)
	{
		i++;
		if (compare > current->value)
			return (0);
		compare = current->value;
		current = current->next;
	}
	if (i != utils->input_count)
		return (0);
	return (1);
}

/* Frees both lists in utils. After reaching the
end of stack_a, will switch to head_b if it
exists. Uses the head_a pointer for freeing stack_b
aswell. Use only when program is finishing */

void	ft_freelists(t_utils *utils)
{
	t_node	*temp;

	temp = NULL;
	while (utils->head_a)
	{
		temp = utils->head_a->next;
		free(utils->head_a);
		utils->head_a = NULL;
		if (!temp && utils->head_b)
		{
			temp = utils->head_b;
			utils->head_b = NULL;
		}
		utils->head_a = temp;
	}
}

int	main(int argc, char **argv)
{
	t_utils	utils;

	ft_initutils(&utils);
	utils.head_b = NULL;
	if (argc < 2)
		ft_error();
	ft_read_values(&utils, argv + 1, argc - 1);
	ft_read_input(&utils);
	if (ft_is_correct(&utils))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_freelists(&utils);
	return (0);
}
