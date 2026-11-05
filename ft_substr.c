/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalaini <amalaini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:04:04 by amalaini          #+#    #+#             */
/*   Updated: 2026/11/03 15:53:13 by amalaini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	str = ft_calloc(sizeof(char), min(len, ft_strlen(s) - start) + 1);
	if (str)
		ft_memcpy(str, &s[start], min(len, ft_strlen(s) - start));
	return (str);
}
