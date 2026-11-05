/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalaini <amalaini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 11:30:09 by amalaini          #+#    #+#             */
/*   Updated: 2026/11/02 14:34:48 by amalaini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt(int i)
{
	int		j;
	long	tmp;

	j = 0;
	tmp = i;
	if (0 > tmp)
	{
		j++;
		tmp = -tmp;
	}
	while (tmp)
	{
		j++;
		tmp /= 10;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	char	*res;
	char	*p;
	long	tmp;

	if (!n)
		return (ft_strdup("0"));
	res = ft_calloc(sizeof(char), cnt(n) + 1);
	if (!res)
		return (NULL);
	tmp = n;
	if (res && tmp <= 0)
	{
		tmp = -tmp;
		res[0] = '-';
	}
	p = &res[cnt(n) - 1];
	while (res && tmp)
	{
		*p = tmp % 10 + '0';
		p--;
		tmp /= 10;
	}
	return (res);
}
