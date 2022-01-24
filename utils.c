/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:50:17 by bbayard           #+#    #+#             */
/*   Updated: 2022/01/23 17:50:19 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	only_spaces(char *s)
{
	while (*s)
	{
		if (*s != ' ')
			return (1);
		s++;
	}
	return (0);
}

int	str_start_with(char *str, char *start_str)
{
	int	i;

	i = 0;
	while (start_str[i])
	{
		if (str[i] != start_str[i])
			return (0);
		i++;
	}
	return (1);
}

char	*get_var(char *var, char **envp)
{
	while (*envp)
	{
		if (str_start_with(*envp, var))
			return (*envp + ft_strlen(var));
		envp++;
	}
	return (0);
}

void	create_pipe(int fds[2])
{
	if (pipe(fds) == -1)
		exit(3);
}
