/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalaini <amalaini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 14:40:50 by amalaini          #+#    #+#             */
/*   Updated: 2026/11/02 15:42:13 by amalaini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	size_t	start;
	size_t	end;

	if (s || set)
	{
		if (!s)
			return (ft_strdup(""));
		if (!set)
			return (ft_strdup(s));
	}
	else
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (s[start] && ft_strchr(set, s[start]))
		start++;
	while (end > start && ft_strchr(set, s[end - 1]))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	return (ft_substr(s, start, end - start));
}
