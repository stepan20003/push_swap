#include "push_swap.h"

static void	rotate_to_top(t_stack **a, int pos, int size)
{
	if (pos <= size / 2)
		while (pos-- > 0)
			funct_ra(a);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			funct_rra(a);
	}
}

static void	push_max_to_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		max_val;
	int		pos;
	int		size;

	tmp = *b;
	max_val = tmp->value;
	while (tmp)
	{
		if (tmp->value > max_val)
			max_val = tmp->value;
		tmp = tmp->next;
	}
	pos = 0;
	tmp = *b;
	while (tmp->value != max_val)
	{
		pos++;
		tmp = tmp->next;
	}
	size = stack_size(*b);
	if (pos <= size / 2)
		while (pos-- > 0)
			funct_rb(b);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			funct_rrb(b);
	}
	funct_pa(a, b);
}

static int	find_chunk_pos(t_stack *a, int min, int max)
{
	t_stack	*tmp;
	int		pos;

	tmp = a;
	pos = 0;
	while (tmp)
	{
		if (tmp->value >= min && tmp->value <= max)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (-1);
}

static void	push_chunk(t_stack **a, t_stack **b, int min, int max)
{
	int	pos;
	int	size;

	pos = find_chunk_pos(*a, min, max);
	while (pos != -1)
	{
		size = stack_size(*a);
		rotate_to_top(a, pos, size);
		funct_pb(a, b);
		pos = find_chunk_pos(*a, min, max);
	}
}

void	medium_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk_size;
	int	chunks;
	int	i;

	size = stack_size(*a);
	chunks = ft_sqrt(size);
	if (chunks < 1)
		chunks = 1;
	chunk_size = size / chunks;
	i = 0;
	while (i < chunks)
	{
		push_chunk(a, b, i * chunk_size, (i + 1) * chunk_size - 1);
		i++;
	}
	push_chunk(a, b, i * chunk_size, size - 1);
	while (*b)
		push_max_to_a(a, b);
}