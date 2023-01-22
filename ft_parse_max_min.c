/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_max_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:05:39 by lamasson          #+#    #+#             */
/*   Updated: 2023/01/04 16:13:39 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *str)
{
	long long	neg;
	long long	nb;

	nb = 0;
	neg = 1;
	while (*str == 32 || (*str >= 8 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += *str - 48;
		if (nb * neg > 2147483647 || nb * neg < -2147483648)
			return (2147483650);
		str++;
	}
	return (nb * neg);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit (1);
}

void	ft_min_max(char **tab)
{
	int			i;
	long long	cmp;

	i = 0;
	while (tab[i] != NULL)
	{
		cmp = ft_atoll(tab[i]);
		if (cmp == 2147483650)
		{
			ft_free_tab(tab);
			ft_error();
		}
		i++;
	}
}
