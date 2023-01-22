/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct_lst_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:48:27 by lamasson          #+#    #+#             */
/*   Updated: 2023/01/04 16:49:30 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lstnew_d(int val)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst) * 1);
	if (!new)
		return (NULL);
	new->val = val;
	new->next = NULL;
	new->back = NULL;
	return (new);
}

void	ft_lstadd_back_d(t_lst **stack, t_lst *new)
{
	t_lst	*last;

	if (!stack)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		last = *stack;
		while (last && last->next)
			last = last->next;
		last->next = new;
		new->back = last;
	}
}

void	ft_lstclear_d(t_lst *lst)
{
	t_lst	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}
