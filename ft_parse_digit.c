/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:27:36 by lamasson          #+#    #+#             */
/*   Updated: 2023/01/04 16:01:14 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen_d(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i + 1);
}

static void	ft_cat_d(char *s1, char *s2, char *s3)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s1 && s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	s3[i] = ' ';
	i++;
	while (s2 && s2[y] != '\0')
	{
		s3[i] = s2[y];
		i++;
		y++;
	}
	s3[i] = '\0';
}

static char	*ft_strjoin_d(char *s1, char *s2)
{
	char	*s3;
	int		size_s3;

	size_s3 = ft_strlen_d(s1) + ft_strlen_d(s2);
	s3 = malloc(sizeof(char) * (size_s3 + 1));
	if (!s3)
		return (NULL);
	ft_cat_d(s1, s2, s3);
	if (s1)
		free(s1);
	return (s3);
}

static int	ft_check_digit(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '-' || tmp[i] == '+')
		{
			if (tmp[i + 1] == ' ' || tmp[i + 1] == '-' || tmp[i + 1] == '+')
				return (1);
			i++;
		}
		else if ((tmp[i] >= '0' && tmp[i] <= '9'))
		{
			if (tmp[i + 1] == '-' || tmp[i + 1] == '+')
				return (1);
			i++;
		}
		else if (tmp[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

char	*ft_digit(char **argv)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (argv[i++])
		tmp = ft_strjoin_d(tmp, argv[i]);
	if (ft_check_digit(tmp) == 1)
	{
		free(tmp);
		ft_error();
	}
	return (tmp);
}
