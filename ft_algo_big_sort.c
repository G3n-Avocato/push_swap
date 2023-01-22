/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_big_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:09:38 by lamasson          #+#    #+#             */
/*   Updated: 2023/01/22 19:54:08 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_a_last(t_stack *stack, int pivot, int top, int bot)
{
	t_lst	*buf;

	buf = stack->a;
	if (top > bot)
	{
		while (buf->val > pivot)
		{
			reverse_rotate(&stack->a, 8);
			buf = stack->a;
		}
	}
	else if (top <= bot)
	{
		while (buf->val > pivot)
		{
			rotate(&stack->a, 5);
			buf = stack->a;
		}
	}
	push(&stack->b, &stack->a, 4);
}

static void	ft_push_a_value(t_stack *stack, int cut)
{
	int	len_b;
	int	top;
	int	bot;
	int	pivot;

	len_b = ft_len_lst(&stack->b);
	pivot = cut;
	while (ft_len_lst(&stack->a) != 0)
	{
		while (len_b <= pivot && ft_len_lst(&stack->a) != 0)
		{
			top = ft_top_range(pivot, stack);
			bot = ft_bottom_range(pivot, stack);
			ft_push_a_last(stack, pivot, top, bot);
			ft_sort_b(stack, pivot, cut);
			len_b = ft_len_lst(&stack->b);
		}
		pivot = pivot + cut;
	}
}

static void	ft_push_b_max(t_stack *stack, int max, int top, int bot)
{
	t_lst	*buf;

	buf = stack->b;
	if (top > bot)
	{
		while (buf->val < max)
		{
			reverse_rotate(&stack->b, 9);
			buf = stack->b;
		}
	}
	else if (top <= bot)
	{
		while (buf->val < max)
		{
			rotate(&stack->b, 6);
			buf = stack->b;
		}
	}
	push(&stack->a, &stack->b, 3);
}

static void	ft_push_b(t_stack *stack)
{
	int	max;
	int	top;
	int	bot;
	int	i;

	i = 0;
	max = ft_len_lst(&stack->b) - 1;
	while (max + 1 != 0)
	{
		while (i != 2)
		{	
			top = ft_top_max(max - 1, stack);
			bot = ft_bottom_max(max - 1, stack);
			ft_push_b_max(stack, max - 1, top, bot);
			ft_swap_a_max(stack);
			i++;
		}
		i = 0;
		max = max - 2;
	}
}

void	ft_all_sort(t_stack *stack)
{
	int	cut;
	int	len;

	len = ft_len_lst(&stack->a);
	cut = ft_cut_size(len);
	ft_push_a_value(stack, cut);
	ft_push_b(stack);
}
