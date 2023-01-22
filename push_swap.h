/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:02:40 by lamasson          #+#    #+#             */
/*   Updated: 2023/01/22 20:26:57 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_lst{
	int				index;
	int				val;
	struct s_lst	*next;
	struct s_lst	*back;
}t_lst;

typedef struct s_stack{
	t_lst	*a;
	t_lst	*b;
}t_stack;

char		*ft_digit(char **argv);
void		ft_min_max(char **tab);
void		ft_error(void);
void		ft_free_tab(char **tab);
long long	ft_atoll(const char *str);
void		ft_comp_tab(char **tab);
int			ft_already_sort(char **tab);

void		ft_index_stack(t_stack *stack, int *tab_int);
void		ft_init_stack(t_stack *stack, char **tab);

void		swap(t_lst *lst, int nb);
int			push(t_lst **lst_dst, t_lst **lst_src, int nb);
void		rotate(t_lst **lst, int nb);
void		reverse_rotate(t_lst **lst, int nb);
void		ft_print_move(int nb);

t_lst		*ft_lstnew_d(int val);
void		ft_lstadd_back_d(t_lst **stack, t_lst *new);
void		ft_lstclear_d(t_lst *lst);

int			ft_check_sort(t_lst **stack);
void		ft_three_sort(t_stack *stack);
void		ft_four_sort(t_stack *stack);
void		ft_five_sort(t_stack *stack);

int			ft_check_min(t_lst **stack);
void		ft_push_value(int top_dis, t_stack *stack, int value);
int			ft_len_lst(t_lst **stack);
int			ft_top_dis(int value, t_lst **stack);

int			*ft_tab_char_to_int(char **tab);
int			ft_index_pos(int *tab_int, int val);

void		ft_all_sort(t_stack *stack);

int			ft_top_range(int pivot, t_stack *stack);
int			ft_bottom_range(int pivot, t_stack *stack);
void		ft_sort_b(t_stack *stack, int pivot, int cut);
int			ft_cut_size(int len);

int			ft_top_max(int pivot, t_stack *stack);
int			ft_bottom_max(int pivot, t_stack *stack);
void		ft_swap_a_max(t_stack *stack);

#endif
