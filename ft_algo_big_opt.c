/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_big_opt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:54:22 by lamasson          #+#    #+#             */
/*   Updated: 2023/01/22 19:13:05 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_top_max(int pivot, t_stack *stack)
{
	int		top;
	t_lst	*buf;

	buf = stack->b;
	top = 0;
	while (buf)
	{
		if (buf->val >= pivot)
			return (top);
		buf = buf->next;
		top++;
	}
	return (-1);
}

int	ft_bottom_max(int pivot, t_stack *stack)
{
	int		bot;
	t_lst	*buf;

	buf = stack->b;
	bot = 0;
	while (buf && buf->next)
		buf = buf->next;
	while (buf && buf->back)
	{
		if (buf->val >= pivot)
			return (bot);
		buf = buf->back;
		bot++;
	}
	return (-1);
}

void	ft_swap_a_max(t_stack *stack)
{
	t_lst	*buf;

	buf = stack->a;
	if (buf->next && buf->val > buf->next->val)
		swap(stack->a, 0);
}
