/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:33:19 by lamasson          #+#    #+#             */
/*   Updated: 2023/01/22 20:22:38 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_type_sort(t_stack *stack)
{
	int	len;

	len = ft_len_lst(&stack->a);
	if (len == 2)
		swap(stack->a, 0);
	else if (len == 3)
		ft_three_sort(stack);
	else if (len == 4)
		ft_four_sort(stack);
	else if (len == 5)
		ft_five_sort(stack);
	else
		ft_all_sort(stack);
}

static char	**ft_parse(char **argv)
{
	char	*str;
	char	**tab;

	str = ft_digit(argv);
	tab = ft_split(str, ' ');
	free(str);
	ft_min_max(tab);
	ft_comp_tab(tab);
	ft_already_sort(tab);
	return (tab);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	char	**tab;
	int		*tab_int;

	if (argc < 2)
		return (0);
	tab = ft_parse(argv);
	tab_int = ft_tab_char_to_int(tab);
	ft_init_stack(&stack, tab);
	ft_index_stack(&stack, tab_int);
	ft_type_sort(&stack);
	ft_lstclear_d(stack.a);
	ft_lstclear_d(stack.b);
	return (0);
}
