/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_sort_and_doublon.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:19:28 by lamasson          #+#    #+#             */
/*   Updated: 2023/01/04 16:25:42 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_int_sort(char *s1, char *s2)
{
	long long	c1;
	long long	c2;

	c1 = ft_atoll(s1);
	c2 = ft_atoll(s2);
	if (c1 > c2)
		return (0);
	else if (c1 < c2)
		return (1);
	return (-1);
}

int	ft_already_sort(char **tab)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (tab[y])
	{
		if (ft_check_int_sort(tab[i], tab[y]) == 0)
			return (0);
		else
		{
			i++;
			y++;
		}
	}
	ft_free_tab(tab);
	exit (1);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_comp_tab(char **tab)
{
	int	i;
	int	y;

	i = 0;
	while (tab[i + 1] != NULL)
	{
		y = i + 1;
		while (tab[y] != NULL)
		{
			if (ft_strcmp(tab[i], tab[y]) == 0)
			{
				ft_free_tab(tab);
				ft_error();
			}
			y++;
		}
		i++;
	}
}
