/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalaini <amalaini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 08:44:45 by amalaini          #+#    #+#             */
/*   Updated: 2026/11/02 15:53:58 by amalaini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c0;

	c0 = (char)c;
	i = 0;
	while (1)
	{
		if (s[i] == c0)
			return ((char *)s + i);
		if (s[i] == 0)
			break ;
		i++;
	}
	return (NULL);
}
