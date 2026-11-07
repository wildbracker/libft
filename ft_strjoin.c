/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalaini <amalaini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 14:18:17 by amalaini          #+#    #+#             */
/*   Updated: 2026/11/07 15:46:18 by amalaini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (s1 && s2)
		res = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	else
		return (NULL);
	i = 0;
	while (res && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (res && s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	return (res);
}
