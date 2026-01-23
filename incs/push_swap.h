/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:22:45 by eseragio          #+#    #+#             */
/*   Updated: 2026/01/21 14:18:52 by eseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "../libs/printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PA "pa\n"
# define PB "pb\n"
# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*xor;
}			t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_a;
	int		size_b;
}			t_data;

// numCheck
int			ft_valid_num(char *str);

// make_stack
t_stack		*ft_stack_new(int value);
t_stack		*ft_stack_last(t_stack *curr);
int			ft_stack_addback(t_stack **head, t_stack *new);
int			ft_is_duplicated(t_stack *head, long value);
int			ft_add_to_stack(t_stack **stack_a, char *str);
t_data		*ft_make_stack(int argc, char **argv);
bool		ft_make_stack_utl(t_data *data, char *argv);

// stacl utius
int			ft_stack_len(t_stack *head);
t_stack		*ft_stack_max(t_stack *head);

// atol
long		ft_atol(const char *str);

// xor
t_stack		*ft_xor(t_stack *a, t_stack *b);

// operations
void		ft_index(t_stack *stack);
t_stack		*ft_index_min(t_stack *curr);
t_stack		*ft_get_index_min(t_stack *curr);
void		ft_push_min_whiles(t_data *data, int *cost_a, int *cost_b);
void		ft_push_min_whiles_both(t_data *data, int *cost_a, int *cost_b);
int			ft_find_node(t_stack *head, t_stack *node);
void		ft_push(t_stack **src, t_stack **dest, char *str);
t_stack		*ft_rmv_head(t_stack **stack);
void		ft_swap(t_stack **head, char *str);
void		ft_swap_both(t_data *data);
void		ft_rotate(t_stack **head, char *str);
void		ft_reverse_rotate(t_stack **head, char *str);
void		ft_rotate_both(t_data *data);
void		ft_reverse_rotate_both(t_data *data);

// free
void		ft_free_split(char **array);
void		ft_free_stack(t_stack *curr);
void		ft_free_data(t_data *data);

void		ft_print_stack(t_stack *head);
bool		ft_sorted(t_data *data);
void		ft_sort(t_data *data);
void		ft_sort_3(t_data *data);
void		ft_sort_4(t_data *data);
void		ft_sort_5(t_data *data);
void		ft_sort_all(t_data *data);

int			ft_abso(int cost);

int			ft_total_cost(t_stack *stack_a, t_stack *stack_b, t_stack *node);
void		ft_push_min(t_data *data, t_stack *node);
t_stack		*ft_next_in_b(t_stack *head, t_stack *node);
int			ft_rotate_cost(t_stack *head, t_stack *node);

// bonus
bool		ft_sort_empty(t_stack **stack_a, t_stack **stack_b);
int			check_instruct(t_stack **stack_a, t_stack **stack_b, char *line);
void		checker(t_stack **stack_a, t_stack **stack_b);
int			check_all(t_stack **stack_a, t_stack **stack_b, char *line);

// gnl
char		*get_next_line(int fd);
int			ft_len_gnl(const char *str);
char		*ft_strchr_gnl(const char *s, int c);
char		*ft_strdup_gnl(const char *s);
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*ft_substr_gnl(char const *s, unsigned int start, size_t len);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
