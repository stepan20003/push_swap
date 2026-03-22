#include "push_swap.h"

void	funct_ra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*start;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = *a;
	start = *a;
	while (start->next)
		start = start->next;
	start->next = temp;
	*a = (*a)->next;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	funct_rb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*start;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = *b;
	start = *b;
	while (start->next)
		start = start->next;
	start->next = temp;
	*b = (*b)->next;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	funct_rr(t_stack **a, t_stack **b)
{
	funct_ra(a);
	funct_rb(b);
	write(1, "rr\n", 3);
}

void	funct_rra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*start;

	if (!a || !*a || !(*a)->next)
		return ;
	start = *a;
	while (start->next->next)
		start = start->next;
	temp = start->next;
	start->next = NULL;
	temp->next = *a;
	*a = temp;
	write(1, "rra\n", 4);
}

void	funct_rrb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*start;

	if (!b || !*b || !(*b)->next)
		return ;
	start = *b;
	while (start->next->next)
		start = start->next;
	temp = start->next;
	start->next = NULL;
	temp->next = *b;
	*b = temp;
	write(1, "rrb\n", 4);
}
