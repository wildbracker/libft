/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalaini <amalaini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 20:39:29 by amalaini          #+#    #+#             */
/*   Updated: 2026/11/04 13:07:28 by amalaini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	c;
	void	*p;

	c = nmemb * size;
	if (nmemb && size)
	{
		if (c / nmemb != size)
			return (NULL);
	}
	else
	{
		return (malloc(1));
	}
	p = malloc(c);
	if (p)
		ft_bzero(p, c);
	return (p);
}
