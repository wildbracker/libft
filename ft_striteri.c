/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalaini <amalaini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 13:24:31 by amalaini          #+#    #+#             */
/*   Updated: 2026/11/07 15:44:27 by amalaini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	n;

	if (s && f)
		n = ft_strlen(s);
	else
		return ;
	i = 0;
	while (i < n)
	{
		f(i, &s[i]);
		i++;
	}
}
