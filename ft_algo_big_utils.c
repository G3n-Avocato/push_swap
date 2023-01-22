/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_big_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:47:37 by lamasson          #+#    #+#             */
/*   Updated: 2023/01/22 19:23:38 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_top_range(int pivot, t_stack *stack)
{
	int		top;
	t_lst	*buf;

	buf = stack->a;
	top = 0;
	while (buf)
	{
		if (buf->val <= pivot)
			return (top);
		buf = buf->next;
		top++;
	}
	return (-1);
}

int	ft_bottom_range(int pivot, t_stack *stack)
{
	int		bot;
	t_lst	*buf;

	buf = stack->a;
	bot = 0;
	while (buf && buf->next)
		buf = buf->next;
	while (buf && buf->back)
	{
		if (buf->val <= pivot)
			return (bot);
		buf = buf->back;
		bot++;
	}
	return (-1);
}

void	ft_sort_b(t_stack *stack, int pivot, int cut)
{
	t_lst	*buf;
	int		start;
	int		mid;

	buf = stack->b;
	start = pivot - cut;
	mid = (start + pivot) / 2;
	if (buf->next && buf->val <= mid)
		rotate(&stack->b, 6);
	else
		return ;
}

int	ft_cut_size(int len)
{
	int	cut;

	if (len < 300)
		cut = (len * len * 0.000000053) + (0.03 * len) + 14.5;
	else
		cut = len / 8;
	return (cut);
}
