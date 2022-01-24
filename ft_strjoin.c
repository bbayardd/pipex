/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:12:00 by bbayard           #+#    #+#             */
/*   Updated: 2021/10/22 12:12:03 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sum_s;
	int		i;
	int		c;

	i = 0;
	c = 0;
	sum_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sum_s || !s1 || !s2)
		return (NULL);
	while (s1[c])
	{
		sum_s[i] = s1[c];
		i++;
		c++;
	}
	c = 0;
	while (s2[c])
	{
		sum_s[i] = s2[c];
		c++;
		i++;
	}
	sum_s[i] = '\0';
	return (sum_s);
}
