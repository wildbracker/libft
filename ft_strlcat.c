/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalaini <amalaini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:49:29 by amalaini          #+#    #+#             */
/*   Updated: 2026/10/23 12:15:41 by amalaini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	i;

	d = 0;
	while (d < size && dst[d])
		d++;
	s = ft_strlen(src);
	if (d == size)
		return (size + s);
	i = d;
	while (i < size - 1 && src[i - d])
	{
		dst[i] = src[i - d];
		i++;
	}
	dst[i] = 0;
	return (d + s);
}
