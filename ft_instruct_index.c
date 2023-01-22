/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:29:30 by lamasson          #+#    #+#             */
/*   Updated: 2023/01/22 19:14:55 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_size_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

static int	*ft_sort_tab(int *tab, int size)
{
	int	i;
	int	cmp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			cmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = cmp;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

int	*ft_tab_char_to_int(char **tab)
{
	int	i;
	int	y;
	int	*tab_int;

	i = 0;
	y = ft_size_tab(tab);
	tab_int = malloc(sizeof(int) * y);
	while (tab[i])
	{
		tab_int[i] = ft_atoll(tab[i]);
		i++;
	}
	tab_int = ft_sort_tab(tab_int, y);
	return (tab_int);
}

int	ft_index_pos(int *tab_int, int val)
{
	int	i;

	i = 0;
	while (tab_int[i] != val)
		i++;
	return (i);
}
