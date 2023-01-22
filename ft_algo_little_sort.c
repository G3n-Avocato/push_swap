/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_little_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:52:18 by lamasson          #+#    #+#             */
/*   Updated: 2023/01/22 18:11:20 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_lst **stack)
{
	t_lst	*buf;

	buf = *stack;
	while (buf->next)
	{
		if (buf->val > buf->next->val)
			return (1);
		buf = buf->next;
	}
	return (0);
}

void	ft_three_sort(t_stack *stack)
{
	t_lst	*buf;
	int		middle;
	int		last;

	buf = stack->a;
	middle = buf->next->val;
	last = buf->next->next->val;
	if (ft_check_sort(&stack->a) == 1)
	{
		if ((buf->val > middle && buf->val < last)
			|| (buf->val > middle && middle > last)
			|| (buf->val < middle && buf->val < last))
			swap(stack->a, 0);
		else if (buf->val > middle && middle < last)
			rotate(&stack->a, 5);
		else if (middle > last && middle > buf->val)
			reverse_rotate(&stack->a, 8);
		if (ft_check_sort(&stack->a) == 1)
			ft_three_sort(stack);
	}
}

void	ft_four_sort(t_stack *stack)
{
	int	min;
	int	top;

	min = ft_check_min(&stack->a);
	top = ft_top_dis(min, &stack->a);
	if (ft_check_sort(&stack->a) == 1)
	{
		ft_push_value(top, stack, min);
		ft_three_sort(stack);
		if (ft_check_sort(&stack->a) == 1)
			ft_four_sort(stack);
	}
	push(&stack->a, &stack->b, 3);
}

void	ft_five_sort(t_stack *stack)
{
	int	min;
	int	top;

	min = ft_check_min(&stack->a);
	top = ft_top_dis(min, &stack->a);
	if (ft_check_sort(&stack->a) == 1)
	{
		ft_push_value(top, stack, min);
		ft_four_sort(stack);
		if (ft_check_sort(&stack->a) == 1)
			ft_five_sort(stack);
	}
	push(&stack->a, &stack->b, 3);
}
