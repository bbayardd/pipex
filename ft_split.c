/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:10:15 by bbayard           #+#    #+#             */
/*   Updated: 2021/10/22 12:10:19 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	num_space(char const *s, char c)
{
	int	i;
	int	ns;

	i = 0;
	ns = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			ns++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (ns);
}

char	*make_word(const char *str, int first, int last)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((last - first + 1) * sizeof(char));
	while (first < last)
		word[i++] = str[first++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		l;
	int		i;
	int		idx;
	char	**arr_s;

	i = 0;
	l = 0;
	arr_s = (char **)malloc(sizeof(char *) * (num_space(s, c) + 1));
	if (!s || !arr_s)
		return (NULL);
	idx = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && idx < 0)
			idx = i;
		else if ((s[i] == c || i == ft_strlen(s)) && idx >= 0)
		{
			arr_s[l] = make_word(s, idx, i);
			idx = -1;
			l++;
		}
		i++;
	}	
	arr_s[l] = NULL;
	return (arr_s);
}
