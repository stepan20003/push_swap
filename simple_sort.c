#include "push_swap.h"

static int	find_min_pos(t_stack *a)
{
	t_stack	*tmp;
	int		pos;
	int		min_pos;
	int		min_val;

	tmp = a;
	pos = 0;
	min_pos = 0;
	min_val = a->value;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}

static void	bring_to_top(t_stack **a, int pos, int size)
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

void	simple_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	pos;

	while (*a)
	{
		size = stack_size(*a);
		pos = find_min_pos(*a);
		bring_to_top(a, pos, size);
		funct_pb(a, b);
	}
	while (*b)
		funct_pa(a, b);
}