/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_little_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:09:13 by lamasson          #+#    #+#             */
/*   Updated: 2023/01/22 20:27:34 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len_lst(t_lst **stack)
{
	int		len;
	t_lst	*tmp;

	len = 0;
	tmp = *stack;
	while (tmp)
	{
			len++;
			tmp = tmp->next;
	}
	return (len);
}

int	ft_check_min(t_lst **stack)
{
	int		min_value;
	t_lst	*buf;

	buf = *stack;
	min_value = 2147483647;
	while (buf)
	{
		if (buf->val < min_value)
			min_value = buf->val;
		buf = buf->next;
	}
	return (min_value);
}

int	ft_top_dis(int value, t_lst **stack)
{
	int		top_dis;
	t_lst	*buf;

	buf = *stack;
	top_dis = 0;
	while (buf)
	{
		if (buf->val == value)
			return (top_dis);
		buf = buf->next;
		top_dis++;
	}
	return (-1);
}

void	ft_push_value(int top_dis, t_stack *stack, int value)
{
	t_lst	*buf;
	int		middle_len;

	buf = stack->a;
	middle_len = ft_len_lst(&stack->a) / 2;
	while (buf->val != value)
	{
		if (top_dis > middle_len)
			reverse_rotate(&stack->a, 8);
		else if (top_dis <= middle_len)
			rotate(&stack->a, 5);
		buf = stack->a;
	}
	push(&stack->b, &stack->a, 4);
}
