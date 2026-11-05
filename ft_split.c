/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalaini <amalaini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:49:54 by amalaini          #+#    #+#             */
/*   Updated: 2026/11/02 14:40:04 by amalaini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wc(char const *s, char c)
{
	size_t	i;
	size_t	res;
	int		in_word;

	i = 0;
	res = 0;
	in_word = 0;
	while (s[i])
	{
		if (in_word)
		{
			if (s[i] == c)
				in_word = 0;
			i++;
			continue ;
		}
		if (s[i] != c)
		{
			in_word = 1;
			res++;
		}
		i++;
	}
	return (res);
}

static void	ffree(char **arr, size_t i)
{
	while (i)
	{
		i--;
		free(arr[i]);
	}
	free(arr[0]);
}

static char	**f(char **arr, char const *s, char c, size_t w)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (arr && i < w)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j + k] && s[j + k] != c)
			k++;
		arr[i] = ft_substr(s, j, k);
		if (!arr[i])
		{
			ffree(arr, i);
			free(arr);
			return (NULL);
		}
		i++;
		j += k + 1;
		k = 0;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	w;

	if (!s)
		return (NULL);
	w = wc(s, c);
	arr = ft_calloc(sizeof(char *), w + 1);
	return (f(arr, s, c, w));
}
