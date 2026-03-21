#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# define SIMPLE		0
# define MEDIUM		1
# define COMPLEX	2
# define ADAPTIVE	3

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	int		strategy;
	int		bench;
	double	disorder;
}	t_data;

int		get_strategy(char *flag);
void	parse_input(int count, char **argv, t_stack **a);
int		is_sorted(t_stack *a);
int		is_duplicate(t_stack *a, int val);
int		is_number(char *str);
int		stack_size(t_stack *a);
void	free_stack(t_stack *a);
void	free_arr(char **arr, int j);
void	ft_error(void);
void	free_and_error(char **arr, int j);
int		ft_sqrt(int n);
double	compute_disorder(t_stack *a);
void	print_bench(double disorder, int strategy);
void	adaptive_sort(t_data *data);
void	simple_sort(t_stack **a, t_stack **b);
void	medium_sort(t_stack **a, t_stack **b);
void	complex_sort(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	funct_sa(t_stack **a);
void	funct_sb(t_stack **b);
void	funct_ss(t_stack **a, t_stack **b);
void	funct_pa(t_stack **a, t_stack **b);
void	funct_pb(t_stack **a, t_stack **b);
void	funct_ra(t_stack **a);
void	funct_rb(t_stack **b);
void	funct_rr(t_stack **a, t_stack **b);
void	funct_rra(t_stack **a);
void	funct_rrb(t_stack **b);
void	funct_rrr(t_stack **a, t_stack **b);
void	stack_add_back(t_stack **a, t_stack *new);
long	ft_atol(char *str);
int		ft_putstr(char *s);
int		ft_putchar(char c);
void 	ft_putnbr(int n);
void 	print_disorder(double disorder);
t_stack	*stack_new(int value);
#endif