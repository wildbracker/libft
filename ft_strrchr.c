/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalaini <amalaini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 08:42:57 by amalaini          #+#    #+#             */
/*   Updated: 2026/10/23 12:14:24 by amalaini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	c0;

	c0 = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == c0)
			return ((char *)s + i);
		i--;
	}
	if (s[0] == c0)
		return ((char *)s);
	return (NULL);
}
