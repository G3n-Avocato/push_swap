/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct_rule.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:01:08 by lamasson          #+#    #+#             */
/*   Updated: 2023/01/17 01:28:27 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst *lst, int nb)
{	
	int	tmp;

	tmp = lst->val;
	lst->val = lst->next->val;
	lst->next->val = tmp;
	if (nb >= 0)
		ft_print_move(nb);
}

int	push(t_lst **lst_dst, t_lst **lst_src, int nb)
{
	t_lst	*dst;
	t_lst	*src;
	t_lst	*tmp;

	dst = *lst_dst;
	src = *lst_src;
	if (!src)
		return (0);
	tmp = src;
	src = src->next;
	*lst_src = src;
	tmp->next = dst;
	tmp->back = NULL;
	if (tmp->next)
		tmp->next->back = tmp;
	*lst_dst = tmp;
	if (nb >= 0)
		ft_print_move(nb);
	return (0);
}

void	rotate(t_lst **lst, int nb)
{
	t_lst	*first;
	t_lst	*second;
	t_lst	*buf;

	buf = *lst;
	first = buf;
	buf = buf->next;
	second = buf;
	*lst = buf;
	while (second->next)
		second = second->next;
	second->next = first;
	first->back = second;
	first->next = NULL;
	if (nb >= 0)
		ft_print_move(nb);
}

void	reverse_rotate(t_lst **lst, int nb)
{
	t_lst	*buf;
	t_lst	*second;
	t_lst	*first;
	t_lst	*pre;

	buf = *lst;
	second = buf;
	while (buf->next)
	{
		pre = buf;
		buf = buf->next;
	}
	pre->next = NULL;
	first = buf;
	second->back = first;
	first->next = second;
	first->back = NULL;
	*lst = first;
	if (nb >= 0)
		ft_print_move(nb);
}

void	ft_print_move(int nb)
{
	if (nb == 0)
		ft_putendl_fd("sa", 1);
	else if (nb == 1)
		ft_putendl_fd("sb", 1);
	else if (nb == 2)
		ft_putendl_fd("ss", 1);
	else if (nb == 3)
		ft_putendl_fd("pa", 1);
	else if (nb == 4)
		ft_putendl_fd("pb", 1);
	else if (nb == 5)
		ft_putendl_fd("ra", 1);
	else if (nb == 6)
		ft_putendl_fd("rb", 1);
	else if (nb == 7)
		ft_putendl_fd("rr", 1);
	else if (nb == 8)
		ft_putendl_fd("rra", 1);
	else if (nb == 9)
		ft_putendl_fd("rrb", 1);
	else if (nb == 10)
		ft_putendl_fd("rrr", 1);
}
