#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		funct_sa(a);
	else if (first > second && second > third)
	{
		funct_sa(a);
		funct_rra(a);
	}
	else if (first > second && second < third && first > third)
		funct_ra(a);
	else if (first < second && second > third && first < third)
	{
		funct_sa(a);
		funct_ra(a);
	}
	else if (first < second && second > third && first > third)
		funct_rra(a);
}
