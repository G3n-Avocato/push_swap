/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:29:12 by lamasson          #+#    #+#             */
/*   Updated: 2023/01/22 19:16:52 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_stack(t_stack *stack, int *tab_int)
{
	t_lst	*buf;
	int		index;

	buf = stack->a;
	while (buf->next)
	{
		index = ft_index_pos(tab_int, buf->val);
		buf->val = index;
		buf = buf->next;
	}
	index = ft_index_pos(tab_int, buf->val);
	buf->val = index;
	free(tab_int);
}

void	ft_init_stack(t_stack *stack, char **tab)
{
	int		i;
	t_lst	*new;

	i = 1;
	stack->a = ft_lstnew_d(ft_atoll(tab[0]));
	stack->b = NULL;
	while (tab[i])
	{
		new = ft_lstnew_d(ft_atoll(tab[i]));
		if (!new)
		{
			ft_lstclear_d(stack->a);
			ft_error();
		}
		ft_lstadd_back_d(&stack->a, new);
		i++;
	}
	ft_free_tab(tab);
}
